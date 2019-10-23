// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PerlinNoise2D.generated.h"

/**
 * 
 */
UCLASS()
class PROCEDURAL_GEN_API UPerlinNoise2D : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	/** Generates Perlin noise from two given values. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Perlin Noise 2D", CompactNodeTitle = "PerlinNoise2D", Keywords = "Perlin Noise 2D"), Category = "Math|Random")
	static float PerlinNoise2D(float x, float y, float scale);
};