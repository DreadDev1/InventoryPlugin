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
		bool bisConsumable = false;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		bool bisStackable = false;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		bool bhasMaxStackSize = false;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		bool bisRare = false;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		bool bisBound = false;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		bool bisEnabled = true;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		bool bisAltEnabled = true;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		bool bhasCooldown = false;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		float cooldownTime = 5.0f;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		bool bhasAltCooldown = false;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		float altCooldownTime = 1.0f;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		bool bisShopItem = false;
};

