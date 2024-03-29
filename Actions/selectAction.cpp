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
	
	
		ReadActionParameters();
		Output* pOut = pManager->GetOutput();
		CFigure* d = pManager->GetFigure(P.x, P.y);
		if (d != NULL) {
			if (d->IsSelected() == 0) {
		      	if(pManager->Get_selected()!=NULL)
					pManager->Get_selected()->SetSelected(0);
				(d->SetSelected(1));
				d->PrintInfo(pOut);
				(pManager->set_selected(d));
				
			}
			else {
				pManager->Get_selected()->SetSelected(0);	
				pManager->set_selected(NULL);
			}
			if (pManager->GetIsRec())
			{
				CFigure* d1 = d->copy();
				d1->setID(d->GetID());

				pManager->AddRECFig(d1);
			}
		}
		
	
}