#include "MoveAction.h"
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "VoiceAction.h"
MoveAction::MoveAction(ApplicationManager* pApp) :Action(pApp)
{
	if (VoiceAction::voice)
		PlaySound(TEXT("voice\\move figure.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void MoveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click to move figure");
	pIn->GetPointClicked(d.x, d.y);
	pOut->ClearStatusBar();
}

void MoveAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	CFigure* f = pManager->Get_selected();
	Point c;
	if (f != NULL)
	{
		pManager->Addpoint(d);
		c = f->GetCenter();
		pManager->Addpoint(c);
		f->Move(d, pOut);
		pManager->AddfigselectedM(f);
		pManager->AddUndoAction(this);
		if (pManager->GetIsRec())
		{
			CFigure* d1 = f->copy();
			d1->setID(f->GetID());
			pManager->AddRECFig(d1);
		}

	}
	else
		pOut->PrintMessage("Move Figure : select figure");
}