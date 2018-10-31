// Fill out your copyright notice in the Description page of Project Settings.

#include "CPlayer.h"

#include "Engine.h" // 웬만한거 다 포함하고있어서 컴파일 엄청 느려짐
#include "CConsoleLog.h"
#include "CCamera.h"
#include "Animation/AnimMontage.h"
#include "Components/CapsuleComponent.h"
#include "CGoblin.h"
#include "Camera/CameraShake.h"

// Sets default values
ACPlayer::ACPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Attack = 30.0f;
	bAttack = false;
	bNextCombo = false;
	ComboCount = 0;

	// Game 콘텐츠 의미
	static ConstructorHelpers::FObjectFinder<UAnimMontage> attack
	{
		TEXT("/Game/Montages/BpMonSwordAttack")
	};
	AttackMontage[0] = attack.Object; // attack만 하면 안됨

	static ConstructorHelpers::FObjectFinder<UAnimMontage> attack2
	{
		TEXT("/Game/Montages/BpMonSwordAttack2")
	};
	AttackMontage[1] = attack2.Object;

	static ConstructorHelpers::FObjectFinder<UAnimMontage> attack3
	{
		TEXT("/Game/Montages/BpMonSwordAttack3")
	};
	AttackMontage[2] = attack3.Object;

	// Game 콘텐츠 의미
	static ConstructorHelpers::FObjectFinder<UAnimMontage> jump
	{
		TEXT("/Game/Montages/BpMonSwordJump")
	};

	JumpMontage = jump.Object;

	//static ConstructorHelpers::FObjectFinder<UParticleSystem> finishComboParticle
	//{
	//	TEXT("/Game/Particles/FinishComboParticle")
	//};
	//FinishComboParticle = CreateDefaultSubobject< UParticleSystemComponent>(TEXT("FinishComboParticle"));
	//FinishComboParticle->SetTemplate(finishComboParticle.Object);
	
	//for (FParticleEmitterInstance* emitter : FinishComboParticle->EmitterInstances)
	////for(UINT i = 0; i < FinishComboParticle->EmitterInstances)
	//{
	//	emitter->LoopCount = 1;
	//}


	static ConstructorHelpers::FObjectFinder<UMaterial> bodyMaterial
	(
		TEXT("/Game/Player/Materials/Body_SG")
	);
	BodyMaterial = bodyMaterial.Object;

	static ConstructorHelpers::FObjectFinder<UMaterial> redMaterial
	(
		TEXT("/Game/Player/Materials/logo_m")
	);
	RedMaterial = redMaterial.Object;
}

// Called when the game starts or when spawned
void ACPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	TSet<UActorComponent *> components = this->GetComponents();
	for (UActorComponent* component : components)
	{
		if (component->GetFName() == "Capsule")
			WeaponCapsule = Cast<UCapsuleComponent>(component);
	}

	WeaponCapsule->OnComponentBeginOverlap.AddDynamic(this, &ACPlayer::OnBeginOverlap);
	WeaponCapsule->SetCollisionEnabled(ECollisionEnabled::NoCollision);


	//// print string이랑 같은 애
	//GEngine->AddOnScreenDebugMessage(
	//	-1, // 0,1 이런거 주면 해당 라인에서 계속 바뀜 -1이면 계속 밀리는거
	//	3.0f, // 몇초동안 출력할지
	//	FColor::Red, // 글색상
	//	L"Hello, World");

	//Print("Hello Unreal");

	// 문자열 일때는 포인터 붙여줘야함
	//FString test = "Hello, Unreal2";
	//PrintFormat("Vec : %s", *test);

	//int a = 10;
	//PrintFormat("Vec : %d", a);
	//
	//UE_LOG(LogTemp, Warning, TEXT("a = %d"), a);

}

// Called every frame
void ACPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Super 부모
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// bind 그쪽 함수로 연결하는거
	InputComponent->BindAxis("MoveForward", this, &ACPlayer::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ACPlayer::MoveRight);
	
	InputComponent->BindAction("Attack", IE_Pressed, this, &ACPlayer::Attacking);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACPlayer::Jumping);
	InputComponent->BindAction("Jump", IE_Released, this, &ACPlayer::StopJumping);
}

void ACPlayer::MoveForward(float axisValue)
{
	if (bAttack == true) return;

	FVector vec = FVector(1, 0, 0);
	AddMovementInput(vec, axisValue);
}

void ACPlayer::MoveRight(float axisValue)
{
	FVector vec = FVector(0, 1, 0);
	AddMovementInput(vec, axisValue);
}

void ACPlayer::Jumping()
{
	bool bFalling = GetCharacterMovement()->IsFalling();
	if (bFalling == false && bAttack == false)
	{
		PlayAnimMontage(JumpMontage);

		Jump();
	}
}

void ACPlayer::OnBeginOverlap_Implementation(UPrimitiveComponent * OverComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor == this)
		return;

	// 플레이어 컨트롤러 가져오기.
	APlayerController* cont = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	cont->ClientPlayCameraShake(CameraShake);

	ACGoblin* monster = Cast<ACGoblin>(OtherActor);
	if (monster != NULL)
		monster->Damaged(Attack);

	Print(*OtherActor->GetFName().ToString());
}

void ACPlayer::Attacking()
{
	if (bAttack == true)
	{
		bNextCombo = true;
	}
	else
	{
		bAttack = true;

		PlayAnimMontage(AttackMontage[ComboCount]);

		if (ComboCount > 1)
		{
			FTimerHandle handle;
			GetWorldTimerManager().SetTimer(handle, this, &ACPlayer::FinishComboComplete, 0.47f, false);
		}
	}
}

void ACPlayer::FinishComboComplete()
{
	//UGameplayStatics::SpawnEmitterAtLocation
	//(
	//	GetWorld(), (UParticleSystem*)FinishComboParticle,
	//	GetActorLocation(), FRotator::ZeroRotator, FVector::OneVector, true
	//);
}

void ACPlayer::OnEndAttack()
{
	bAttack = false;

	if (bNextCombo == true)
	{
		Attacking();
		bNextCombo = false;
	}
	else
		ComboCount = 0;
}

void ACPlayer::OnCheckCombo()
{
	if (bNextCombo == true)
		ComboCount++;
}

void ACPlayer::OnFinishCombo()
{
	bAttack = false;
	bNextCombo = false;

	ComboCount = 0;
}

void ACPlayer::Damaged(float damage)
{
	GetMesh()->SetMaterial(0, RedMaterial);

	FTimerHandle handle;
	GetWorldTimerManager().SetTimer(handle, this, &ACPlayer::DamagedComplete, 0.2f, false);
}

void ACPlayer::DamagedComplete()
{
	GetMesh()->SetMaterial(0, BodyMaterial);
}

