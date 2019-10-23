// Fill out your copyright notice in the Description page of Project Settings.


#include "GenerateNoiseMap.h"
#include "Kismet/KismetMathLibrary.h" 
#include "Curves/CurveFloat.h"


void UGenerateNoiseMap::GenerateNoiseMap(TArray<float>& map, int rows, int cols, float scale, int octaves, float persistence, float lacunarity, UCurveFloat* heightWeight) {
    float minNoiseHeight = 1;
    float maxNoiseHeight = -1;

    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            float amplitude = 1;
            float frequency = 1;
            float noiseHeight = 0;
            for (int i = 0; i < octaves; i++) {
                float sampleX = (x + 0.1) * scale * frequency + (i * scale * 100000);
                float sampleY = (y + 0.1) * scale * frequency + (i * scale * 100000);
                float perlinValue = FMath::PerlinNoise2D(FVector2D(sampleX, sampleY));
                noiseHeight += perlinValue * amplitude;
                amplitude *= persistence;
                frequency *= lacunarity;
            }
            map.Add(noiseHeight);

            // Update min and max height values
            if (noiseHeight < minNoiseHeight) {
                minNoiseHeight = noiseHeight;
            } else if (noiseHeight > maxNoiseHeight) {
                maxNoiseHeight = noiseHeight;
            }
        }
    }

    // Normalize noise and apply height weight
    for (int i = 0; i < map.Num(); i++) {
        map[i] = UKismetMathLibrary::NormalizeToRange(map[i], minNoiseHeight, maxNoiseHeight);
        map[i] = heightWeight->GetFloatValue(map[i]);
    }
}
