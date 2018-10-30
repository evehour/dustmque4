// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SGAUnreal/CAnimPlayer.h"
#include "Engine/Classes/Components/SkeletalMeshComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCAnimPlayer() {}
// Cross Module References
	SGAUNREAL_API UClass* Z_Construct_UClass_UCAnimPlayer_NoRegister();
	SGAUNREAL_API UClass* Z_Construct_UClass_UCAnimPlayer();
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
	UPackage* Z_Construct_UPackage__Script_SGAUnreal();
	SGAUNREAL_API UFunction* Z_Construct_UFunction_UCAnimPlayer_UpdateSpeed();
// End Cross Module References
	void UCAnimPlayer::StaticRegisterNativesUCAnimPlayer()
	{
		UClass* Class = UCAnimPlayer::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "UpdateSpeed", &UCAnimPlayer::execUpdateSpeed },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCAnimPlayer_UpdateSpeed_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCAnimPlayer_UpdateSpeed_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CAnimPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UCAnimPlayer_UpdateSpeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCAnimPlayer, "UpdateSpeed", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCAnimPlayer_UpdateSpeed_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UCAnimPlayer_UpdateSpeed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCAnimPlayer_UpdateSpeed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCAnimPlayer_UpdateSpeed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UCAnimPlayer_NoRegister()
	{
		return UCAnimPlayer::StaticClass();
	}
	struct Z_Construct_UClass_UCAnimPlayer_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bWalking_MetaData[];
#endif
		static void NewProp_bWalking_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bWalking;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCAnimPlayer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_SGAUnreal,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCAnimPlayer_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCAnimPlayer_UpdateSpeed, "UpdateSpeed" }, // 3328318267
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCAnimPlayer_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "CAnimPlayer.h" },
		{ "ModuleRelativePath", "CAnimPlayer.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCAnimPlayer_Statics::NewProp_bWalking_MetaData[] = {
		{ "Category", "CAnimPlayer" },
		{ "ModuleRelativePath", "CAnimPlayer.h" },
	};
#endif
	void Z_Construct_UClass_UCAnimPlayer_Statics::NewProp_bWalking_SetBit(void* Obj)
	{
		((UCAnimPlayer*)Obj)->bWalking = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCAnimPlayer_Statics::NewProp_bWalking = { UE4CodeGen_Private::EPropertyClass::Bool, "bWalking", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000015, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UCAnimPlayer), &Z_Construct_UClass_UCAnimPlayer_Statics::NewProp_bWalking_SetBit, METADATA_PARAMS(Z_Construct_UClass_UCAnimPlayer_Statics::NewProp_bWalking_MetaData, ARRAY_COUNT(Z_Construct_UClass_UCAnimPlayer_Statics::NewProp_bWalking_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCAnimPlayer_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCAnimPlayer_Statics::NewProp_bWalking,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCAnimPlayer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCAnimPlayer>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCAnimPlayer_Statics::ClassParams = {
		&UCAnimPlayer::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A8u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_UCAnimPlayer_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UCAnimPlayer_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UCAnimPlayer_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UCAnimPlayer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCAnimPlayer()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCAnimPlayer_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCAnimPlayer, 659350339);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCAnimPlayer(Z_Construct_UClass_UCAnimPlayer, &UCAnimPlayer::StaticClass, TEXT("/Script/SGAUnreal"), TEXT("UCAnimPlayer"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCAnimPlayer);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
