// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SGame : ModuleRules
{
	public SGame(TargetInfo Target)
	{
        PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore", "UMG", });

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
