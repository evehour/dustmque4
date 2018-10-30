// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SGAUNREAL_CAnimPlayer_generated_h
#error "CAnimPlayer.generated.h already included, missing '#pragma once' in CAnimPlayer.h"
#endif
#define SGAUNREAL_CAnimPlayer_generated_h

#define SGAUnreal_Source_SGAUnreal_CAnimPlayer_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execUpdateSpeed) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateSpeed(); \
		P_NATIVE_END; \
	}


#define SGAUnreal_Source_SGAUnreal_CAnimPlayer_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execUpdateSpeed) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateSpeed(); \
		P_NATIVE_END; \
	}


#define SGAUnreal_Source_SGAUnreal_CAnimPlayer_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCAnimPlayer(); \
	friend struct Z_Construct_UClass_UCAnimPlayer_Statics; \
public: \
	DECLARE_CLASS(UCAnimPlayer, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/SGAUnreal"), NO_API) \
	DECLARE_SERIALIZER(UCAnimPlayer)


#define SGAUnreal_Source_SGAUnreal_CAnimPlayer_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUCAnimPlayer(); \
	friend struct Z_Construct_UClass_UCAnimPlayer_Statics; \
public: \
	DECLARE_CLASS(UCAnimPlayer, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/SGAUnreal"), NO_API) \
	DECLARE_SERIALIZER(UCAnimPlayer)


#define SGAUnreal_Source_SGAUnreal_CAnimPlayer_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCAnimPlayer(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCAnimPlayer) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCAnimPlayer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCAnimPlayer); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCAnimPlayer(UCAnimPlayer&&); \
	NO_API UCAnimPlayer(const UCAnimPlayer&); \
public:


#define SGAUnreal_Source_SGAUnreal_CAnimPlayer_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCAnimPlayer(UCAnimPlayer&&); \
	NO_API UCAnimPlayer(const UCAnimPlayer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCAnimPlayer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCAnimPlayer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCAnimPlayer)


#define SGAUnreal_Source_SGAUnreal_CAnimPlayer_h_15_PRIVATE_PROPERTY_OFFSET
#define SGAUnreal_Source_SGAUnreal_CAnimPlayer_h_12_PROLOG
#define SGAUnreal_Source_SGAUnreal_CAnimPlayer_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SGAUnreal_Source_SGAUnreal_CAnimPlayer_h_15_PRIVATE_PROPERTY_OFFSET \
	SGAUnreal_Source_SGAUnreal_CAnimPlayer_h_15_RPC_WRAPPERS \
	SGAUnreal_Source_SGAUnreal_CAnimPlayer_h_15_INCLASS \
	SGAUnreal_Source_SGAUnreal_CAnimPlayer_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SGAUnreal_Source_SGAUnreal_CAnimPlayer_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SGAUnreal_Source_SGAUnreal_CAnimPlayer_h_15_PRIVATE_PROPERTY_OFFSET \
	SGAUnreal_Source_SGAUnreal_CAnimPlayer_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	SGAUnreal_Source_SGAUnreal_CAnimPlayer_h_15_INCLASS_NO_PURE_DECLS \
	SGAUnreal_Source_SGAUnreal_CAnimPlayer_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SGAUnreal_Source_SGAUnreal_CAnimPlayer_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
