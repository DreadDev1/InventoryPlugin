#include "Base/SharedStorage.h"
#include "Net/UnrealNetwork.h"

ASharedStorage::ASharedStorage(const FObjectInitializer& ObjectImitializer) : Super(ObjectImitializer)
{
	SetReplicates(true);

	StorageComponent = CreateDefaultSubobject<UStorageComponent>("StorageComponent");
	StorageComponent->SetIsReplicated(true);
	StorageComponent->Capacity = 20;
}

void ASharedStorage::BeginPlay()
{
	Super::BeginPlay();
}

void ASharedStorage::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ASharedStorage, StorageComponent);
}

void ASharedStorage::ServerAddBPItem_Implementation(FInventoryItem Item)
{
	StorageComponent->AddItem(Item);
}

void ASharedStorage::ServerRemoveBPItem_Implementation(FInventoryItem Item)
{
	StorageComponent->RemoveItem(Item);
}

void ASharedStorage::ServerRemoveBPItemStack_Implementation(FName UniqueName, int StackSize)
{
	StorageComponent->RemoveItemStack(UniqueName, StackSize);
}
