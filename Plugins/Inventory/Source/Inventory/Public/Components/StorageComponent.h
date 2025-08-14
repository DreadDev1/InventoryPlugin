// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Delegates//DelegateCombinations.h"
#include "Base/InventoryItem.h"
#include "StorageComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStorageCompUpdated);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStorageCompFull);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class INVENTORY_API UStorageComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UStorageComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
#pragma region Variables
	UPROPERTY(EditDefaultsOnly, Replicated, Category = Inventory)
	int Capacity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Replicated, Category = Inventory)
	int SlotsFilled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing=OnRep_StorageUpdated, Category = Inventory)
	TArray<FInventoryItem> Items;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
	UDataTable* DataTable;

	UPROPERTY(BlueprintAssignable, Category = Inventory)
	FOnStorageCompUpdated OnInventoryUpdated;
	
	UPROPERTY(BlueprintAssignable, Category = Inventory)
	FOnStorageCompFull OnInventoryFull;
	
#pragma endregion Variables

#pragma region Functions

	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	UFUNCTION()
	void OnRep_StorageUpdated();
	
	void UpdateUI();
	
	int GetFirstEmpty();
	int AddEmptyAtIndex(int Index);
	
	bool AddItem(FInventoryItem Item);
	bool RemoveItem(FInventoryItem Item);
	bool RemoveItemStack(FName UniqueName, int StackSize);
	bool HasItems(FName UniqueName, int StackSize);

#pragma endregion Functions
	
#pragma region BPFunctions

	UFUNCTION(BlueprintCallable, Category=Inventory)
	TArray<FInventoryItem> GetItems() { return Items; }

	UFUNCTION(BlueprintCallable, Server, Reliable, Category = Inventory)
	void ServerAddBPItem(FInventoryItem Item);

	UFUNCTION(BlueprintCallable, Server, Reliable, Category = Inventory)
	void ServerRemoveBPItem(FInventoryItem Item);

	UFUNCTION(BlueprintCallable, Server, Reliable, Category = Inventory)
	void ServerRemoveBPItemStack(FName UniqueName, int StackSize);
	
	UFUNCTION(BlueprintCallable, Category = Inventory)
	bool BPHasItems(FName UniqueName, int StackSize);

	
	
#pragma endregion BPFunctions

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
