#include "AddTriAction.h"
#include "..\Figures\CTri.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <mmsystem.h>
#include <Mmsystem.h>
#include <mciapi.h>
#include "VoiceAction.h"
#pragma comment (lib, "Winmm.lib")
AddTriAction::AddTriAction(ApplicationManager* pApp):Action(pApp)
{
	if (VoiceAction::voice)
		PlaySound(TEXT("voice\\triangle.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void AddTriAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first vertex");

	//Read 1st Vertex and store in point Vertex1
	pIn->GetPointClicked(Vertex1.x, Vertex1.y);
	if (ValidP(Vertex1)) {
		pOut->PrintMessage("New Triangle: Click at second vertex");

		//Read 2nd Vertex and store in point Vertex2
		pIn->GetPointClicked(Vertex2.x, Vertex2.y);
		if (ValidP(Vertex2)) {
			pOut->PrintMessage("New Triangle: Click at thrid vertex");

			//Read 3nd Vertex and store in point Vertex3
			pIn->GetPointClicked(Vertex3.x, Vertex3.y);
			if (ValidP(Vertex3)) {
				TriGfxInfo.isFilled = false;	//default is not filled
				//get drawing, filling colors and pen width from the interface
				TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
				TriGfxInfo.FillClr = pOut->getCrntFillColor();

				pOut->ClearStatusBar();
				}
			else pOut->PrintMessage("Invalid Point, Can't place point here");
			}
		else pOut->PrintMessage("Invalid Point, Can't place point here");
	}
	else pOut->PrintMessage("Invalid Point, Can't place point here");
}
bool AddTriAction::Valid()
{
	return (Vertex1.y > UI.ToolBarHeight) && (Vertex1.y < UI.height - UI.StatusBarHeight) && (Vertex2.y > UI.ToolBarHeight) && (Vertex2.y < UI.height - UI.StatusBarHeight)&& (Vertex3.y > UI.ToolBarHeight) && (Vertex3.y < UI.height - UI.StatusBarHeight);
}

bool AddTriAction::ValidP(Point P)
{
	return (P.y > UI.ToolBarHeight) && (P.y < UI.height - UI.StatusBarHeight);
}


void AddTriAction::Execute()
{
	//This action needs to read some parameters first

	
		ReadActionParameters();
		if (Valid()) {
			//Create a triangle with the parameters read from the user
			CTri* T = new CTri(Vertex1, Vertex2, Vertex3, TriGfxInfo);

			//Add the triangle to the list of figures
			pManager->AddFigure(T);
			if (pManager->GetIsRec()) {
				CTri* T1 = new CTri(Vertex1, Vertex2, Vertex3, TriGfxInfo);
				pManager->AddRECFig(T1);
			}
		}
		
	
}
