// Copyright Eagle 3D Streaming. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "UObject/NoExportTypes.h"
#include "E3dsAutomationToolsSettings.generated.h"

class FToolBarBuilder;
class FMenuBuilder;

UENUM(BlueprintType)
enum class EPackagingModes : uint8
{
	Development UMETA(DisplayName = "Development"),
	Shipping UMETA(DisplayName = "Shipping"),
};



UCLASS(config = E3DSAutomationToolsSettings, defaultconfig, meta = (DisplayName = "E3DS Automation Tools Settings"))
class E3DSAUTOMATIONTOOLS_API UE3dsAutomationToolsSettings : public UObject
{
	GENERATED_BODY()

public:
	template< typename T >
	FString EnumToString(T EnumValue)
	{
		static_assert(TIsUEnumClass< T >::Value, "'T' template parameter to EnumToString must be a valid UEnum");
		return StaticEnum< T >()->GetNameStringByValue((int64)EnumValue);
	}
	bool CanBuildServer() const;
#if WITH_EDITOR
	virtual bool CanEditChange(const FProperty* InProperty) const override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	FString GetEnumAsString(EPackagingModes EnumValue)
	{
		const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EPackagingModes"), true);
		if (!EnumPtr)
		{
			// Handle error, enum not found
			return FString();
		}

		return EnumPtr->GetDisplayNameTextByIndex(static_cast<int32>(EnumValue)).ToString();
	}
	

	UE3dsAutomationToolsSettings(const FObjectInitializer& obj);
	UPROPERTY(Config, EditAnywhere, Category = "E3DS Automation Settings", DisplayName = "Path to E3DS Automation Executable" )

		FFilePath E3DSExecutablePath;


		

	//UPROPERTY(Config, EditAnywhere, Category = "E3DS Automation Settings")
		//FFilePath 
		FString EngineFolderPath;

		//UPROPERTY(Config, EditAnywhere, Category = "E3DS Automation Settings")
		//FFilePath 
			FString EngineExePath;
		
		//UPROPERTY(Config, EditAnywhere, Category = "E3DS Automation Settings",DisplayName = "Path to Unreal Project file( yourProjectName.uproject )")
		//FFilePath 
			FFilePath UProjectPath;
		
			UPROPERTY(Config, EditAnywhere, Category = "E3DS Automation Settings", DisplayName = "Path to 7zip Executable( 7z.exe )")
		FFilePath PathTo7Zip;
		
		
	UPROPERTY(Config, EditAnywhere, Category = "E3DS Automation Settings",DisplayName = "E3DS Api Key")
		FString ApiKey;
	//UPROPERTY(Config, EditAnywhere, Category = "E3DS Automation Settings")
		//FString CloudStorage;
	//UPROPERTY(Config, EditAnywhere, Category = "E3DS Automation Settings")
		//FString UserName;
	UPROPERTY(Config, EditAnywhere, Category = "E3DS Automation Settings",DisplayName = "Streaming App Name")
		FString E3DSStreamingAppName;

	UPROPERTY(Config, EditAnywhere, Category = "E3DS Automation Settings")
	EPackagingModes PackagingMode;

	//UPROPERTY(Config, EditAnywhere, Category = "E3DS Automation Settings")
		FDirectoryPath PackagingFolder;
	UPROPERTY(Config, EditAnywhere, Category = "E3DS Automation Settings",DisplayName = "Build Dedicated Server App")
		bool DoDedicatedServerBuild;

	UPROPERTY(Config, EditAnywhere, Category = "E3DS Automation Settings",DisplayName = "Dedicated Server App Name")
		FString E3DSDedicatedServerAppName;

	UPROPERTY(Config, EditAnywhere, Category = "E3DS Automation Settings",DisplayName = "Launch Streaming App Url On Completion")
	bool AutoLaunchStreamingAppURLOnCompletion;

	//UPROPERTY(Config, EditAnywhere, Category = "E3DS Automation Settings")
	//	FString TestUrl;
	// Get the project name dynamically
	FString ProjectName = FApp::GetProjectName();
	//const FString PluginName = TEXT("E3DSAutomationTools");
	//const FString ConfigFilePath = FPaths::ProjectConfigDir() / TEXT("DefaultE3DSAutomationToolsSettings.ini");
	//const FString SectionName = TEXT("/Script/E3DSAutomationTools.E3DSAutomationToolsSettings");
	//const  FString PluginBaseDir = IPluginManager::Get().FindPlugin(TEXT("E3DSAutomationTools"))->GetBaseDir();
	//bool FindE3DSExecutable();


};