// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Project_BossFight : ModuleRules
{
	public Project_BossFight(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput",
            "GameplayAbilities", "GameplayTags", "GameplayTasks",
            "AIModule", "MovieScene", "LevelSequence", "NavigationSystem",
            "UMG", "Niagara", "AdvancedWidgets"
        });

        PrivateIncludePaths.Add("Project_BossFight");
        PublicDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
    }
}