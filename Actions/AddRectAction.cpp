#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"
#include "..\Actions\FillingAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\GUI\UI_Info.h" 
#include <mmsystem.h>
#include <Mmsystem.h>
#include <mciapi.h>
#include "VoiceAction.h"
#pragma comment (lib, "Winmm.lib")
AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp)
{
	if (VoiceAction::voice)
		PlaySound(TEXT("voice\\rectangle.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void AddRectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	if (ValidP(P1)) {
		pOut->PrintMessage("New Rectangle: Click at second corner");
		//Read 2nd corner and store in point P2
		pIn->GetPointClicked(P2.x, P2.y);
		if (ValidP(P2)) {
			RectGfxInfo.isFilled = false;	//default is not filled
			RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
			RectGfxInfo.FillClr = pOut->getCrntFillColor();
			pOut->ClearStatusBar();

		}
		else pOut->PrintMessage("Invalid Point, Can't place point here");
	}
	 else pOut->PrintMessage("Invalid Point, Can't place point here");
}

bool AddRectAction::Valid()
{
	return (P1.y > UI.ToolBarHeight) && (P1.y < UI.height - UI.StatusBarHeight) && (P2.y > UI.ToolBarHeight) && (P2.y < UI.height - UI.StatusBarHeight);
}
bool AddRectAction::ValidP(Point P)
{
	return (P.y > UI.ToolBarHeight) && (P.y < UI.height - UI.StatusBarHeight) ;
}

//Execute the action
void AddRectAction::Execute() 
{
	//This action needs to read some parameters first
	//if (!pManager->GetIsPlay())
	//{
		ReadActionParameters();
		if (Valid()) {
			//Create a rectangle with the parameters read from the user
			CRectangle* R = new CRectangle(P1, P2, RectGfxInfo);

			//Add the rectangle to the list of figures
			pManager->AddFigure(R);
			if (pManager->GetIsRec()) 
			{
				CRectangle* R1 = new CRectangle(P1, P2, RectGfxInfo);
				R1->setID(R->GetID());
				pManager->AddRECFig(R1);
			}
			CRectangle* R1 = new CRectangle(P1, P2, RectGfxInfo);
			R1->setID(R->GetID());
			R1->Sethidden(1);
			pManager->AddUndo(R1);
		}


	//}
}
