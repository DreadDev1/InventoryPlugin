#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StorageComponent.h"

#include "SharedStorage.generated.h"

UCLASS()
class INVENTORY_API ASharedStorage : public AActor
{
	GENERATED_BODY()

public:
	ASharedStorage(const FObjectInitializer& ObjectImitializer);
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated, Category = Inventory)
	class UStorageComponent* StorageComponent;

	UFUNCTION(BlueprintCallable, Server, Reliable, Category = Inventory)
	void ServerAddBPItem(FInventoryItem Item);

	UFUNCTION(BlueprintCallable, Server, Reliable, Category = Inventory)
	void ServerRemoveBPItem(FInventoryItem Item);

	UFUNCTION(BlueprintCallable, Server, Reliable, Category = Inventory)
	void ServerRemoveBPItemStack(FName UniqueName, int StackSize);

protected:
	virtual void BeginPlay() override;
};

