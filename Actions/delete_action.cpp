#include "delete_action.h"
#include "selectAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <mmsystem.h>
#include <Mmsystem.h>
#include <mciapi.h>
#include "VoiceAction.h"
#pragma comment (lib, "Winmm.lib")
delete_action::delete_action(ApplicationManager* pApp) :Action(pApp) {
	if (VoiceAction::voice)
		PlaySound(TEXT("voice\\delete figure.wav"), NULL, SND_FILENAME | SND_ASYNC);
};//constructor

//Reads parameters required for action to execute (code depends on action type)
void delete_action::ReadActionParameters() {
};

//Execute action (code depends on action type)
void delete_action::Execute() {
	CFigure* f=pManager->Get_selected();
	pManager->deletefig(f);
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
}