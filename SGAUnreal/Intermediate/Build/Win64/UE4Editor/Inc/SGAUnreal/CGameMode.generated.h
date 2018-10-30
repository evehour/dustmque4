// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SGAUNREAL_CGameMode_generated_h
#error "CGameMode.generated.h already included, missing '#pragma once' in CGameMode.h"
#endif
#define SGAUNREAL_CGameMode_generated_h

#define SGAUnreal_Source_SGAUnreal_CGameMode_h_15_RPC_WRAPPERS
#define SGAUnreal_Source_SGAUnreal_CGameMode_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define SGAUnreal_Source_SGAUnreal_CGameMode_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACGameMode(); \
	friend struct Z_Construct_UClass_ACGameMode_Statics; \
public: \
	DECLARE_CLASS(ACGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/SGAUnreal"), NO_API) \
	DECLARE_SERIALIZER(ACGameMode)


#define SGAUnreal_Source_SGAUnreal_CGameMode_h_15_INCLASS \
private: \
	static void StaticRegisterNativesACGameMode(); \
	friend struct Z_Construct_UClass_ACGameMode_Statics; \
public: \
	DECLARE_CLASS(ACGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/SGAUnreal"), NO_API) \
	DECLARE_SERIALIZER(ACGameMode)


#define SGAUnreal_Source_SGAUnreal_CGameMode_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACGameMode(ACGameMode&&); \
	NO_API ACGameMode(const ACGameMode&); \
public:


#define SGAUnreal_Source_SGAUnreal_CGameMode_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACGameMode(ACGameMode&&); \
	NO_API ACGameMode(const ACGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACGameMode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACGameMode)


#define SGAUnreal_Source_SGAUnreal_CGameMode_h_15_PRIVATE_PROPERTY_OFFSET
#define SGAUnreal_Source_SGAUnreal_CGameMode_h_12_PROLOG
#define SGAUnreal_Source_SGAUnreal_CGameMode_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SGAUnreal_Source_SGAUnreal_CGameMode_h_15_PRIVATE_PROPERTY_OFFSET \
	SGAUnreal_Source_SGAUnreal_CGameMode_h_15_RPC_WRAPPERS \
	SGAUnreal_Source_SGAUnreal_CGameMode_h_15_INCLASS \
	SGAUnreal_Source_SGAUnreal_CGameMode_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SGAUnreal_Source_SGAUnreal_CGameMode_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SGAUnreal_Source_SGAUnreal_CGameMode_h_15_PRIVATE_PROPERTY_OFFSET \
	SGAUnreal_Source_SGAUnreal_CGameMode_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	SGAUnreal_Source_SGAUnreal_CGameMode_h_15_INCLASS_NO_PURE_DECLS \
	SGAUnreal_Source_SGAUnreal_CGameMode_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SGAUnreal_Source_SGAUnreal_CGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
