// Fill out your copyright notice in the Description page of Project Settings.


#include "capture2dBox.h"

// Sets default values
Acapture2dBox::Acapture2dBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Acapture2dBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Acapture2dBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


TArray<TArray<FVector2D>>  Acapture2dBox::ConvertBoundingBoxes(const TArray<TArray<FVector2D>>& boundingBoxes, int32 lineLength)
{
    TArray<TArray<FVector2D>> bb4Data;
    bb4Data.SetNum(lineLength);

    int32 k = 0;
    for (int32 i = 0; i < lineLength; ++i)
    {
        TArray<float> pointsArrayX;
        TArray<float> pointsArrayY;

        for (int32 j = 0; j < 8; ++j)
        {
            pointsArrayX.Add(boundingBoxes[i][j].X);
            pointsArrayY.Add(boundingBoxes[i][j].Y);
        }

        float maxX = pointsArrayX[0];
        float minX = pointsArrayX[0];
        float maxY = pointsArrayY[0];
        float minY = pointsArrayY[0];

        for (int32 j = 1; j < 8; ++j)
        {
            maxX = FMath::Max(maxX, pointsArrayX[j]);
            minX = FMath::Min(minX, pointsArrayX[j]);
            maxY = FMath::Max(maxY, pointsArrayY[j]);
            minY = FMath::Min(minY, pointsArrayY[j]);
        }

        bb4Data[i].Add(FVector2D(minX, minY));
        bb4Data[i].Add(FVector2D(maxX, minY));
        bb4Data[i].Add(FVector2D(maxX, maxY));
        bb4Data[i].Add(FVector2D(minX, maxY));
    }

    for (int32 i = 0; i < lineLength; i++)
    {

        FString TupleStr;
        for (const FVector2D& Coord : bb4Data[i])
        {
            TupleStr += "(" + FString::FromInt(Coord.X) + ", " + FString::FromInt(Coord.Y) + "), ";
        }
        UE_LOG(LogTemp, Warning, TEXT("Tuple4: %s"), *TupleStr);
    }

    return bb4Data;


}
void  Acapture2dBox::objectArea(TArray<TArray<FVector2D>> data, TArray<FColor> vehiclesColors)
{


    TArray<FColor> VehiclesColors = vehiclesColors;
    int32 CarIndex = 0;

    TArray<FColor> emptyRow;
    areaInfo.Empty();
    //segInfo.Empty();
    //rgbInfo.Empty();
    for (int32 i = 0; i < viewWidth; i++)                                                // i made changes here viewHeight was here 
    {
        emptyRow.Add(FColor::Black);
    }

    for (int32 i = 0; i < viewHeight; i++)                                               // i made changes here viewWeidth  was here 
    {
        areaInfo.Add(emptyRow);
        segInfo.Add(emptyRow);
        rgbInfo.Add(emptyRow);
    }

    UE_LOG(LogTemp, Warning, TEXT("<---------------------image Dim------------------------>"));
    UE_LOG(LogTemp, Warning, TEXT("areaInfo Height: %d"), areaInfo.Num());
    UE_LOG(LogTemp, Warning, TEXT("areaInfo width: %d"), areaInfo[0].Num());
    UE_LOG(LogTemp, Warning, TEXT("total cars in the scene: %d"), data.Num());
    UE_LOG(LogTemp, Warning, TEXT("<------------------------------------------------------------>"));

    UE_LOG(LogTemp, Warning, TEXT("<---------------------image Dim ------------------------>"));
    UE_LOG(LogTemp, Warning, TEXT("segInfo Height: %d"), segInfo.Num());
    UE_LOG(LogTemp, Warning, TEXT("segInfo width: %d"), segInfo[0].Num());
    UE_LOG(LogTemp, Warning, TEXT("total cars in the scene: %d"), data.Num());
    UE_LOG(LogTemp, Warning, TEXT("<------------------------------------------------------------>"));


    UE_LOG(LogTemp, Warning, TEXT("<---------------------image Dim ------------------------>"));
    UE_LOG(LogTemp, Warning, TEXT("rgbInfo Height: %d"), rgbInfo.Num());
    UE_LOG(LogTemp, Warning, TEXT("rgbInfo width: %d"), rgbInfo[0].Num());
    UE_LOG(LogTemp, Warning, TEXT("total cars in the scene: %d"), data.Num());
    UE_LOG(LogTemp, Warning, TEXT("<------------------------------------------------------------>"));
    for (auto& vehicleArea : data)
    {
        UE_LOG(LogTemp, Warning, TEXT("CAR INDEX !!!!!!!!!! %d"), CarIndex);

        TArray<float> arrayX;
        TArray<float> arrayY;
        FColor VehicleColor = VehiclesColors[CarIndex];
        CarIndex++;

        for (int32 i = 0; i < 4; i++)
        {
            arrayX.Add(vehicleArea[i].X);
        }

        for (int32 j = 0; j < 4; j++)
        {
            arrayY.Add(vehicleArea[j].Y);
        }

        float MinX = arrayX[0];
        float MaxX = arrayX[0];
        float MinY = arrayY[0];
        float MaxY = arrayY[0];

        for (int32 i = 1; i < 4; i++)
        {
            MinX = FMath::Min(MinX, arrayX[i]);
            MaxX = FMath::Max(MaxX, arrayX[i]);
            MinY = FMath::Min(MinY, arrayY[i]);
            MaxY = FMath::Max(MaxY, arrayY[i]);
        }

        TArray<float> array = { MinX, MaxX, MinY, MaxY };

    }

}

bool  Acapture2dBox::Filtering(TArray<float> array, FColor color)
{
    UE_LOG(LogTemp, Warning, TEXT("Inside filtering function"));
    for (int32 y = static_cast<int32>(array[2]); y < static_cast<int32>(array[3]); y++)
    {
        for (int32 x = static_cast<int32>(array[0]); x < static_cast<int32>(array[1]); x++)
        {
            if (segInfo[y][x].B == color.B && segInfo[y][x].G == color.G && segInfo[y][x].R == color.R)
            {
                UE_LOG(LogTemp, Warning, TEXT("Color value of segmentation to compare at index 2[-_-!]: %d"), segInfo[y][x].B);
                UE_LOG(LogTemp, Warning, TEXT("Color value of segmentation to compare at index 1[-_-!]: %d"), segInfo[y][x].G);
                UE_LOG(LogTemp, Warning, TEXT("Color value of segmentation to compare at index 0[-_-!]: %d"), segInfo[y][x].R);
                UE_LOG(LogTemp, Warning, TEXT("Color that is being compared at index 0: %d"), color.R);
                UE_LOG(LogTemp, Warning, TEXT("Color that is being compared at index 1: %d"), color.G);
                UE_LOG(LogTemp, Warning, TEXT("Color that is being compared at index 2: %d"), color.B);
                return true;
            }
        }
    }
    return false;
}
bool  Acapture2dBox::preOccludedObjectsExcluded(TArray<float> array, TArray<TArray<FColor>> areaImage, FColor color)
{
    float top_left = areaImage[array[2] - 1][array[0] - 1].R;
    float top_right = areaImage[array[2]][array[1] + 1].R;
    float bottom_left = areaImage[array[3] + 1][array[1] - 1].R;
    float bottom_right = areaImage[array[3] + 1][array[0] + 1].R;

    if (top_left == color.R && top_right == color.R && bottom_left == color.R && bottom_right == color.R)
    {
        return false;
    }

    return true;
}
bool  Acapture2dBox::smallObjectsExcluded(TArray<float> array, float bb_min)
{
    float diff_x = array[1] - array[0];
    float diff_y = array[3] - array[2];
    if (diff_x > bb_min && diff_y > bb_min)
    {
        return true;
    }
    return false;
}
bool  Acapture2dBox::postOccludedObjectsExcluded(TArray<float> array, FColor color)
{
    //TArray<TArray<FColor>>& segInfo = GetSegInfo(); // Assuming segInfo is a globally accessible variable

    float top_left = segInfo[array[2] + 1][array[0] + 1].R;
    float top_right = segInfo[array[2] + 1][array[1] - 1].R;
    float bottom_left = segInfo[array[3] - 1][array[0] + 1].R;
    float bottom_right = segInfo[array[3] - 1][array[1] - 1].R;

    if (top_left == color.R && top_right == color.R && bottom_left == color.R && bottom_right == color.R)
    {
        return false;
    }

    return true;
}
int32  Acapture2dBox::fittingX(int32 x1, int32 x2, int32 rangeMin, int32 rangeMax, FColor color)
{
    // global segInfo; // Assuming segInfo is globally declared

    bool state = false;
    int32 caliPoint = 0;

    if (x1 < x2)
    {
        for (int32 searchPoint = x1; searchPoint < x2; searchPoint++)
        {
            for (int32 rangeOfPoints = rangeMin; rangeOfPoints < rangeMax; rangeOfPoints++)
            {
                if (segInfo[rangeOfPoints][searchPoint].B == color.B && segInfo[rangeOfPoints][searchPoint].G == color.G && segInfo[rangeOfPoints][searchPoint].R == color.R)
                {
                    UE_LOG(LogTemp, Warning, TEXT("*****--->Fitting x********"));
                    UE_LOG(LogTemp, Warning, TEXT("value to compare: %d"), segInfo[rangeOfPoints][searchPoint].B);
                    UE_LOG(LogTemp, Warning, TEXT("vehicle color value: %d"), color.B);
                    caliPoint = searchPoint;
                    state = true;
                    break;
                }
            }

            if (state == true)
            {
                break;
            }
        }
    }
    else
    {
        for (int32 searchPoint = x1; searchPoint > x2; searchPoint--)
        {
            for (int32 rangeOfPoints = rangeMin; rangeOfPoints < rangeMax; rangeOfPoints++)
            {
                if (segInfo[rangeOfPoints][searchPoint].B == color.B && segInfo[rangeOfPoints][searchPoint].G == color.G && segInfo[rangeOfPoints][searchPoint].R == color.R)
                {
                    UE_LOG(LogTemp, Warning, TEXT("*****--->Fitting x********"));
                    UE_LOG(LogTemp, Warning, TEXT("value to compare: %d"), segInfo[rangeOfPoints][searchPoint].B);
                    UE_LOG(LogTemp, Warning, TEXT("vehicle color value: %d"), color.B);
                    caliPoint = searchPoint;
                    state = true;
                    break;
                }
            }

            if (state == true)
            {
                break;
            }
        }
    }

    return caliPoint;
}
int32  Acapture2dBox::fittingY(int32 y1, int32 y2, int32 rangeMin, int32 rangeMax, FColor color)
{
    bool state = false;
    int32 caliPoint = 0;

    if (y1 < y2)
    {
        for (int32 searchPoint = y1; searchPoint < y2; searchPoint++)
        {
            for (int32 rangeOfPoints = rangeMin; rangeOfPoints < rangeMax; rangeOfPoints++)
            {
                if (segInfo[searchPoint][rangeOfPoints].R == color.R && segInfo[searchPoint][rangeOfPoints].G == color.G && segInfo[searchPoint][rangeOfPoints].B == color.B)
                {
                    caliPoint = searchPoint;
                    state = true;
                    break;
                }
            }
            if (state)
            {
                break;
            }
        }
    }
    else
    {
        for (int32 searchPoint = y1; searchPoint > y2; searchPoint--)
        {
            for (int32 rangeOfPoints = rangeMin; rangeOfPoints < rangeMax; rangeOfPoints++)
            {
                if (segInfo[searchPoint][rangeOfPoints].R == color.R)
                {
                    caliPoint = searchPoint;
                    state = true;
                    break;
                }
            }
            if (state)
            {
                break;
            }
        }
    }

    return caliPoint;
}

void  Acapture2dBox::processing(TArray<TArray<FColor>> img, TArray<TArray<FVector2D>> vData, int32 index, TArray<FColor> vehiclesColors)
{

    //    TArray<TArray<FColor>> segInfo;
    //    TArray<TArray<FColor>> areaInfo;
    //    TArray<FColor> vehiclesColors;
   
    FColor vehicleColor;
    int32 vehicleClass = 0;
    int32 walkerClass = 1;
    int32 carIndex = 0;
    FString line;
    //vehiclesColors = vehiclesColors;

    objectArea(vData, vehiclesColors);
    
    FString filePath = mainDir + "custom_data/image" + FString::FromInt(index) + ".txt";
    //FString finalFilePath = filePath;
    //TCHAR* filePathChar = finalFilePath.GetCharArray().GetData();
    //FILE* file = nullptr;
    IPlatformFile& file = FPlatformFileManager::Get().GetPlatformFile();
    //_wfopen_s(&file, filePathChar, _T("w"));

    // Vehicle
    for (int32 i = 0; i < vData.Num(); ++i)
    {
        vehicleColor = vehiclesColors[carIndex];
        carIndex++;
        TArray<float> arrayX;
        TArray<float> arrayY;
        for (int32 j = 0; j < 4; ++j)
        {
            arrayX.Add(vData[i][j].X);
            arrayY.Add(vData[i][j].Y);
        }

        for (int32 j = 0; j < 4; ++j)
        {
            if (arrayX[j] <= 0)
            {
                arrayX[j] = 1;
            }
            else if (arrayX[j] >= viewWidth - 1)
            {
                arrayX[j] = viewWidth - 2;
            }
        }

        for (int32 j = 0; j < 4; ++j)
        {
            if (arrayY[j] <= 0)
            {
                arrayY[j] = 1;
            }
            else if (arrayY[j] >= viewHeight - 1)
            {
                arrayY[j] = viewHeight - 2;
            }
        }

        float minX = FMath::Min(arrayX);
        float maxX = FMath::Max(arrayX);
        float minY = FMath::Min(arrayY);
        float maxY = FMath::Max(arrayY);
        TArray<float> vBbArray = { minX, maxX, minY, maxY };
        float centerX = FMath::FloorToFloat((minX + maxX) / 2);
        float centerY = FMath::FloorToFloat((minY + maxY) / 2);
        bool filterFlag;
        filterFlag = Filtering(vBbArray, vehicleColor);

        FString ValueString = filterFlag ? TEXT("true") : TEXT("false");
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, ValueString);
        UE_LOG(LogTemp, Warning, TEXT("iltering-------------->: %s"), Filtering(vBbArray, vehicleColor) ? TEXT("true") : TEXT("false"));
        //UE_LOG(LogTemp, Warning, TEXT("filtering-------------->"), Filtering(vBbArray, vehicleColor));
        UE_LOG(LogTemp, Warning, TEXT("<-----------Start-------------->"));
        for (float val : vBbArray)
        {
            UE_LOG(LogTemp, Warning, TEXT("vBbArray-------------->%f"), val);


        }
        UE_LOG(LogTemp, Warning, TEXT("<-----------END-------------->"));
        UE_LOG(LogTemp, Warning, TEXT("pre_occluded_objects_excluded-------------->"), preOccludedObjectsExcluded(vBbArray, areaInfo, vehicleColor));
        if (Filtering(vBbArray, vehicleColor) && preOccludedObjectsExcluded(vBbArray, areaInfo, vehicleColor))
        {
            float caliMinX = fittingX(minX, maxX, minY, maxY, vehicleColor);
            float caliMaxX = fittingX(maxX, minX, minY, maxY, vehicleColor);
            float caliMinY = fittingY(minY, maxY, minX, maxX, vehicleColor);
            float caliMaxY = fittingY(maxY, minY, minX, maxX, vehicleColor);
            TArray<float> vCaliArray = { caliMinX, caliMaxX, caliMinY, caliMaxY };

            if (smallObjectsExcluded(vCaliArray, 10) && postOccludedObjectsExcluded(vCaliArray, vehicleColor))
            {
                float darknetX = FMath::FloorToFloat((caliMinX + caliMaxX) / 2) / viewWidth;
                float darknetY = FMath::FloorToFloat((caliMinY + caliMaxY) / 2) / viewHeight;
                float darknetWidth = FMath::FloorToFloat(caliMaxX - caliMinX) / viewWidth;
                float darknetHeight = FMath::FloorToFloat(caliMaxY - caliMinY) / viewHeight;

                line = line+FString::Printf(TEXT("%d %0.6f %0.6f %0.6f %0.6f\n"), vehicleClass, darknetX, darknetY, darknetWidth, darknetHeight);
                //fwrite(TCHAR_TO_UTF8(*line), 1, line.Len(), file);

            }
        }
    }
    if (file.CreateDirectory(*filePath))
    {
        FString Myfile = filePath;
        FFileHelper::SaveStringToFile(line, *Myfile);

    }
    //fclose(file);


}
TArray<FColor>  Acapture2dBox::ReadColors(int32 frameNum)
{

    FString fileName = "frame" + FString::FromInt(frameNum);
    TArray<FColor> colorList;
    FString filePath = colorFolder + fileName + ".txt";
    FString fileContent;


    if (FFileHelper::LoadFileToString(fileContent, *filePath))
    {
        TArray<FString> lines;
        fileContent.ParseIntoArrayLines(lines);

        for (const FString& line : lines)
        {
            // Remove parentheses and whitespace from the line
            FString cleanedLine = line.Replace(TEXT("("), TEXT("")).Replace(TEXT(")"), TEXT(""));
            //cleanedLine = FStringTrimHelpers::TrimStartAndEnd(cleanedLine);
            cleanedLine = cleanedLine.TrimStartAndEnd();
            // Split the line by commas to get the individual color values
            TArray<FString> colorValues;
            cleanedLine.ParseIntoArray(colorValues, TEXT(","));

            if (colorValues.Num() == 3)
            {
                uint8 red = FCString::Atoi(*colorValues[0]);
                uint8 green = FCString::Atoi(*colorValues[1]);
                uint8 blue = FCString::Atoi(*colorValues[2]);

                FColor color(red, green, blue);
                colorList.Add(color);

                // Do something with the color
                //UE_LOG(LogTemp, Warning, TEXT("Color: R=%d, G=%d, B=%d"), red, green, blue);
            }
        }
    }

    FString str;
    for (FColor& color : colorList)
    {
        str += "(" + color.ToString() + "), ";
    }
    UE_LOG(LogTemp, Warning, TEXT("color: %s"), *str);

    return colorList;
}
TArray<FVector4>  Acapture2dBox::CreateBBPoints(FVector vehicleBoxExtend)
{
    TArray<FVector4> cords;
    FVector extent = vehicleBoxExtend;

    cords.Add(FVector4(extent.X, extent.Y, -extent.Z, 1));
    cords.Add(FVector4(-extent.X, extent.Y, -extent.Z, 1));
    cords.Add(FVector4(-extent.X, -extent.Y, -extent.Z, 1));
    cords.Add(FVector4(extent.X, -extent.Y, -extent.Z, 1));
    cords.Add(FVector4(extent.X, extent.Y, extent.Z, 1));
    cords.Add(FVector4(-extent.X, extent.Y, extent.Z, 1));
    cords.Add(FVector4(-extent.X, -extent.Y, extent.Z, 1));
    cords.Add(FVector4(extent.X, -extent.Y, extent.Z, 1));

    //UE_LOG(LogTemp, Warning, TEXT("<----------CORDS----------------------->"));
    //for (FVector4& i :cords)
    //{

    //    UE_LOG(LogTemp, Warning, TEXT("CORDS: X=%f, Y=%f, Z=%f,W=%f"), i.X, i.Y, i.Z,i.W);
    //}
    //UE_LOG(LogTemp, Warning, TEXT("<------------------------------------------------>"));
    return cords;
}
FMatrix  Acapture2dBox::GetMatrix(const FTransform& transform)
{
    FRotator rotation = transform.Rotator();
    FVector location = transform.GetLocation();

    float rotationYaw = FMath::DegreesToRadians(rotation.Yaw);
    float rotationRoll = FMath::DegreesToRadians(rotation.Roll);
    float rotationPitch = FMath::DegreesToRadians(rotation.Pitch);

    float locationX = location.X;
    float locationY = location.Y;
    float locationZ = location.Z;

    float c_y = FMath::Cos(rotationYaw);
    float s_y = FMath::Sin(rotationYaw);
    float c_r = FMath::Cos(rotationRoll);
    float s_r = FMath::Sin(rotationRoll);
    float c_p = FMath::Cos(rotationPitch);
    float s_p = FMath::Sin(rotationPitch);
    //UE_LOG(LogTemp, Warning, TEXT("<-----------------GetMatrix Function------------------------>"));
    ////for (FVector& i : worldCords)
    ////{
    ////    UE_LOG(LogTemp, Warning, TEXT("CORDS: X=%f, Y=%f, Z=%f"), i.X, i.Y, i.Z);

    ////}
    //UE_LOG(LogTemp, Warning, TEXT("rotationYaw in deg=%f"), rotation.Yaw);
    //UE_LOG(LogTemp, Warning, TEXT("rotationRoll in deg=%f"), rotation.Roll);
    //UE_LOG(LogTemp, Warning, TEXT("rotationPitch in deg=%f"), rotation.Pitch);
    //UE_LOG(LogTemp, Warning, TEXT("rotationYaw in Rad=%f"), rotationYaw);
    //UE_LOG(LogTemp, Warning, TEXT("rotationRoll in Rad=%f"), rotationRoll);
    //UE_LOG(LogTemp, Warning, TEXT("rotationPitch in Rad=%f"), rotationPitch);
    //UE_LOG(LogTemp, Warning, TEXT("locationX=%f"), locationX);
    //UE_LOG(LogTemp, Warning, TEXT("locationY=%f"), locationY);
    //UE_LOG(LogTemp, Warning, TEXT("locationZ=%f"), locationZ);


    //UE_LOG(LogTemp, Warning, TEXT("c_y=%f"), c_y);
    //UE_LOG(LogTemp, Warning, TEXT("s_y=%f"), s_y);
    //UE_LOG(LogTemp, Warning, TEXT("s_r=%f"), s_r);
    //UE_LOG(LogTemp, Warning, TEXT("c_p=%f"), c_p);
    //UE_LOG(LogTemp, Warning, TEXT("s_p=%f"), s_p);

    //UE_LOG(LogTemp, Warning, TEXT("<------------------------------------------------>"));
    FMatrix matrix = FMatrix::Identity;
    matrix.M[0][3] = locationX;
    matrix.M[1][3] = locationY;
    matrix.M[2][3] = locationZ;
    matrix.M[0][0] = c_p * c_y;
    matrix.M[0][1] = c_y * s_p * s_r - s_y * c_r;
    matrix.M[0][2] = -c_y * s_p * c_r - s_y * s_r;
    matrix.M[1][0] = s_y * c_p;
    matrix.M[1][1] = s_y * s_p * s_r + c_y * c_r;
    matrix.M[1][2] = -s_y * s_p * c_r + c_y * s_r;
    matrix.M[2][0] = s_p;
    matrix.M[2][1] = -c_p * s_r;
    matrix.M[2][2] = c_p * c_r;

    return matrix;
}
TArray<TArray<float>>  Acapture2dBox::VehicleToWorld(TArray<FVector4> cords, FVector vehicleBoxLocation, FRotator vehicleBoxRotation, FVector vehicleLocation)
{
    //FTransform bbTransform(vehicleBoxLocation, FRotator::ZeroRotator);
    FTransform bbTransform(FRotator(0, 0, 0), vehicleBoxLocation);


    //bbTransform.SetLocation(vehicleBoxLocation);
    //bbTransform.SetRotation(vehicleBoxRotation.Quaternion());

    //FTransform vehicleTransform(vehicleLocation, vehicleBoxRotation);
    FTransform vehicleTransform(vehicleBoxRotation, vehicleLocation);
    //FTransform vehicleTransform;
    //vehicleTransform.SetLocation(vehicleLocation);
    //vehicleTransform.SetRotation(vehicleBoxRotation.Quaternion());
    FMatrix bbVehicleMatrix = GetMatrix(bbTransform);
    FMatrix vehicleWorldMatrix = GetMatrix(vehicleTransform);

    FMatrix bbWorldMatrix = vehicleWorldMatrix * bbVehicleMatrix;


    TArray<TArray<float>> worldCords; // Declare a nested TArray to store world coordinates

    TArray<TArray<float>> transformedCords;

    // Resize the transformedCords array to 4x8
    transformedCords.SetNum(4);
    for (int32 i = 0; i < 4; i++)
    {
        transformedCords[i].SetNum(8);
    }

    // Transfer the data from cords to transformedCords
    for (int32 i = 0; i < cords.Num(); i++)
    {
        FVector4 cord = cords[i];
        transformedCords[0][i] = cord.X;
        transformedCords[1][i] = cord.Y;
        transformedCords[2][i] = cord.Z;
        transformedCords[3][i] = cord.W;
    }


    // Convert bbWorldMatrix to TArray<TArray<float>>
    TArray<TArray<float>> bbWorldMatrixArray;
    for (int32 i = 0; i < 4; i++)
    {
        TArray<float> row;
        for (int32 j = 0; j < 4; j++)
        {
            row.Add(bbWorldMatrix.M[i][j]);
        }
        bbWorldMatrixArray.Add(row);
    }

    // Perform the dot product
    //TArray<TArray<float>> result;
    for (int32 i = 0; i < 4; i++)
    {
        TArray<float> rowResult;
        for (int32 j = 0; j < 8; j++)
        {
            float dotProduct = 0.0f;
            for (int32 k = 0; k < 4; k++)
            {
                dotProduct += bbWorldMatrixArray[i][k] * transformedCords[k][j];
            }
            rowResult.Add(dotProduct);
        }
        worldCords.Add(rowResult);
    }

    //UE_LOG(LogTemp, Warning, TEXT("<-----------------bbWorldMatrix------------------------>"));
    //for (const TArray<float>& row : worldCords)
    //{
    //    UE_LOG(LogTemp, Warning, TEXT("["));
    //    for (float element : row)
    //    {
    //        UE_LOG(LogTemp, Warning, TEXT("%f"), element);
    //    }
    //    UE_LOG(LogTemp, Warning, TEXT("]"));
    //}
    //UE_LOG(LogTemp, Warning, TEXT("<-----------------bbWorldMatrix------------------------>"));



    //UE_LOG(LogTemp, Warning, TEXT("<------------------------------------------------>"));
    return worldCords;
}
TArray<TArray<float>>  Acapture2dBox::WorldToSensor(TArray<TArray<float>> cords, FVector sensorLocation, FRotator sensorRotation)
{
    FTransform sensorTransform(sensorRotation, sensorLocation);
    //FTransform sensorTransform(sensorLocation, sensorRotation);
    //FTransform sensorTransform;
    //sensorTransform.SetLocation(sensorLocation);
    //sensorTransform.SetRotation(sensorRotation.Quaternion());
    FMatrix sensorWorldMatrix = GetMatrix(sensorTransform);
    FMatrix worldSensorMatrix = sensorWorldMatrix.Inverse();
    TArray<TArray<float>> sensorCords;

    // Convert bbWorldMatrix to TArray<TArray<float>>
    TArray<TArray<float>> worldSensorMatrixArray;
    for (int32 i = 0; i < 4; i++)
    {
        TArray<float> row;
        for (int32 j = 0; j < 4; j++)
        {
            row.Add(worldSensorMatrix.M[i][j]);
        }
        worldSensorMatrixArray.Add(row);
    }

    for (int32 i = 0; i < 4; i++)
    {
        TArray<float> rowResult;
        for (int32 j = 0; j < 8; j++)
        {
            float dotProduct = 0.0f;
            for (int32 k = 0; k < 4; k++)
            {
                dotProduct += worldSensorMatrixArray[i][k] * cords[k][j];
            }
            rowResult.Add(dotProduct);
        }
        sensorCords.Add(rowResult);
    }

    //UE_LOG(LogTemp, Warning, TEXT("<-----------------bbWorldMatrix------------------------>"));
    //for (const TArray<float>& row : sensorCords)
    //{
    //    UE_LOG(LogTemp, Warning, TEXT("["));
    //    for (float element : row)
    //    {
    //        UE_LOG(LogTemp, Warning, TEXT("%f"), element);
    //    }
    //    UE_LOG(LogTemp, Warning, TEXT("]"));
    //}
    //UE_LOG(LogTemp, Warning, TEXT("<-----------------bbWorldMatrix------------------------>"));

    return sensorCords;
}
void  Acapture2dBox::SetupCamCalib()
{
    // idientity 3x3
    CamCalib.M[0][0] = 1;
    CamCalib.M[1][1] = 1;
    CamCalib.M[2][2] = 1;

    float HalfViewWidth = viewWidth / 2.0f;
    float HalfViewHeight = viewHeight / 2.0f;
    float FOVRadians = FMath::DegreesToRadians(viewFOV);
    float TanHalfFOV = FMath::Tan(FOVRadians / 2.0f);

    CamCalib.M[0][2] = HalfViewWidth;
    CamCalib.M[1][2] = HalfViewHeight;
    CamCalib.M[0][0] = CamCalib.M[1][1] = HalfViewWidth / TanHalfFOV;




    // Print the values of the CamCalib matrix
    UE_LOG(LogTemp, Warning, TEXT("CamCalib values:"));
    UE_LOG(LogTemp, Warning, TEXT("[%f, %f, %f]"), CamCalib.M[0][0], CamCalib.M[0][1], CamCalib.M[0][2]);
    UE_LOG(LogTemp, Warning, TEXT("[%f, %f, %f]"), CamCalib.M[1][0], CamCalib.M[1][1], CamCalib.M[1][2]);
    UE_LOG(LogTemp, Warning, TEXT("[%f, %f, %f]"), CamCalib.M[2][0], CamCalib.M[2][1], CamCalib.M[2][2]);

}
TArray<TArray<float>>  Acapture2dBox::VehicleToSensor(TArray<FVector4> cords, FVector vehicleBoxLocation, FRotator vehicleBoxRotation, FVector sensorLocation, FRotator sensorRotation, FVector vehicleLocation)
{
    // Convert vehicle coordinates to world coordinates
    TArray<TArray<float>> worldCords = VehicleToWorld(cords, vehicleBoxLocation, vehicleBoxRotation, vehicleLocation);

    // Convert world coordinates to sensor coordinates
    TArray<TArray<float>> sensorCords = WorldToSensor(worldCords, sensorLocation, sensorRotation);

    //UE_LOG(LogTemp, Warning, TEXT("<-----------------sensorCords------------------------>"));
    //for (FVector& i : sensorCords)
    //{
    //    UE_LOG(LogTemp, Warning, TEXT("CORDS: X=%f, Y=%f, Z=%f"), i.X, i.Y, i.Z);

    //}
    //UE_LOG(LogTemp, Warning, TEXT("<------------------------------------------------>"));

    return sensorCords;
}
TArray<TArray<float>>  Acapture2dBox::GetBoundingBox(FVector vehicleBoxLocation, FRotator vehicleBoxRotation, FVector sensorLocation, FRotator sensorRotation, FVector vehicleBoxExtend, FVector vehicleLocation)
{



    TArray<FVector4> bbCords = CreateBBPoints(vehicleBoxExtend);
    TArray<TArray<float>> cordsXYZW = VehicleToSensor(bbCords, vehicleBoxLocation, vehicleBoxRotation, sensorLocation, sensorRotation, vehicleLocation);
    cordsXYZW.RemoveAt(cordsXYZW.Num() - 1);
    TArray<TArray<float>> cordsXYZ = cordsXYZW;

    TArray<TArray<float>> cords_y_minus_z_x;
    TArray<TArray<float>> bbox;
    TArray<TArray<float>> bboxTrans;
    TArray<TArray<float>> camera_bbox;
    bboxTrans.SetNum(8);
    //bbox.SetNum(8);
    cords_y_minus_z_x.SetNum(3);
    TArray<float> tempArr;
    tempArr = cordsXYZ[2];
    for (float& element : tempArr)
    {
        element *= -1;

    }
    cords_y_minus_z_x[0] = cordsXYZ[1];
    cords_y_minus_z_x[1] = tempArr;
    cords_y_minus_z_x[2] = cordsXYZ[0];


    for (int32 i = 0; i < 3; i++)
    {
        TArray<float> rowResult;
        for (int32 j = 0; j < 8; j++)
        {
            float dotProduct = 0.0f;
            for (int32 k = 0; k < 3; k++)
            {
                dotProduct += CamCalib.M[i][k] * cords_y_minus_z_x[k][j];
            }
            rowResult.Add(dotProduct);
        }
        bbox.Add(rowResult);
    }


    bbox[0] = divArr(bbox[0], bbox[2]);
    bbox[1] = divArr(bbox[1], bbox[2]);
    bbox[2] = bbox[2];
    bboxTrans = transArr(bbox);


    //UE_LOG(LogTemp, Warning, TEXT("<-----------------cordsXYZ------------------------>"));
    //for (const TArray<float>& row : bboxTrans)
    //{
    //    UE_LOG(LogTemp, Warning, TEXT("["));
    //    for (float element : row)
    //    {
    //        UE_LOG(LogTemp, Warning, TEXT("%f"), element);
    //    }
    //    UE_LOG(LogTemp, Warning, TEXT("]"));
    //}
    //UE_LOG(LogTemp, Warning, TEXT("<-----------------cordsXYZ------------------------>"));




    return bboxTrans;
}
TArray<TArray<TArray<float>>>  Acapture2dBox::GetBoundingBoxes(TArray<FVector> vehiclesBoxLocations, TArray<FRotator> vehiclesBoxRotations, FVector sensorLocation, FRotator sensorRotation, TArray<FVector> vehiclesBoxExtends, TArray<FVector> vehiclesLocations)
{
    TArray<TArray<TArray<float>>> boundingBoxes;
    boundingBoxes.SetNum(vehiclesBoxLocations.Num());
    TArray<int32> badBoxes;

    for (int32 i = 0; i < vehiclesBoxLocations.Num(); i++)
    {
        FVector vehicleBoxLocation = vehiclesBoxLocations[i];
        FRotator vehicleBoxRotation = vehiclesBoxRotations[i];
        FVector vehicleLocation = vehiclesLocations[i];
        TArray<TArray<float>> boundingBox = GetBoundingBox(vehicleBoxLocation, vehicleBoxRotation, sensorLocation, sensorRotation, vehiclesBoxExtends[i], vehicleLocation);
        boundingBoxes[i] = boundingBox;


        //// Check if the bounding box is behind the camera
        //bool isBadBox = false;
        //for (const FVector& point : boundingBox)
        //{
        //    if (point.Z <= 0)
        //    {
        //        isBadBox = true;
        //        break;
        //    }
        //}

        //if (isBadBox)
        //{
        //    badBoxes.Add(i);
        //}
    }

    //// Filter out the bad boxes
    //for (int32 i = badBoxes.Num() - 1; i >= 0; i--)
    //{
    //    int32 index = badBoxes[i];
    //    boundingBoxes.RemoveAt(index);
    //}

    return boundingBoxes;
}

void  Acapture2dBox::DrawBoundingBoxes(const TArray < TArray<TArray<float>> >& BoundingBoxes, int32 FrameNum)
{
    // Declare global variables
    static bool bVehicleBBoxRecord = true;
    static int32 Count = 0;
    Count = FrameNum;

    // Create and set up bb_surface
    // UTexture2D* BBSurface = CreateBBTexture(VIEW_WIDTH, VIEW_HEIGHT);
    // FColor ClearColor = FColor(0, 0, 0, 0);
    // ClearTexture(BBSurface, ClearColor);

    if (bVehicleBBoxRecord)
    {
        FString Filename = mainDir + "VehicleBBox/bbox" + FString::FromInt(Count) + ".txt";
        FString FileContent;
        for (const TArray<TArray<float>>& BBox : BoundingBoxes)
        {
            FString Line;
            for (const TArray<float> &Points : BBox)
            {
                if (Line == "")
                {
                    Line += FString::Printf(TEXT("(%d,%d)"), FMath::RoundToInt(Points[0]), FMath::RoundToInt(Points[1]));

                }
                else
                {
                    Line += FString::Printf(TEXT(",(%d,%d)"), FMath::RoundToInt(Points[0]), FMath::RoundToInt(Points[1]));
                }
                //Line += FString::Printf(TEXT("(%d, %d) "), static_cast<int32>(Point.X), static_cast<int32>(Point.Y));
            }
            FileContent += "[" + Line + TEXT("]\n");
        }
        FFileHelper::SaveStringToFile(FileContent, *Filename);
    }

    //if (bVehicleBBoxRecord)
    //{
    //    bVehicleBBoxRecord = false;
    //}
}
void  Acapture2dBox::generated3d(int32 frameNum, TArray<FVector> vehiclesBoxLocations, TArray<FRotator> vehiclesBoxRotations, FVector sensorLocation, FRotator sensorRotation, TArray<FVector> vehiclesBoxExtends, TArray<FVector> vehiclesLocations)
{
    SetupCamCalib();

    UE_LOG(LogTemp, Warning, TEXT("---------------------------TransForms------------------------"));
    UE_LOG(LogTemp, Warning, TEXT("FrameNum:%d"), frameNum);
    UE_LOG(LogTemp, Warning, TEXT("<-------vehiclesBoxLocations-------->"));
    UE_LOG(LogTemp, Warning, TEXT("vehiclesBoxLocationsX:%f"), vehiclesBoxLocations[0].X);
    UE_LOG(LogTemp, Warning, TEXT("vehiclesBoxLocationsY:%f"), vehiclesBoxLocations[0].Y);
    UE_LOG(LogTemp, Warning, TEXT("vehiclesBoxLocationsz:%f"), vehiclesBoxLocations[0].Z);
    UE_LOG(LogTemp, Warning, TEXT("<-------vehiclesBoxLocations-------->"));

    UE_LOG(LogTemp, Warning, TEXT("<-------vehiclesBoxRotations-------->"));
    UE_LOG(LogTemp, Warning, TEXT("Pitch:%f"), vehiclesBoxRotations[0].Pitch);
    UE_LOG(LogTemp, Warning, TEXT("Yaw:%f"), vehiclesBoxRotations[0].Yaw);
    UE_LOG(LogTemp, Warning, TEXT("Roll:%f"), vehiclesBoxRotations[0].Roll);
    UE_LOG(LogTemp, Warning, TEXT("<-------vehiclesBoxRotations-------->"));

    UE_LOG(LogTemp, Warning, TEXT("<-------sensorRotation-------->"));
    UE_LOG(LogTemp, Warning, TEXT("X:%f"), sensorRotation.Pitch);
    UE_LOG(LogTemp, Warning, TEXT("Y:%f"), sensorRotation.Yaw);
    UE_LOG(LogTemp, Warning, TEXT("Z:%f"), sensorRotation.Roll);
    UE_LOG(LogTemp, Warning, TEXT("<-------sensorRotation-------->"));

    UE_LOG(LogTemp, Warning, TEXT("<-------sensorLocation-------->"));
    UE_LOG(LogTemp, Warning, TEXT("X:%f"), sensorLocation.X);
    UE_LOG(LogTemp, Warning, TEXT("Y:%f"), sensorLocation.Y);
    UE_LOG(LogTemp, Warning, TEXT("Z:%f"), sensorLocation.Z);
    UE_LOG(LogTemp, Warning, TEXT("<-------sensorLocation-------->"));

    UE_LOG(LogTemp, Warning, TEXT("<-------vehiclesBoxExtends-------->"));
    UE_LOG(LogTemp, Warning, TEXT("X:%f"), vehiclesBoxExtends[0].X);
    UE_LOG(LogTemp, Warning, TEXT("Y:%f"), vehiclesBoxExtends[0].Y);
    UE_LOG(LogTemp, Warning, TEXT("Z:%f"), vehiclesBoxExtends[0].Z);
    UE_LOG(LogTemp, Warning, TEXT("<-------vehiclesBoxExtends-------->"));

    UE_LOG(LogTemp, Warning, TEXT("<-------vehiclesLocations-------->"));
    UE_LOG(LogTemp, Warning, TEXT("X:%f"), vehiclesLocations[0].X);
    UE_LOG(LogTemp, Warning, TEXT("Y:%f"), vehiclesLocations[0].Y);
    UE_LOG(LogTemp, Warning, TEXT("Z:%f"), vehiclesLocations[0].Z);
    UE_LOG(LogTemp, Warning, TEXT("<-------vehiclesLocations-------->"));

    TArray < TArray<TArray<float>> > boxes = GetBoundingBoxes(vehiclesBoxLocations, vehiclesBoxRotations, sensorLocation, sensorRotation, vehiclesBoxExtends, vehiclesLocations);
    //UE_LOG(LogTemp, Warning, TEXT("<-----------------cordsXYZ------------------------>"));
    //for (const TArray<TArray<float>>& box : boxes)
    //{
    //    UE_LOG(LogTemp, Warning, TEXT("---------------------------NEW BOX------------------------"));
    //    for (TArray<float> row : box)
    //    {
    //        UE_LOG(LogTemp, Warning, TEXT("["));
    //        for (float element : row)
    //        {
    //            UE_LOG(LogTemp, Warning, TEXT("%f"), element);
    //        }
    //        UE_LOG(LogTemp, Warning, TEXT("]"));
    //    }
    //    UE_LOG(LogTemp, Warning, TEXT("---------------------------NEW BOX------------------------"));
    //}
    //UE_LOG(LogTemp, Warning, TEXT("<-----------------cordsXYZ------------------------>"));
    DrawBoundingBoxes(boxes, frameNum);
}

TArray<float>  Acapture2dBox::divArr(TArray<float> array1, TArray<float> array2)
{
    int32 arraySize = FMath::Min(array1.Num(), array2.Num());
    TArray<float> resultArray;
    resultArray.SetNum(arraySize);

    for (int32 i = 0; i < arraySize; i++)
    {
        if (array2[i] != 0.0f)
        {
            resultArray[i] = array1[i] / array2[i];
        }
        else
        {
            // Handle division by zero case if needed
            // For example, assign a default value or handle the error
            resultArray[i] = 0.0f;
        }
    }

    return resultArray;
}

TArray<TArray<float>>  Acapture2dBox::transArr(TArray<TArray<float>> orgArr) //3x8 --> 8x3
{
    TArray<TArray<float>> transArr;
    int32 newRow;
    int32 newCol;
    newCol = orgArr.Num();
    newRow = orgArr[0].Num();
    transArr.SetNum(newRow);

    for (int32 i = 0; i < newRow; i++)
    {
        transArr[i].SetNum(newCol);
    }
    for (int32 i = 0; i < newCol; i++)
    {
        for (int32 j = 0; j < newRow; j++)
        {

            transArr[j][i] = orgArr[i][j];
        }
    }
    return transArr;
}

bool  Acapture2dBox::CheckFiles(int32 usrFrame)
{

    FString pathRGB = mainDir + dirRGB;
    FString pathSeg = mainDir + dirSeg;
    FString pathVbbox = mainDir + dirVbbox;

    FString extensionRGB = "*.jpeg";
    FString extensionSeg = "*.png";
    FString extensionVbbox = "*";

    TArray<FString> filesRGB;
    TArray<FString> filesSeg;
    TArray<FString> filesVbbox;

    IFileManager& FileManager = IFileManager::Get();
    FileManager.FindFiles(filesRGB, *pathRGB, *extensionRGB);
    FileManager.FindFiles(filesSeg, *pathSeg, *extensionSeg);
    FileManager.FindFiles(filesVbbox, *pathVbbox, *extensionVbbox);

    int32 numberOfFilesRGB = filesRGB.Num();
    int32 numberOfFilesSeg = filesSeg.Num();
    int32 numberOfFilesVbbox = filesVbbox.Num();

    UE_LOG(LogTemp, Warning, TEXT("RGB path: %s"), *pathRGB);
    UE_LOG(LogTemp, Warning, TEXT("number_of_files_rgb: %d"), numberOfFilesRGB);
    UE_LOG(LogTemp, Warning, TEXT("seg path: %s"), *pathSeg);
    UE_LOG(LogTemp, Warning, TEXT("number_of_files_seg: %d"), numberOfFilesSeg);
    UE_LOG(LogTemp, Warning, TEXT("BB3d path: %s"), *pathVbbox);
    UE_LOG(LogTemp, Warning, TEXT("number_of_files_bb3d: %d"), numberOfFilesVbbox);
    UE_LOG(LogTemp, Warning, TEXT("number frames user demanded: %d"), usrFrame);

    if (numberOfFilesRGB == usrFrame && numberOfFilesSeg == usrFrame && numberOfFilesVbbox == usrFrame)
    {
        UE_LOG(LogTemp, Warning, TEXT("READY TO GENERATE (^_^) "));
        return true;
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("FILES ARE NOT READY  (^@^) "));
        return false;
    }
}

void  Acapture2dBox::generate2d(int32 usrFrames)
{

    rgbInfo.SetNum(viewHeight);
    segInfo.SetNum(viewHeight);
    for (int32 counter = 0; counter < usrFrames; counter++)
    {
        result = readingData(counter);
        if (result.Get<2>())
        {
            //ConvertBoundingBoxes(result.Get<0>(), result.Get<1>());
            //ReadColors(counter);
            processing(rgbInfo, ConvertBoundingBoxes(result.Get<0>(), result.Get<1>()), counter, ReadColors(counter));
        }

    }


}

TArray<TArray<FColor>>  Acapture2dBox::readImage(const TCHAR* path, EImageFormat format)
//TArray<TArray<FColor>>  Acapture2dBox::readImage(const TCHAR* path)
{
    TArray<FColor> PixelData;
    TArray<TArray<FColor>> PixelData2D;// 2D array to store the pixel values
    TArray<uint8> RawFileData;
    int32 ImageWidth = 0;
    int32 ImageHeight = 0;
    TArray<uint8> UncompressedData;
    TArray<uint8> CompressedData;
    FFileHelper::LoadFileToArray(RawFileData, path);


    // Assuming you have loaded the image data into the 'RawFileData' array and set up the 'ImageWrapper' as shown in the previous code examples



    TSharedPtr<IImageWrapper> ImageWrapper = FModuleManager::Get().LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper")).CreateImageWrapper(format);



    if (ImageWrapper.IsValid() && ImageWrapper->SetCompressed(RawFileData.GetData(), RawFileData.Num()))
    {

        if (ImageWrapper->GetRaw(ERGBFormat::BGRA, 8, UncompressedData))
        {
            // Access and manipulate the image data in the UncompressedData array
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Valid Image Wrapper !!!!!!"));
            GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Blue, FString::FromInt(ImageWrapper->GetWidth()));
        }
    }
    else
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Something went wrong !!!!!!"));

    }

    //ImageWrapper->GetRawImageSize(ImageWidth, ImageHeight);




    ImageWidth = ImageWrapper->GetWidth();
    ImageHeight = ImageWrapper->GetHeight();
    PixelData.SetNumZeroed(ImageWidth * ImageHeight);
    if (ImageWrapper->GetRaw(ERGBFormat::BGRA, 8, UncompressedData))
    {
        const uint8* ImageBytes = UncompressedData.GetData();

        for (int32 Y = 0; Y < ImageHeight; Y++)
        {
            for (int32 X = 0; X < ImageWidth; X++)
            {
                int32 Index = Y * ImageWidth + X;
                FColor& Pixel = PixelData[Index];

                Pixel.R = ImageBytes[Index * 4 + 2];
                Pixel.G = ImageBytes[Index * 4 + 1];
                Pixel.B = ImageBytes[Index * 4];
                Pixel.A = ImageBytes[Index * 4 + 3];
            }
        }
    }

    PixelData2D.SetNum(ImageHeight);
    for (int32 Y = 0; Y < ImageHeight; Y++)
    {
        PixelData2D[Y].SetNum(ImageWidth);
        for (int32 X = 0; X < ImageWidth; X++)
        {
            int32 Index = Y * ImageWidth + X;
            PixelData2D[Y][X] = PixelData[Index];
        }
    }

    FImageUtils::CompressImageArray(ImageWidth, ImageHeight, PixelData, CompressedData);
    //FFileHelper::SaveArrayToFile(CompressedData, *SavePath);
    return PixelData2D;
}

TTuple<TArray<TArray<FVector2D>>, int32, bool>  Acapture2dBox::readingData(int32 index)
{

    FString MainDir = mainDir;
    FString RGBImagePath = MainDir + FString::Printf(TEXT("custom_data/img_%.6d.jpeg"), index);
    FString SegImagePath = MainDir + FString::Printf(TEXT("SegmentationImage/img_%.6d.png"), index);
    FString VehicleBBoxFilePath = MainDir + FString::Printf(TEXT("VehicleBBox/bbox%d"), index) + ".txt";
    FString VBoundingBoxRawData;
    TArray<int32> VBBoxDataNumeric;
    int32 lines;
    TArray<TArray<FVector2D>> VBBoxData;
    //TArray<TArray<FColor>> rgbImage;

    rgbImage = readImage(*RGBImagePath, EImageFormat::JPEG);
    segImage = readImage(*SegImagePath, EImageFormat::PNG);
    //TArray<TArray<FColor>> segImage = readImage(*SegImagePath, EImageFormat::PNG);

    if (rgbImage.Num() > 0)
    {
        int32 ImageWidth = rgbImage[0].Num();
        int32 ImageHeight = rgbImage.Num();

        // Perform calculations using PixelData2D
        // ...

        // Print the RGB values of a specific pixel
        int32 X = 10; // X-coordinate of the pixel
        int32 Y = 20; // Y-coordinate of the pixel
        FColor PixelColor = rgbImage[Y][X];
        UE_LOG(LogTemp, Warning, TEXT("RGB values of pixel (%d, %d): R=%d, G=%d, B=%d"), X, Y, PixelColor.R, PixelColor.G, PixelColor.B);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to read image data."));
    }


    //converting 8 3d bbox cord to 2d 
    if (rgbImage.Num() != 0 && segImage.Num() != 0)
    {
        // Vehicle



        bool bLoaded = FFileHelper::LoadFileToString(VBoundingBoxRawData, *VehicleBBoxFilePath);

        TArray<FString> VBBoxDataString;
        VBoundingBoxRawData.ParseIntoArrayLines(VBBoxDataString);

        GEngine->AddOnScreenDebugMessage(-1, 25.f, FColor::Green, VBBoxDataString[0]);
        for (const FString& TupleString : VBBoxDataString)
        {
            // Remove parentheses and whitespace
            FString CleanedString = TupleString.Replace(TEXT("("), TEXT("")).Replace(TEXT(")"), TEXT("")).TrimStartAndEnd();

            // Use regular expression to find all integers
            FString Pattern = TEXT("-?\\d+");
            FRegexPattern RegexPattern(Pattern);
            FRegexMatcher Matcher(RegexPattern, CleanedString);

            // Iterate over matches and convert to integers
            while (Matcher.FindNext())
            {
                FString NumericString = Matcher.GetCaptureGroup(0);
                int32 NumericValue = FCString::Atoi(*NumericString);
                VBBoxDataNumeric.Add(NumericValue);
            }
        }

        int32 VBBoxLineLength = VBBoxDataNumeric.Num() / 16;

        // Print VBBoxDataNumeric for verification
        for (int32 i = 0; i < VBBoxDataNumeric.Num(); i++)
        {
            UE_LOG(LogTemp, Warning, TEXT("VBBoxDataNumeric[%d]: %d"), i, VBBoxDataNumeric[i]);
        }
        if (bLoaded && VBoundingBoxRawData.Len() > 0)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("BBOX LOADED!!!!!!"));
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("length-->%d"), VBBoxLineLength));
        }
        else
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("BBOX FAILED TO LOAD!!!!!!"));
        }


        lines = VBBoxDataNumeric.Num() / 16;
        int32 Index = 0;
        for (int32 i = 0; i < lines; ++i)
        {

            TArray<FVector2D> TupleCoords;

            for (int32 j = 0; j < 8; ++j)
            {

                int32 CoordX = VBBoxDataNumeric[Index];
                int32 CoordY = VBBoxDataNumeric[Index + 1];
                FVector2D Coord(CoordX, CoordY);
                TupleCoords.Add(Coord);
                Index = Index + 2;
            }

            //VBBoxData.Append(TupleCoords);
            VBBoxData.Add(TupleCoords);
        }
        for (const TArray<FVector2D>& Tuple : VBBoxData)
        {
            FString TupleStr;
            for (const FVector2D& Coord : Tuple)
            {
                TupleStr += "(" + FString::FromInt(Coord.X) + ", " + FString::FromInt(Coord.Y) + "), ";
            }
            UE_LOG(LogTemp, Warning, TEXT("Tuple: %s"), *TupleStr);
        }

        rgbInfo = rgbImage;
        segInfo = segImage;
        return MakeTuple(VBBoxData, lines, true);
        UE_LOG(LogTemp, Warning, TEXT("RGB image and Segmentation is ready !"));
    }

    else
    {

        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("RGB image or Segmentation is not ready !"));
        UE_LOG(LogTemp, Warning, TEXT("RGB image or Segmentation is not ready !"));
        return MakeTuple(VBBoxData, lines, false);
    }



}
