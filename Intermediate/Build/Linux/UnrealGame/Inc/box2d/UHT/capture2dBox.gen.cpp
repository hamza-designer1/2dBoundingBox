// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "box2d/Public/capture2dBox.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodecapture2dBox() {}
// Cross Module References
	BOX2D_API UClass* Z_Construct_UClass_Acapture2dBox();
	BOX2D_API UClass* Z_Construct_UClass_Acapture2dBox_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_box2d();
// End Cross Module References
	DEFINE_FUNCTION(Acapture2dBox::execgenerate2d)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_usrFrames);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->generate2d(Z_Param_usrFrames);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(Acapture2dBox::execgenerated3d)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_frameNum);
		P_GET_TARRAY(FVector,Z_Param_vehiclesBoxLocations);
		P_GET_TARRAY(FRotator,Z_Param_vehiclesBoxRotations);
		P_GET_STRUCT(FVector,Z_Param_sensorLocation);
		P_GET_STRUCT(FRotator,Z_Param_sensorRotation);
		P_GET_TARRAY(FVector,Z_Param_vehiclesBoxExtends);
		P_GET_TARRAY(FVector,Z_Param_vehiclesLocations);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->generated3d(Z_Param_frameNum,Z_Param_vehiclesBoxLocations,Z_Param_vehiclesBoxRotations,Z_Param_sensorLocation,Z_Param_sensorRotation,Z_Param_vehiclesBoxExtends,Z_Param_vehiclesLocations);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(Acapture2dBox::execCheckFiles)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_usrFrame);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->CheckFiles(Z_Param_usrFrame);
		P_NATIVE_END;
	}
	void Acapture2dBox::StaticRegisterNativesAcapture2dBox()
	{
		UClass* Class = Acapture2dBox::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CheckFiles", &Acapture2dBox::execCheckFiles },
			{ "generate2d", &Acapture2dBox::execgenerate2d },
			{ "generated3d", &Acapture2dBox::execgenerated3d },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_Acapture2dBox_CheckFiles_Statics
	{
		struct capture2dBox_eventCheckFiles_Parms
		{
			int32 usrFrame;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_usrFrame;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_Acapture2dBox_CheckFiles_Statics::NewProp_usrFrame = { "usrFrame", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(capture2dBox_eventCheckFiles_Parms, usrFrame), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_Acapture2dBox_CheckFiles_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((capture2dBox_eventCheckFiles_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_Acapture2dBox_CheckFiles_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(capture2dBox_eventCheckFiles_Parms), &Z_Construct_UFunction_Acapture2dBox_CheckFiles_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_Acapture2dBox_CheckFiles_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Acapture2dBox_CheckFiles_Statics::NewProp_usrFrame,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Acapture2dBox_CheckFiles_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_Acapture2dBox_CheckFiles_Statics::Function_MetaDataParams[] = {
		{ "Category", "2dBBoxGen" },
		{ "ModuleRelativePath", "Public/capture2dBox.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_Acapture2dBox_CheckFiles_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_Acapture2dBox, nullptr, "CheckFiles", nullptr, nullptr, sizeof(Z_Construct_UFunction_Acapture2dBox_CheckFiles_Statics::capture2dBox_eventCheckFiles_Parms), Z_Construct_UFunction_Acapture2dBox_CheckFiles_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_Acapture2dBox_CheckFiles_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_Acapture2dBox_CheckFiles_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_Acapture2dBox_CheckFiles_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_Acapture2dBox_CheckFiles()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_Acapture2dBox_CheckFiles_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_Acapture2dBox_generate2d_Statics
	{
		struct capture2dBox_eventgenerate2d_Parms
		{
			int32 usrFrames;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_usrFrames;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_Acapture2dBox_generate2d_Statics::NewProp_usrFrames = { "usrFrames", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(capture2dBox_eventgenerate2d_Parms, usrFrames), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_Acapture2dBox_generate2d_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Acapture2dBox_generate2d_Statics::NewProp_usrFrames,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_Acapture2dBox_generate2d_Statics::Function_MetaDataParams[] = {
		{ "Category", "2dBBoxGen" },
		{ "ModuleRelativePath", "Public/capture2dBox.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_Acapture2dBox_generate2d_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_Acapture2dBox, nullptr, "generate2d", nullptr, nullptr, sizeof(Z_Construct_UFunction_Acapture2dBox_generate2d_Statics::capture2dBox_eventgenerate2d_Parms), Z_Construct_UFunction_Acapture2dBox_generate2d_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_Acapture2dBox_generate2d_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_Acapture2dBox_generate2d_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_Acapture2dBox_generate2d_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_Acapture2dBox_generate2d()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_Acapture2dBox_generate2d_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_Acapture2dBox_generated3d_Statics
	{
		struct capture2dBox_eventgenerated3d_Parms
		{
			int32 frameNum;
			TArray<FVector> vehiclesBoxLocations;
			TArray<FRotator> vehiclesBoxRotations;
			FVector sensorLocation;
			FRotator sensorRotation;
			TArray<FVector> vehiclesBoxExtends;
			TArray<FVector> vehiclesLocations;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_frameNum;
		static const UECodeGen_Private::FStructPropertyParams NewProp_vehiclesBoxLocations_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_vehiclesBoxLocations;
		static const UECodeGen_Private::FStructPropertyParams NewProp_vehiclesBoxRotations_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_vehiclesBoxRotations;
		static const UECodeGen_Private::FStructPropertyParams NewProp_sensorLocation;
		static const UECodeGen_Private::FStructPropertyParams NewProp_sensorRotation;
		static const UECodeGen_Private::FStructPropertyParams NewProp_vehiclesBoxExtends_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_vehiclesBoxExtends;
		static const UECodeGen_Private::FStructPropertyParams NewProp_vehiclesLocations_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_vehiclesLocations;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::NewProp_frameNum = { "frameNum", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(capture2dBox_eventgenerated3d_Parms, frameNum), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::NewProp_vehiclesBoxLocations_Inner = { "vehiclesBoxLocations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::NewProp_vehiclesBoxLocations = { "vehiclesBoxLocations", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(capture2dBox_eventgenerated3d_Parms, vehiclesBoxLocations), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::NewProp_vehiclesBoxRotations_Inner = { "vehiclesBoxRotations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::NewProp_vehiclesBoxRotations = { "vehiclesBoxRotations", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(capture2dBox_eventgenerated3d_Parms, vehiclesBoxRotations), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::NewProp_sensorLocation = { "sensorLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(capture2dBox_eventgenerated3d_Parms, sensorLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::NewProp_sensorRotation = { "sensorRotation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(capture2dBox_eventgenerated3d_Parms, sensorRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::NewProp_vehiclesBoxExtends_Inner = { "vehiclesBoxExtends", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::NewProp_vehiclesBoxExtends = { "vehiclesBoxExtends", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(capture2dBox_eventgenerated3d_Parms, vehiclesBoxExtends), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::NewProp_vehiclesLocations_Inner = { "vehiclesLocations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::NewProp_vehiclesLocations = { "vehiclesLocations", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(capture2dBox_eventgenerated3d_Parms, vehiclesLocations), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::NewProp_frameNum,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::NewProp_vehiclesBoxLocations_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::NewProp_vehiclesBoxLocations,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::NewProp_vehiclesBoxRotations_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::NewProp_vehiclesBoxRotations,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::NewProp_sensorLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::NewProp_sensorRotation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::NewProp_vehiclesBoxExtends_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::NewProp_vehiclesBoxExtends,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::NewProp_vehiclesLocations_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::NewProp_vehiclesLocations,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::Function_MetaDataParams[] = {
		{ "Category", "3dBBoxGen" },
		{ "ModuleRelativePath", "Public/capture2dBox.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_Acapture2dBox, nullptr, "generated3d", nullptr, nullptr, sizeof(Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::capture2dBox_eventgenerated3d_Parms), Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_Acapture2dBox_generated3d()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_Acapture2dBox_generated3d_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(Acapture2dBox);
	UClass* Z_Construct_UClass_Acapture2dBox_NoRegister()
	{
		return Acapture2dBox::StaticClass();
	}
	struct Z_Construct_UClass_Acapture2dBox_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_Acapture2dBox_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_box2d,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_Acapture2dBox_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_Acapture2dBox_CheckFiles, "CheckFiles" }, // 2822697143
		{ &Z_Construct_UFunction_Acapture2dBox_generate2d, "generate2d" }, // 3013593653
		{ &Z_Construct_UFunction_Acapture2dBox_generated3d, "generated3d" }, // 2126638606
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Acapture2dBox_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "capture2dBox.h" },
		{ "ModuleRelativePath", "Public/capture2dBox.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_Acapture2dBox_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<Acapture2dBox>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_Acapture2dBox_Statics::ClassParams = {
		&Acapture2dBox::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_Acapture2dBox_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_Acapture2dBox_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_Acapture2dBox()
	{
		if (!Z_Registration_Info_UClass_Acapture2dBox.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_Acapture2dBox.OuterSingleton, Z_Construct_UClass_Acapture2dBox_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_Acapture2dBox.OuterSingleton;
	}
	template<> BOX2D_API UClass* StaticClass<Acapture2dBox>()
	{
		return Acapture2dBox::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(Acapture2dBox);
	Acapture2dBox::~Acapture2dBox() {}
	struct Z_CompiledInDeferFile_FID_Altroverse_LA_Plugins_box2d_Source_box2d_Public_capture2dBox_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Altroverse_LA_Plugins_box2d_Source_box2d_Public_capture2dBox_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_Acapture2dBox, Acapture2dBox::StaticClass, TEXT("Acapture2dBox"), &Z_Registration_Info_UClass_Acapture2dBox, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(Acapture2dBox), 3970608308U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Altroverse_LA_Plugins_box2d_Source_box2d_Public_capture2dBox_h_3667889268(TEXT("/Script/box2d"),
		Z_CompiledInDeferFile_FID_Altroverse_LA_Plugins_box2d_Source_box2d_Public_capture2dBox_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Altroverse_LA_Plugins_box2d_Source_box2d_Public_capture2dBox_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
