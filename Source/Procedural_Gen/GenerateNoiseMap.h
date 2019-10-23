// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GenerateNoiseMap.generated.h"

/**
 * 
 */
UCLASS()
class PROCEDURAL_GEN_API UGenerateNoiseMap : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	/** Generates a Perlin noise map. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Perlin Noise Map", CompactNodeTitle = "PerlinNoiseMap", Keywords = "Perlin Noise 2D Map"), Category = "Math|Random")
	static void GenerateNoiseMap(TArray<float>& map, int rows, int cols, float scale, int octaves, float persistence, float lacunarity, UCurveFloat* heightWeight);
};
