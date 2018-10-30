// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SGAUNREAL_CPlayer_generated_h
#error "CPlayer.generated.h already included, missing '#pragma once' in CPlayer.h"
#endif
#define SGAUNREAL_CPlayer_generated_h

#define SGAUnreal_Source_SGAUnreal_CPlayer_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnEndAttack) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnEndAttack(); \
		P_NATIVE_END; \
	}


#define SGAUnreal_Source_SGAUnreal_CPlayer_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnEndAttack) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnEndAttack(); \
		P_NATIVE_END; \
	}


#define SGAUnreal_Source_SGAUnreal_CPlayer_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACPlayer(); \
	friend struct Z_Construct_UClass_ACPlayer_Statics; \
public: \
	DECLARE_CLASS(ACPlayer, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SGAUnreal"), NO_API) \
	DECLARE_SERIALIZER(ACPlayer)


#define SGAUnreal_Source_SGAUnreal_CPlayer_h_12_INCLASS \
private: \
	static void StaticRegisterNativesACPlayer(); \
	friend struct Z_Construct_UClass_ACPlayer_Statics; \
public: \
	DECLARE_CLASS(ACPlayer, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SGAUnreal"), NO_API) \
	DECLARE_SERIALIZER(ACPlayer)


#define SGAUnreal_Source_SGAUnreal_CPlayer_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACPlayer(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACPlayer) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACPlayer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACPlayer); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACPlayer(ACPlayer&&); \
	NO_API ACPlayer(const ACPlayer&); \
public:


#define SGAUnreal_Source_SGAUnreal_CPlayer_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACPlayer(ACPlayer&&); \
	NO_API ACPlayer(const ACPlayer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACPlayer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACPlayer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACPlayer)


#define SGAUnreal_Source_SGAUnreal_CPlayer_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__AttackMontage() { return STRUCT_OFFSET(ACPlayer, AttackMontage); } \
	FORCEINLINE static uint32 __PPO__JumpMontage() { return STRUCT_OFFSET(ACPlayer, JumpMontage); }


#define SGAUnreal_Source_SGAUnreal_CPlayer_h_9_PROLOG
#define SGAUnreal_Source_SGAUnreal_CPlayer_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SGAUnreal_Source_SGAUnreal_CPlayer_h_12_PRIVATE_PROPERTY_OFFSET \
	SGAUnreal_Source_SGAUnreal_CPlayer_h_12_RPC_WRAPPERS \
	SGAUnreal_Source_SGAUnreal_CPlayer_h_12_INCLASS \
	SGAUnreal_Source_SGAUnreal_CPlayer_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SGAUnreal_Source_SGAUnreal_CPlayer_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SGAUnreal_Source_SGAUnreal_CPlayer_h_12_PRIVATE_PROPERTY_OFFSET \
	SGAUnreal_Source_SGAUnreal_CPlayer_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	SGAUnreal_Source_SGAUnreal_CPlayer_h_12_INCLASS_NO_PURE_DECLS \
	SGAUnreal_Source_SGAUnreal_CPlayer_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SGAUnreal_Source_SGAUnreal_CPlayer_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
