// Fill out your copyright notice in the Description page of Project Settings.

#include "CGoblin.h"

#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

#include "CConsoleLog.h"

#include "DrawDebugHelpers.h" // 디버그에 출력할 도형 모양 다 들어가있음
#include "Animation/AnimMontage.h"

// Sets default values
ACGoblin::ACGoblin()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	State = GoblinState::Idle;
	Hp = 100;
	Distance = 200;
	AttackDistance = 130;
	bDeath = false;

	//오브젝트 파인더는 생성자에서만 사용가능
	static ConstructorHelpers::FObjectFinder<UMaterial> bodyMaterial
	(
		TEXT("/Game/Goblin/GoblinMaterial")
	);
	BodyMaterial = bodyMaterial.Object;

	///////////////////////////////////////////////////////////////////////////

	static ConstructorHelpers::FObjectFinder<UAnimMontage> deathMontage
	(
		TEXT("/Game/Montages/BpMonGoblinDeath")
	);
	DeathMontage = deathMontage.Object;
}

// Called when the game starts or when spawned
void ACGoblin::BeginPlay()
{
	Super::BeginPlay();

	//Instance생성은 생성자에서 하면 안되고 여기서 해야함.
	RedBodyMaterial = UMaterialInstanceDynamic::Create(BodyMaterial, this);
	GetMesh()->SetMaterial(0, RedBodyMaterial);

	TSet<UActorComponent *> components = this->GetComponents();
	for (UActorComponent* component : components)
	{
		//UE_LOG(LogTemp, Warning, TEXT("%s"), *component->GetFName().ToString());
		//Print(*component->GetFName().ToString(), 30);
		if (component->GetFName() == "CollisionCylinder")
			MainCapsule = Cast<UCapsuleComponent>(component);
	}
}

// Called every frame
void ACGoblin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(bDeath == true)
		return;

	GetPlayerDistanceAndDirection();
	switch (State)
	{
	case GoblinState::Idle: Idling(); break;
	case GoblinState::Follow: Following();  break;
	case GoblinState::Attack: break;
	case GoblinState::Death: Dying(); break;
	}


	FVector Location = this->GetActorLocation();

	// 점임 크게 해서 사각형처럼 보이는거
	//DrawDebugPoint(GetWorld(), Location, 100, FColor::Red, true); 
	//DrawDebugSphere(GetWorld(), Location, Distance, 100, FColor(255, 0, 0), -1, true, 0, 2);

	//DrawDebugSphere(GetWorld(), Location, Distance, 5, FColor(255, 0, 0), 0.1f, true);
}

// Called to bind functionality to input
void ACGoblin::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACGoblin::GetPlayerDistanceAndDirection()
{
	ACharacter* player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	FVector playerLocation = player->GetActorLocation();
	FVector location = this->GetActorLocation();

	// 우리가 바라볼 방향 뒤로 해서 빼주면 됨
	FVector subtract = playerLocation - location; // 플레이어를 바라보는 방향 벡터
	subtract.ToDirectionAndLength(DirectionToPlayer, DistanceToPlayer);
	DirectionToPlayer.Normalize();


	FVector xy;
	xy.X = DirectionToPlayer.X;
	xy.Y = DirectionToPlayer.Y;
	xy.Z = 0.0f; // 높이라서 빼버리는거 점프할 때 누워버림

	FRotator rotator = xy.Rotation();
	SetActorRotation(rotator);
}

void ACGoblin::Idling()
{
	if (DistanceToPlayer <= Distance)
		State = GoblinState::Follow;
}

void ACGoblin::Following()
{
	if (DistanceToPlayer <= AttackDistance)
		State = GoblinState::Attack;
	else if (DistanceToPlayer <= Distance)
		AddMovementInput(DirectionToPlayer);
	else
		State = GoblinState::Idle;
}

//void ACGoblin::Attacking()
//{
//
//}

void ACGoblin::Dying()
{
	if (bDeath == true)
		return;

	bDeath = true;
	
	// 죽었을 때 충돌 컬라이더 해제.
	MainCapsule->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// 해당 몽타쥬의 종료시간이 리턴됨.
	float playTime = PlayAnimMontage(DeathMontage, 1.0f);

	FTimerHandle handle;
	GetWorldTimerManager().SetTimer(handle, this, &ACGoblin::DyingComplete, playTime + 3.0f, false);
}

void ACGoblin::DyingComplete()
{
	//StopAnimMontage(DeathMontage);
	Destroy();
}

void ACGoblin::Damaged(float damage)
{
	Hp -= damage;
	PrintFormat("%f", Hp);

	RedBodyMaterial->SetVectorParameterValue("Color", FLinearColor(1, 0, 0, 1));

	FTimerHandle handle;
	GetWorldTimerManager().SetTimer(handle, this, &ACGoblin::DamagedComplete, 0.2f, false);
}

void ACGoblin::DamagedComplete()
{
	RedBodyMaterial->SetVectorParameterValue("Color", FLinearColor(1, 1, 1, 1));

	if (Hp <= 0.0f)
		State = GoblinState::Death;
}

void ACGoblin::OnEndAttack()
{

}