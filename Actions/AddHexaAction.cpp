#include "AddHexaAction.h"
#include "..\Figures\CHexa.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <mmsystem.h>
#include <Mmsystem.h>
#include <mciapi.h>
#include "VoiceAction.h"
#pragma comment (lib, "Winmm.lib")
AddHexaAction::AddHexaAction(ApplicationManager* pApp) :Action(pApp)
{
	if (VoiceAction::voice)
		PlaySound(TEXT("voice\\hexagon.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void AddHexaAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at the Center");
	//Read center and store in point center
	pIn->GetPointClicked(center.x, center.y);
	if (ValidP(center)) {
		if (Valid()) {
			HexaGfxInfo.isFilled = false;	//default is not filled
			//get drawing, filling colors and pen width from the interface
			HexaGfxInfo.DrawClr = pOut->getCrntDrawColor();
			HexaGfxInfo.FillClr = pOut->getCrntFillColor();

			pOut->ClearStatusBar();
		}
		else pOut->PrintMessage("Invalid, Can't draw in Toolbar");
	}
	else pOut->PrintMessage("Invalid Point, Can't place point here");
}

bool AddHexaAction::Valid()
{
	return (((center.y + 43.3 - UI.ToolBarHeight) > 86.6) && ((UI.height - UI.StatusBarHeight) - center.y >= 43.3));
}

bool AddHexaAction::ValidP(Point P)
{
	return (P.y > UI.ToolBarHeight) && (P.y < UI.height - UI.StatusBarHeight);
}

void AddHexaAction::Execute()
{
	//This action needs to read some parameters first
	
	
		ReadActionParameters();
		if (Valid()) {
			//Create a hexagon with the parameters read from the user
			CHexa* H = new CHexa(center, HexaGfxInfo);

			//Add the hexagon to the list of figures
			pManager->AddFigure(H);
			if (pManager->GetIsRec()) {
				CHexa*H1 = new CHexa(center, HexaGfxInfo);
				pManager->AddRECFig(H1);
			
			}
		}

		
	
}