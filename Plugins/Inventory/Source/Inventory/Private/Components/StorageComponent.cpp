// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/StorageComponent.h"

#include "Base/BaseItem.h"
#include "Engine/DataTable.h"
#include "Net/UnrealNetwork.h"

UStorageComponent::UStorageComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UStorageComponent::TickComponent(float DeltaTime, ELevelTick TickType,	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UStorageComponent::BeginPlay()
{
	Super::BeginPlay();









	
}

void UStorageComponent::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UStorageComponent, Items);
	DOREPLIFETIME(UStorageComponent, SlotsFilled);
	DOREPLIFETIME(UStorageComponent, Capacity);
}

int UStorageComponent::GetFirstEmpty()
{
	for (FInventoryItem a : Items) {
		if (a.isEmpty) {
			return a.index;
		}
	}
	return -1;
}

void UStorageComponent::OnRep_StorageUpdated()
{
	OnInventoryUpdated.Broadcast();
}

void UStorageComponent::UpdateUI()
{
	OnInventoryUpdated.Broadcast();
}



int UStorageComponent::AddEmptyAtIndex(int Index)
{
	FInventoryItem e = FInventoryItem();
	e.index = Index;
	e.isEmpty = true;
	e.ItemOwner = this;
	Items.Insert(e, Index);
	UpdateUI();
	return Index;
}

void UStorageComponent::ServerAddBPItem_Implementation(FInventoryItem Item)
{
	AddItem(Item);
}

bool UStorageComponent::AddItem(FInventoryItem Item)
{
	if (SlotsFilled >= Capacity) {
		OnInventoryFull.Broadcast();
		return false;
	}

	// process if the item is stackable
	if (DataTable)
	{
		FItemRow* ItemRow = DataTable->FindRow<FItemRow>(Item.UniqueName, "");

		int PendingStackSize = Item.StackSize;

		if (ItemRow->bIsStackable) {
			for (FInventoryItem& a : Items) {
				if (a == Item) {
					if (!ItemRow->bHasMaxStackSize) {
						a.StackSize += PendingStackSize;
						UpdateUI();
						return true;
					}
					else {
						if (a.StackSize < ItemRow->MaxStackSize) {
							int OldStackSize = a.StackSize;

							if ((OldStackSize + PendingStackSize) > ItemRow->MaxStackSize) {
								int Diff = (OldStackSize + PendingStackSize) - ItemRow->MaxStackSize;
								a.StackSize = ItemRow->MaxStackSize;
								PendingStackSize = Diff;
							}
							else {
								a.StackSize += PendingStackSize;
								PendingStackSize = 0;
							}
						}
					}
				}

				if (PendingStackSize == 0) {
					UpdateUI();
					return true;
				}
			}
		}

		int newIndex = GetFirstEmpty();
		Items.RemoveAt(newIndex);

		Item.index = newIndex;
		Item.StackSize = PendingStackSize;
		Item.ItemOwner = this;

		Items.Insert(Item, newIndex);
		SlotsFilled++;

		UpdateUI();
		return true;
	}
	return false;
}

void UStorageComponent::ServerRemoveBPItem_Implementation(FInventoryItem Item)
{
	RemoveItem(Item);
}

bool UStorageComponent::RemoveItem(FInventoryItem Item)
{
	int Index = Item.index;
	if (Item.index > -1) {
		Items.RemoveAt(Index);
		AddEmptyAtIndex(Index);
		SlotsFilled--;
		UpdateUI();
		return true;
	}
	return false;
}

bool UStorageComponent::RemoveItemStack(FName UniqueName, int StackSize)
{
	int PendingCount = StackSize;

	for (FInventoryItem& a : Items) {
		if (a.UniqueName == UniqueName) {
			if (a.StackSize <= PendingCount) {
				PendingCount -= a.StackSize;
				RemoveItem(a);
			}
			else {
				a.StackSize -= PendingCount;
				PendingCount = 0;
			}

			if (PendingCount <= 0) {
				UpdateUI();
				return true;
			}
		}
	}

	UpdateUI();
	return false;
}

void UStorageComponent::ServerRemoveBPItemStack_Implementation(FName UniqueName, int StackSize)
{
	RemoveItemStack(UniqueName, StackSize);
}

bool UStorageComponent::HasItems(FName UniqueName, int StackSize)
{
	int PendingCount = StackSize;
	
	for (FInventoryItem& a : Items) {
		if (a.UniqueName == UniqueName) {
			PendingCount -= a.StackSize;

			if (PendingCount <= 0) {
				return true;
			}
		}
	}
	return false;
}

bool UStorageComponent::BPHasItems(FName UniqueName, int StackSize)
{
	return HasItems(UniqueName, StackSize);
}





