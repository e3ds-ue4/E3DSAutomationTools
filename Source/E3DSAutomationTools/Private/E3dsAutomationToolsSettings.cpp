// Copyright Eagle 3D Streaming. All Rights Reserved.

#include "E3dsAutomationToolsSettings.h"
//#include "Paths.h"



bool DoesPluginExist(const FString& PluginName)
{
    // Construct paths for project and engine plugin folders
    FString ProjectPluginPathRelative = FPaths::Combine(FPaths::ProjectPluginsDir(), PluginName);
    FString EnginePluginPathRelative = FPaths::Combine(FPaths::EnginePluginsDir(), PluginName);

    // Convert relative paths to absolute paths
    FString ProjectPluginPath = FPaths::ConvertRelativePathToFull(ProjectPluginPathRelative);
    FString EnginePluginPath = FPaths::ConvertRelativePathToFull(EnginePluginPathRelative);

    ProjectPluginPath = "C:/0.ue4/UE53_Tiny/Plugins/E3dsAutomationTools";

   
    // Check if the plugin directory exists in the project folder
    if (FPlatformFileManager::Get().GetPlatformFile().DirectoryExists(*ProjectPluginPath))
    {
        // Plugin exists in the project folder
        int aa = 0;
        aa = 88;
        return true;
    }

    // Check if the plugin directory exists in the project folder
    if (FPlatformFileManager::Get().GetPlatformFile().DirectoryExists(*ProjectPluginPath))
    {
        // Plugin exists in the project folder
        return true;
    }

    // Check if the plugin directory exists in the engine folder
    if (FPlatformFileManager::Get().GetPlatformFile().DirectoryExists(*EnginePluginPath))
    {
        // Plugin exists in the engine folder
        return true;
    }

    // Plugin not found in either folder
    return false;
}

bool  UE3dsAutomationToolsSettings::
CanBuildServer() const
{
//    FString ProjectName = FApp::GetProjectName();
	FString Filename = ProjectName + "Server.Target.cs";
	FString ProjectServerTargetPath = FPaths::Combine(FPaths::GameSourceDir(), Filename);
	FString EngineServerTargetPath = FPaths::Combine(FPaths::EngineSourceDir(), TEXT("/UnrealServer.Target.cs"));
	if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*ProjectServerTargetPath) && FPlatformFileManager::Get().GetPlatformFile().FileExists(*EngineServerTargetPath))
	{
		return true;
	}

	return false;


}
#if WITH_EDITOR
bool UE3dsAutomationToolsSettings::CanEditChange(const FProperty* InProperty) const
{
	// If other logic prevents editing, we want to respect that
	const bool ParentVal = Super::CanEditChange(InProperty);
	if (InProperty->GetFName() == GET_MEMBER_NAME_CHECKED(UE3dsAutomationToolsSettings, DoDedicatedServerBuild))
	{
		return CanBuildServer();

	}
	if (InProperty->GetFName() == GET_MEMBER_NAME_CHECKED(UE3dsAutomationToolsSettings, E3DSDedicatedServerAppName))
	{
		return CanBuildServer();
	}
	return ParentVal;
}
void UE3dsAutomationToolsSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	// Get the name of the property that was changed
	/*FName PropertyName = (PropertyChangedEvent.Property != nullptr) ? PropertyChangedEvent.Property->GetFName() : NAME_None;
	FName MemberPropertyName = PropertyChangedEvent.GetMemberPropertyName();
	if (MemberPropertyName == GET_MEMBER_NAME_CHECKED(UE3dsAutomationToolsSettings, E3DSExecutablePath))
	{
		if (E3DSExecutablePath.FilePath.Contains(PluginBaseDir)) {
			FString RelativePath = E3DSExecutablePath.FilePath.Replace(*PluginBaseDir, TEXT("{PluginDirectory}"), ESearchCase::IgnoreCase);
			E3DSExecutablePath.FilePath = RelativePath;
			GConfig->Flush(false, ConfigFilePath);
		}
	}*/
}
#endif


UE3dsAutomationToolsSettings::UE3dsAutomationToolsSettings(const FObjectInitializer& obj)
{


#if ENGINE_MAJOR_VERSION == 5
    FString EngineDir = FPaths::EngineDir();
    FString EditorPath = FPaths::Combine(*EngineDir, TEXT("Binaries/Win64/UnrealEditor.exe")); // For Windows 64-bit
    EngineExePath = EditorPath;
	
#else
    FString EngineDir = FPaths::EngineDir();
    FString EditorPath = FPaths::Combine(*EngineDir, TEXT("Binaries/Win64/UE4Editor.exe")); // For Windows 64-bit
    EngineExePath = EditorPath;
#endif

    EngineFolderPath = FPaths::EngineDir();

    UProjectPath.FilePath =FPaths::GetProjectFilePath();
	AutoLaunchStreamingAppURLOnCompletion = true;

    // Example usage
    FString PluginName = TEXT("E3dsAutomationTools"); // Replace with the actual plugin name



    FString ProjectPluginsDir = FPaths::ProjectPluginsDir();

    // Construct paths for project and engine plugin folders
    FString ProjectPluginPathRelative = FPaths::Combine(FPaths::ProjectPluginsDir(), PluginName);
    FString EnginePluginPathRelative = FPaths::Combine(FPaths::EnginePluginsDir(),"Marketplace", PluginName);

    // Convert relative paths to absolute paths
    FString ProjectPluginPath = FPaths::ConvertRelativePathToFull(ProjectPluginPathRelative);
    FString EnginePluginPath = FPaths::ConvertRelativePathToFull(EnginePluginPathRelative);

    // Check if the plugin directory exists in the project folder
    if (FPlatformFileManager::Get().GetPlatformFile().DirectoryExists(*ProjectPluginPath))
    {
        // Plugin exists in the project folder
        ProjectPluginsDir = ProjectPluginPath;
    }
    // Check if the plugin directory exists in the engine folder
    else  if (FPlatformFileManager::Get().GetPlatformFile().DirectoryExists(*EnginePluginPath))//Marketplace
    {
        // Plugin exists in the engine folder
        ProjectPluginsDir = EnginePluginPath;
    }


  
   

    E3DSExecutablePath.FilePath = ProjectPluginsDir + "/files/el_AT.exe";

}