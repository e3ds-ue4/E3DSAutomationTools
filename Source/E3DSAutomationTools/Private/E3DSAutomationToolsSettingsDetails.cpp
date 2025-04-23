
#include "E3DSAutomationToolsSettingsDetails.h"
#include "E3DSAutomationToolsSettings.h"
#include "E3DSAutomationTools.h"
#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/SBoxPanel.h"


#define LOCTEXT_NAMESPACE "E3DSAutomationToolsSettingsDetails"

TSharedRef<IDetailCustomization> FE3DSAutomationToolsSettingsDetails::MakeInstance()
{
	return MakeShareable(new FE3DSAutomationToolsSettingsDetails);
}
void FE3DSAutomationToolsSettingsDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	TArray<TWeakObjectPtr<UObject>> ObjectsBeingCustomized;
	DetailBuilder.GetObjectsBeingCustomized(ObjectsBeingCustomized);
	check(ObjectsBeingCustomized.Num() == 1);
	TWeakObjectPtr<UE3dsAutomationToolsSettings> Settings = Cast<UE3dsAutomationToolsSettings>(ObjectsBeingCustomized[0].Get());
	IDetailCategoryBuilder& OpenUrlCategory = DetailBuilder.EditCategory("Utilities");//this is the one which  will be showed up  if no translation selected
	OpenUrlCategory.AddCustomRow(LOCTEXT("Utilities", "Utilities"))
		.ValueContent()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.Padding(5)
			.AutoWidth()
			[
				SNew(SButton)
					.Text(LOCTEXT("DownloadE3DSAutomatioExe", "Download E3DS Automation Tool Executable"))
					.ToolTipText(LOCTEXT("DownloadE3DSAutomatioExe_Tooltip", "Simply opens google"))
					.OnClicked_Lambda([this, Settings]()
						{
							FString URL = "https://e3ds-public-assets.s3.us-east-1.amazonaws.com/E3DSAutomation+Tool/E3DS_Automation.exe";								FE3DSAutomationToolsModule::OpenURL(URL);
								return(FReply::Handled());
						})
			]
			+ SHorizontalBox::Slot()
			.Padding(5)
			.AutoWidth()
			[
				SNew(SButton)
					.Text(LOCTEXT("OpenDocumentation", "Open Plugin Documentation"))
					.ToolTipText(LOCTEXT("OpenDocumentation_Tooltip", "Go to Documentation"))
					.OnClicked_Lambda([this, Settings]()
						{
							FString URL = "https://docs.eagle3dstreaming.com/wiki/upload-app-directly-from-unreal-editor-using-e3ds-";
							FE3DSAutomationToolsModule::OpenURL(URL);
							return(FReply::Handled());
						})
			]
			+ SHorizontalBox::Slot()
			.Padding(5)
			.AutoWidth()
			[
				SNew(SButton)
					.Text(LOCTEXT("GetE3DSApiKey", "Get E3DS Api Key"))
					.ToolTipText(LOCTEXT("GetE3DSApiKey_Tooltip", "Get E3DS Api Key"))
					.OnClicked_Lambda([this, Settings]()
						{
							FString URL = "https://newcontrolpanel.eagle3dstreaming.com/developer-section";
							FE3DSAutomationToolsModule::OpenURL(URL);
							return(FReply::Handled());
						})
			]
			
	];

}

#undef LOCTEXT_NAMESPACE
