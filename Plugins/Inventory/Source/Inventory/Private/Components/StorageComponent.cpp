// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/StorageComponent.h"


UStorageComponent::UStorageComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UStorageComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UStorageComponent::BeginPlay()
{
	Super::BeginPlay();
}

