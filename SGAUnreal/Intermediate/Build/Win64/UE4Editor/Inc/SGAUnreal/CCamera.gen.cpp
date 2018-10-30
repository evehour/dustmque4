// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SGAUnreal/CCamera.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCCamera() {}
// Cross Module References
	SGAUNREAL_API UClass* Z_Construct_UClass_ACCamera_NoRegister();
	SGAUNREAL_API UClass* Z_Construct_UClass_ACCamera();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_SGAUnreal();
// End Cross Module References
	void ACCamera::StaticRegisterNativesACCamera()
	{
	}
	UClass* Z_Construct_UClass_ACCamera_NoRegister()
	{
		return ACCamera::StaticClass();
	}
	struct Z_Construct_UClass_ACCamera_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACCamera_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_SGAUnreal,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACCamera_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "CCamera.h" },
		{ "ModuleRelativePath", "CCamera.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACCamera_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACCamera>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACCamera_Statics::ClassParams = {
		&ACCamera::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ACCamera_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ACCamera_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACCamera()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACCamera_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACCamera, 2031682901);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACCamera(Z_Construct_UClass_ACCamera, &ACCamera::StaticClass, TEXT("/Script/SGAUnreal"), TEXT("ACCamera"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACCamera);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
