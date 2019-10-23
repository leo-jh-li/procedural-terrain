// Fill out your copyright notice in the Description page of Project Settings.


#include "PerlinNoise2D.h"


float UPerlinNoise2D::PerlinNoise2D(float x, float y, float scale) {
    // Prevent integer values
    x += 0.1;
    y += 0.1;
    // Prevent division by 0
    if (scale == 0) {
        scale = 0.1;
    }
    float perlinValue = FMath::PerlinNoise2D(FVector2D(x * scale, y * scale));
    // // Change range from [-1, 1] to [0, 1]
    // perlinValue = (perlinValue + 1) / 2;
    // UE_LOG(LogTemp, Warning, TEXT("(%f, %f): %f"), x, y, perlinValue);
    return perlinValue;
}