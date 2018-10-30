// Fill out your copyright notice in the Description page of Project Settings.

#include "CPlayer.h"

#include "Engine.h" // �����Ѱ� �� �����ϰ��־ ������ ��û ������
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

	// Game ������ �ǹ�
	static ConstructorHelpers::FObjectFinder<UAnimMontage> attack
	{
		TEXT("/Game/Montages/BpMonSwordAttack")
	};
	AttackMontage[0] = attack.Object; // attack�� �ϸ� �ȵ�

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

	// Game ������ �ǹ�
	static ConstructorHelpers::FObjectFinder<UAnimMontage> jump
	{
		TEXT("/Game/Montages/BpMonSwordJump")
	};

	JumpMontage = jump.Object;
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

	//TSubclassOf<UCameraShake>* shake; �� �����°͵��� �Ʒ��� �ִ°ɷ� ��ü���ָ� ��.
	//CameraShake = UCameraShake::StaticClass()->GetDefaultObject<UCameraShake>();
	//CameraShake = UCameraShake::GetDefaultSubobject
	//CameraShake->OscillationDuration = 0.25f; // ī�޶� ���� ��ü �ð� 
	//CameraShake->OscillationBlendInTime = 0.1f; // ���� �ð�
	//CameraShake->OscillationBlendOutTime = 0.2f; // ������ ����

	//CameraShake->RotOscillation.Pitch.Amplitude = FMath::RandRange(0.5f, 1.5f);
	//CameraShake->RotOscillation.Pitch.Frequency = 25.0f;

	//CameraShake->RotOscillation.Yaw.Amplitude = FMath::RandRange(0.5f, 1.5f);
	//CameraShake->RotOscillation.Yaw.Frequency = 25.0f;

	//CameraShake->RotOscillation.Roll.Amplitude = FMath::RandRange(0.5f, 1.5f);
	//CameraShake->RotOscillation.Roll.Frequency = 25.0f;

	

	//// print string�̶� ���� ��
	//GEngine->AddOnScreenDebugMessage(
	//	-1, // 0,1 �̷��� �ָ� �ش� ���ο��� ��� �ٲ� -1�̸� ��� �и��°�
	//	3.0f, // ���ʵ��� �������
	//	FColor::Red, // �ۻ���
	//	L"Hello, World");

	//Print("Hello Unreal");

	// ���ڿ� �϶��� ������ �ٿ������
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
	// Super �θ�
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// bind ���� �Լ��� �����ϴ°�
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

	// �÷��̾� ��Ʈ�ѷ� ��������.
	APlayerController* cont = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	//cont->ClientPlayCameraShake(CameraShake,)

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
	}
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
