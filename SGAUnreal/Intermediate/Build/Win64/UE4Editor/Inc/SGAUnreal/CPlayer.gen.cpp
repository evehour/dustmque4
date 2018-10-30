// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SGAUnreal/CPlayer.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCPlayer() {}
// Cross Module References
	SGAUNREAL_API UClass* Z_Construct_UClass_ACPlayer_NoRegister();
	SGAUNREAL_API UClass* Z_Construct_UClass_ACPlayer();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_SGAUnreal();
	SGAUNREAL_API UFunction* Z_Construct_UFunction_ACPlayer_OnEndAttack();
	ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	void ACPlayer::StaticRegisterNativesACPlayer()
	{
		UClass* Class = ACPlayer::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnEndAttack", &ACPlayer::execOnEndAttack },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ACPlayer_OnEndAttack_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACPlayer_OnEndAttack_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ACPlayer_OnEndAttack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACPlayer, "OnEndAttack", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ACPlayer_OnEndAttack_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ACPlayer_OnEndAttack_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ACPlayer_OnEndAttack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ACPlayer_OnEndAttack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ACPlayer_NoRegister()
	{
		return ACPlayer::StaticClass();
	}
	struct Z_Construct_UClass_ACPlayer_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_JumpMontage_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_JumpMontage;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttackMontage_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AttackMontage;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraObject_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CameraObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACPlayer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_SGAUnreal,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ACPlayer_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ACPlayer_OnEndAttack, "OnEndAttack" }, // 2798146198
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPlayer_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "CPlayer.h" },
		{ "ModuleRelativePath", "CPlayer.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPlayer_Statics::NewProp_JumpMontage_MetaData[] = {
		{ "Category", "CPlayer" },
		{ "ModuleRelativePath", "CPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPlayer_Statics::NewProp_JumpMontage = { UE4CodeGen_Private::EPropertyClass::Object, "JumpMontage", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000020001, 1, nullptr, STRUCT_OFFSET(ACPlayer, JumpMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACPlayer_Statics::NewProp_JumpMontage_MetaData, ARRAY_COUNT(Z_Construct_UClass_ACPlayer_Statics::NewProp_JumpMontage_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPlayer_Statics::NewProp_AttackMontage_MetaData[] = {
		{ "Category", "CPlayer" },
		{ "ModuleRelativePath", "CPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPlayer_Statics::NewProp_AttackMontage = { UE4CodeGen_Private::EPropertyClass::Object, "AttackMontage", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000020001, 1, nullptr, STRUCT_OFFSET(ACPlayer, AttackMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACPlayer_Statics::NewProp_AttackMontage_MetaData, ARRAY_COUNT(Z_Construct_UClass_ACPlayer_Statics::NewProp_AttackMontage_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPlayer_Statics::NewProp_CameraObject_MetaData[] = {
		{ "Category", "CPlayer" },
		{ "ModuleRelativePath", "CPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPlayer_Statics::NewProp_CameraObject = { UE4CodeGen_Private::EPropertyClass::Object, "CameraObject", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ACPlayer, CameraObject), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACPlayer_Statics::NewProp_CameraObject_MetaData, ARRAY_COUNT(Z_Construct_UClass_ACPlayer_Statics::NewProp_CameraObject_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACPlayer_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPlayer_Statics::NewProp_JumpMontage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPlayer_Statics::NewProp_AttackMontage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPlayer_Statics::NewProp_CameraObject,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACPlayer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACPlayer>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACPlayer_Statics::ClassParams = {
		&ACPlayer::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_ACPlayer_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_ACPlayer_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ACPlayer_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ACPlayer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACPlayer()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACPlayer_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACPlayer, 4273538326);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACPlayer(Z_Construct_UClass_ACPlayer, &ACPlayer::StaticClass, TEXT("/Script/SGAUnreal"), TEXT("ACPlayer"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACPlayer);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
