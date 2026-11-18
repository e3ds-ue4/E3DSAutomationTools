// Copyright Eagle 3D Streaming. All Rights Reserved.

#include "E3DSAutomationToolsCommands.h"

#define LOCTEXT_NAMESPACE "FE3DSAutomationToolsModule"

void FE3DSAutomationToolsCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "E3DS-Push To Cloud", "Launch E3DS Automation Tool to push to cloud", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
