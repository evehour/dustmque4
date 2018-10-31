// Fill out your copyright notice in the Description page of Project Settings.

#include "CCameraShake.h"

UCCameraShake::UCCameraShake()
{
	OscillationDuration = 0.25f; // ī�޶� ���� ��ü �ð� 
	OscillationBlendInTime = 0.1f; // ���� �ð�
	OscillationBlendOutTime = 0.2f; // ������ ����

	RotOscillation.Pitch.Amplitude = FMath::RandRange(0.5f, 1.5f);
	RotOscillation.Pitch.Frequency = 50.0f;

	RotOscillation.Yaw.Amplitude = FMath::RandRange(0.5f, 1.5f);
	RotOscillation.Yaw.Frequency = 50.0f;

	RotOscillation.Roll.Amplitude = FMath::RandRange(0.5f, 1.5f);
	RotOscillation.Roll.Frequency = 50.0f;
}


