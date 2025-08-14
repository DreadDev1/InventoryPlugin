// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class InventoryPlugin : ModuleRules
{
	public InventoryPlugin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"Inventory"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"InventoryPlugin",
			"InventoryPlugin/Variant_Horror",
			"InventoryPlugin/Variant_Horror/UI",
			"InventoryPlugin/Variant_Shooter",
			"InventoryPlugin/Variant_Shooter/AI",
			"InventoryPlugin/Variant_Shooter/UI",
			"InventoryPlugin/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
