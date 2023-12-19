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
	if (f != NULL)
	{
		if (f->IsSelected())
		{
			f->Move(d, pOut);

		}
		else
			pOut->PrintMessage("Move Figure : select figure");
	}
}