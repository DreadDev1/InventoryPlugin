#pragma once

#include "CoreMinimal.h"

#include "Engine/DataTable.h"

#include "BaseItem.generated.h"

UENUM(BlueprintType)
enum eItemType
{
	Unset		UMETA(DisplayName = "Unset"),
	Weapon		UMETA(DisplayName = "Weapon"),
	Spell		UMETA(DisplayName = "Spell"),
	Food		UMETA(DisplayName = "Food"),
	Potion		UMETA(DisplayName = "Potion"),
	Armour		UMETA(DisplayName = "Armour"),
	Material	UMETA(DisplayName = "Material"),	
};

USTRUCT(BlueprintType, Category=Inventory)
struct FItemRow : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		UStaticMesh* StaticMesh;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		USkeletalMesh* SkeletalMesh;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		FName UniqueName;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		FText ItemDisplayName;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory, meta = (MultiLine = true))
		FText ItemDescription;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		UTexture2D* Thumbnail;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		TEnumAsByte<eItemType> ItemType = eItemType::Unset;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		FText UseActionText;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory, meta = (ClampMin = 0.0))
		float Weight;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory, meta = (ClampMin = 1))
		int StackSize = 1;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory, meta = (ClampMin = 1))
		int MaxStackSize = 100;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory, meta = (ClampMin = 0.0))
		float Cost;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory, meta = (ClampMin = 0.0))
		float SellCost;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		FString CostType;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		bool bIsConsumable = false;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		bool bIsStackable = false;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		bool bHasMaxStackSize = false;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		bool bIsRare = false;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		bool bIsBound = false;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		bool bIsEnabled = true;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		bool bIsAltEnabled = true;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		bool bHasCooldown = false;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		float CooldownTime = 5.0f;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		bool bHasAltCooldown = false;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		float AltCooldownTime = 1.0f;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		bool bIsShopItem = false;
};

