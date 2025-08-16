// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Player/InventoryPC.h"
#include "InventoryPluginPlayerController.generated.h"

class UInputMappingContext;
class UUserWidget;
class UStorageComponent;
struct FInventoryItem;

/**
 *  Simple first person Player Controller
 *  Manages the input mapping context.
 *  Overrides the Player Camera Manager class.
 */
UCLASS(abstract)
class INVENTORYPLUGIN_API AInventoryPluginPlayerController : public AInventoryPC
{
	GENERATED_BODY()
	
public:

	/** Constructor */
	AInventoryPluginPlayerController();

	UFUNCTION(BlueprintCallable, Server, Reliable, Category = Inventory)
	void ServerAddBPItem(UStorageComponent* Storage, FInventoryItem Item);

	UFUNCTION(BlueprintCallable, Server, Reliable, Category = Inventory)
	void ServerRemoveBPItem(UStorageComponent* Storage,FInventoryItem Item);

protected:

	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, Category="Input|Input Mappings")
	TArray<UInputMappingContext*> DefaultMappingContexts;

	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, Category="Input|Input Mappings")
	TArray<UInputMappingContext*> MobileExcludedMappingContexts;

	/** Mobile controls widget to spawn */
	UPROPERTY(EditAnywhere, Category="Input|Touch Controls")
	TSubclassOf<UUserWidget> MobileControlsWidgetClass;

	/** Pointer to the mobile controls widget */
	TObjectPtr<UUserWidget> MobileControlsWidget;

	/** Gameplay initialization */
	virtual void BeginPlay() override;

	/** Input mapping context setup */
	virtual void SetupInputComponent() override;

};
