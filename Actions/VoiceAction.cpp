#include "VoiceAction.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"
#include <Windows.h>
#include <mmsystem.h>
#include <Mmsystem.h>
#include <mciapi.h>
#include "VoiceAction.h"
#pragma comment (lib, "Winmm.lib")
bool VoiceAction::voice = false;
VoiceAction::VoiceAction(ApplicationManager* pApp) :Action(pApp) {};//constructor
void VoiceAction::ReadActionParameters() {
};

//Execute action (code depends on action type)
void VoiceAction::Execute() {
	voice = !voice;
		PlaySound(TEXT("voice\\Voice.wav"), NULL, SND_FILENAME | SND_ASYNC);
		Output* pOut = pManager->GetOutput();
		if(voice)
		pOut->PrintMessage("Voice is now turned on");
		else
		pOut->PrintMessage("Voice is now turned off");

};