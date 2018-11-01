// Fill out your copyright notice in the Description page of Project Settings.

#include "CGoblin.h"

#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

#include "CConsoleLog.h"

#include "DrawDebugHelpers.h" // ����׿� ����� ���� ��� �� ������
#include "Animation/AnimMontage.h"

#include "CPlayer.h"

// Sets default values
ACGoblin::ACGoblin()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	State = GoblinState::Idle;
	Hp = 100;
	Distance = 200;
	AttackDistance = 150;
	ReAttackDistance = 180;
	bDeath = false;
	Attack = 10;
	AttackDelay = 2.0f;

	//������Ʈ ���δ��� �����ڿ����� ��밡��
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


	static ConstructorHelpers::FObjectFinder<UAnimMontage> attack
	{
		TEXT("/Game/Montages/BpMonGoblinAttack")
	};
	AttackMontage = attack.Object;


	static ConstructorHelpers::FObjectFinder<UAnimMontage> damage
	{
		TEXT("/Game/Montages/BpMonGoblinHit")
	};
	DamageMontage = damage.Object;
}

// Called when the game starts or when spawned
void ACGoblin::BeginPlay()
{
	Super::BeginPlay();

	//Instance������ �����ڿ��� �ϸ� �ȵǰ� ���⼭ �ؾ���.
	RedBodyMaterial = UMaterialInstanceDynamic::Create(BodyMaterial, this);
	GetMesh()->SetMaterial(0, RedBodyMaterial);

	TSet<UActorComponent *> components = this->GetComponents();
	for (UActorComponent* component : components)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *component->GetFName().ToString());
		//Print(*component->GetFName().ToString(), 30);
		if (component->GetFName() == "CollisionCylinder")
			MainCapsule = Cast<UCapsuleComponent>(component);

		if (component->GetFName() == "Capsule")
			WeaponCapsule = Cast<UCapsuleComponent>(component);
	}

	WeaponCapsule->OnComponentBeginOverlap.AddDynamic(this, &ACGoblin::OnBeginOverlap);
	WeaponCapsule->SetCollisionEnabled(ECollisionEnabled::NoCollision);
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
	case GoblinState::Attack: Attacking(); break;
	case GoblinState::Death: Dying(); break;
	}


	FVector Location = this->GetActorLocation();

	// ���� ũ�� �ؼ� �簢��ó�� ���̴°�
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

	// �츮�� �ٶ� ���� �ڷ� �ؼ� ���ָ� ��
	FVector subtract = playerLocation - location; // �÷��̾ �ٶ󺸴� ���� ����
	subtract.ToDirectionAndLength(DirectionToPlayer, DistanceToPlayer);
	DirectionToPlayer.Normalize();


	FVector xy;
	xy.X = DirectionToPlayer.X;
	xy.Y = DirectionToPlayer.Y;
	xy.Z = 0.0f; // ���̶� �������°� ������ �� ��������

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
	//else
	//	State = GoblinState::Idle;
}

void ACGoblin::Attacking()
{
	if (bAttack == true)
		return;

	bAttack = true;
	PlayAnimMontage(AttackMontage);
}

void ACGoblin::Dying()
{
	if (bDeath == true)
		return;

	bDeath = true;
	
	// �׾��� �� �浹 �ö��̴� ����.
	MainCapsule->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	WeaponCapsule->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// �ش� ��Ÿ���� ����ð��� ���ϵ�.
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
	if (bDeath == true)
		return;

	Hp -= damage;
	PrintFormat("%f", Hp);

	PlayAnimMontage(DamageMontage);

	RedBodyMaterial->SetVectorParameterValue("Color", FLinearColor(1, 0, 0, 1));

	FTimerHandle handle;
	GetWorldTimerManager().SetTimer(handle, this, &ACGoblin::DamagedComplete, 0.2f, false);
}

void ACGoblin::DamagedComplete()
{
	RedBodyMaterial->SetVectorParameterValue("Color", FLinearColor(1, 1, 1, 1));

	OnEndAttack();
	//bAttack = false;
	//State = GoblinState::Idle;

	if (Hp <= 0.0f)
		State = GoblinState::Death;
}

void ACGoblin::OnEndAttack()
{
	if (DistanceToPlayer < ReAttackDistance)
	{
		FTimerHandle handle;
		GetWorldTimerManager().SetTimer(handle, this, &ACGoblin::OnEndAttackComplete, AttackDelay, false);
	}
	else
	{
		OnEndAttackComplete();
	}
}

void ACGoblin::OnEndAttackComplete()
{
	bAttack = false;
	State = GoblinState::Follow;
}

void ACGoblin::OnBeginOverlap_Implementation(UPrimitiveComponent * OverComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor == this)
		return;

	//Print(*OtherActor->GetFName().ToString());

	ACPlayer* player = Cast<ACPlayer>(OtherActor);
	if (player == NULL)
		return;

	player->Damaged(Attack);
}