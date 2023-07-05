// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IImageWrapperModule.h"
#include "ImageUtils.h"
#include "Containers/Array.h"
#include "Math/Matrix.h"
#include "Math/Vector2D.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "capture2dBox.generated.h"



// Define a custom 3x3 matrix struct
struct FMatrix3x3
{
	float M[3][3];


	FVector TransformFVector3(const FVector& vector) const
	{
		FVector result;
		result.X = M[0][0] * vector.X + M[0][1] * vector.Y + M[0][2] * vector.Z;
		result.Y = M[1][0] * vector.X + M[1][1] * vector.Y + M[1][2] * vector.Z;
		result.Z = M[2][0] * vector.X + M[2][1] * vector.Y + M[2][2] * vector.Z;
		return result;
	}
};


UCLASS()
class BOX2D_API Acapture2dBox : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	Acapture2dBox();
	// Called every frame
	virtual void Tick(float DeltaTime) override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	TArray<TArray<FColor>> rgbImage;
	TArray<TArray<FColor>> segImage;
	TArray<TArray<FColor>> areaInfo;
	TArray<TArray<FColor>> segInfo;
	TArray<TArray<FColor>> rgbInfo;
	int32 viewHeight = 1080;
	int32 viewWidth = 1920;
	int32 viewFOV = 90;
	FMatrix3x3  CamCalib;


	TTuple<TArray<TArray<FVector2D>>, int32, bool> result;
	//TArray<FColor> vehiclesColors;

	FString dirRGB = "custom_data/";
	FString dirSeg = "SegmentationImage/";
	FString dirVbbox = "VehicleBBox/";
	FString mainDir = FPaths::ProjectSavedDir() + "data/";
	FString colorFolder = mainDir + "carColors/";
	//FString rgbDir = FPaths::ProjectSavedDir() + "data/custom_data/";
	//FString segDir = FPaths::ProjectSavedDir() + "data/SegmentationImage/";
	FString FilePath = TEXT("E:/ue5_2_project/carFree/Saved/sample/img_000000.jpeg");
	//FString SavePath = TEXT("E:/ue5_2_project/carFree/Saved/output");

	FString SavePath = mainDir + FString::Printf(TEXT("custom_data/img_%.6d.jpeg"), 1); // Modify the filename and extension as desired
	TArray<TArray<FColor>> readImage(const TCHAR* path, EImageFormat format);
	//TArray<TArray<FColor>> readImage(const TCHAR* path);
	//TTuple<TArray<TArray<FColor>>,int32> readingData(int32 Index);
	TTuple<TArray<TArray<FVector2D>>, int32, bool> readingData(int32 index);
	TArray<TArray<FVector2D>> ConvertBoundingBoxes(const TArray<TArray<FVector2D>>& boundingBoxes, int32 lineLength);
	void objectArea(TArray<TArray<FVector2D>> data, TArray<FColor> vehiclesColors);
	bool Filtering(TArray<float> array, FColor color);
	bool preOccludedObjectsExcluded(TArray<float> array, TArray<TArray<FColor>> areaImage, FColor color);
	bool smallObjectsExcluded(TArray<float> array, float bb_min);
	bool postOccludedObjectsExcluded(TArray<float> array, FColor color);
	int32 fittingX(int32 x1, int32 x2, int32 rangeMin, int32 rangeMax, FColor color);
	int32 fittingY(int32 y1, int32 y2, int32 rangeMin, int32 rangeMax, FColor color);
	void processing(TArray<TArray<FColor>> img, TArray<TArray<FVector2D>> vData, int32 index, TArray<FColor> vehiclesColors);
	TArray<FColor> ReadColors(int32 frameNum);
	TArray<FVector4> CreateBBPoints(FVector vehicleBoxExtend);
	FMatrix GetMatrix(const FTransform& transform);
	TArray<TArray<float>> VehicleToWorld(TArray<FVector4> cords, FVector vehicleBoxLocation, FRotator vehicleBoxRotation, FVector vehicleLocation);
	TArray<TArray<float>> WorldToSensor(TArray<TArray<float>> cords, FVector sensorLocation, FRotator sensorRotation);
	TArray<TArray<float>> VehicleToSensor(TArray<FVector4> cords, FVector vehicleBoxLocation, FRotator vehicleBoxRotation, FVector sensorLocation, FRotator sensorRotation, FVector vehicleLocation);
	TArray<TArray<float>> GetBoundingBox(FVector vehicleBoxLocation, FRotator vehicleBoxRotation, FVector sensorLocation, FRotator sensorRotation, FVector vehicleBoxExtend, FVector vehicleLocation);
	TArray<TArray<TArray<float>>> GetBoundingBoxes(TArray<FVector> vehiclesBoxLocations, TArray<FRotator> vehiclesBoxRotations, FVector sensorLocation, FRotator sensorRotation, TArray<FVector> vehiclesBoxExtends, TArray<FVector> vehiclesLocations);
	void DrawBoundingBoxes(const TArray < TArray<TArray<float>> >& BoundingBoxes, int32 FrameNum);
	void SetupCamCalib();
	TArray<float> divArr(TArray<float> array1, TArray<float> array2);
	TArray<TArray<float>> transArr(TArray<TArray<float>> orgArr);
	UFUNCTION(BlueprintCallable, Category = "2dBBoxGen")
		bool CheckFiles(int32 usrFrame);
	UFUNCTION(BlueprintCallable, Category = "3dBBoxGen")
		void generated3d(int32 frameNum, TArray<FVector> vehiclesBoxLocations, TArray<FRotator> vehiclesBoxRotations, FVector sensorLocation, FRotator sensorRotation, TArray<FVector> vehiclesBoxExtends, TArray<FVector> vehiclesLocations);
	UFUNCTION(BlueprintCallable, Category = "2dBBoxGen")
		void generate2d(int32 usrFrames);
};

