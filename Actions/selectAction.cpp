#include "selectAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <mmsystem.h>
#include <Mmsystem.h>
#include <mciapi.h>
#include "VoiceAction.h"
#pragma comment (lib, "Winmm.lib")
selectAction::selectAction(ApplicationManager* pApp) :Action(pApp) {
	if (VoiceAction::voice)
		PlaySound(TEXT("voice\\select figure.wav"), NULL, SND_FILENAME | SND_ASYNC);
};//constructor

//Reads parameters required for action to execute (code depends on action type)
void selectAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("click point to Select figure");
	pIn->GetPointClicked(P.x, P.y);
	pOut->ClearStatusBar();
};

//Execute action (code depends on action type)
void selectAction::Execute() {
	if (!pManager->GetIsPlay()) 
	{
		ReadActionParameters();
		Output* pOut = pManager->GetOutput();
		CFigure* d = pManager->GetFigure(P.x, P.y);
		if (d != NULL) {
			if (d->IsSelected() == 0) {
				pManager->de_select();
				(d->SetSelected(1));
				d->PrintInfo(pOut);
				(pManager->set_selected(d));
			}
			else {
				(pManager->de_select());
				pManager->set_selected(NULL);
			}

		}
		if (pManager->GetIsRec())
			pManager->AddAction(this);
	}
}