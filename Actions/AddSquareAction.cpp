#include "AddSquareAction.h"
#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <Windows.h>
#include <mmsystem.h>
#include <Mmsystem.h>
#include <mciapi.h>
#include "VoiceAction.h"
#pragma comment (lib, "Winmm.lib")
AddSquareAction::AddSquareAction(ApplicationManager* pApp) :Action(pApp)
{
	if(VoiceAction::voice)
	PlaySound(TEXT("voice\\square.wav"),NULL,SND_FILENAME|SND_ASYNC);
}

void AddSquareAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at the Center");
	//Read center and store in point P
	pIn->GetPointClicked(P.x, P.y);
	if (ValidP(P)) {
		if (Valid()) {
			SquareGfxInfo.isFilled = false;	//default is not filled
			//get drawing, filling colors and pen width from the interface
			SquareGfxInfo.DrawClr = pOut->getCrntDrawColor();
			SquareGfxInfo.FillClr = pOut->getCrntFillColor();

			pOut->ClearStatusBar();
		}
		else  pOut->PrintMessage("Invalid, Can't draw in Toolbar");
	}
	else  pOut->PrintMessage("Invalid Point, Can't place point here");
}

bool AddSquareAction::Valid()
{
	return (((P.y + 75 - UI.ToolBarHeight) > 150) && (UI.height - (P.y + 75) > UI.StatusBarHeight));
}

bool AddSquareAction::ValidP(Point P)
{
	return (P.y > UI.ToolBarHeight) && (P.y < UI.height - UI.StatusBarHeight);
}


void AddSquareAction::Execute()
{
	//This action needs to read some parameters first

	ReadActionParameters();
	if (Valid())
	{
		//Create a square with the parameters read from the user
		CSquare* S = new CSquare(P, SquareGfxInfo);

		//Add the square to the list of figures
		pManager->AddFigure(S);
		if (pManager->GetIsRec())
		{
			CSquare* S1 = new CSquare(P, SquareGfxInfo);
			pManager->AddRECFig(S1);
		}

	}

}