#include "LoadAction.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"
#include "..\Figures/CCirc.h"
#include "..\Figures/CHexa.h"
#include "..\Figures/CRectangle.h"
#include "..\Figures/CSquare.h"
#include "..\Figures/CTri.h"
#include "..\Actions\AddRectAction.h"
#include "..\Actions\Action.h"
#include<fstream>
LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp)
{}
void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter the file to load");
	FileName = pIn->GetString(pOut);
	pOut->PrintMessage("The File's name is " + FileName);
}

void LoadAction::Execute()
{
	pManager->Clearall();
	ReadActionParameters();
	ifstream In;
	string DrawColor, FillColor, Figure;
	In.open(FileName, ios::in);
	In >> DrawColor >> FillColor;
	if (DrawColor == "RED")    UI.DrawColor = RED;
	else if (DrawColor == "ORANGE") UI.DrawColor = ORANGE;
	else if (DrawColor == "BLUE")   UI.DrawColor = BLUE;
	else if (DrawColor == "GREEN")  UI.DrawColor = GREEN;
	else if (DrawColor == "YELLOW") UI.DrawColor = YELLOW;
	else if (DrawColor == "BLACK")  UI.DrawColor = BLACK;

	if (FillColor == "RED")    UI.FillColor = RED;
	else if (FillColor == "ORANGE") UI.FillColor = ORANGE;
	else if (FillColor == "BLUE")   UI.FillColor = BLUE;
	else if (FillColor == "GREEN")  UI.FillColor = GREEN;
	else if (FillColor == "YELLOW") UI.FillColor = YELLOW;
	else if (FillColor == "BLACK")  UI.FillColor = BLACK;
	int n;
	In >> n;
	for (int i = 0; i < n; i++) {
		In >> Figure;
		if (Figure == "RECT") {
			CRectangle* R = new CRectangle;
			R->Load(In);
			pManager->AddFigure(R);
		}
		else if (Figure == "SQUARE") {
			CSquare* S = new CSquare;
			S->Load(In);
			pManager->AddFigure(S);
		}
		else if (Figure == "TRIANG") {
			CTri* T = new CTri;
			T->Load(In);
			pManager->AddFigure(T);
		}
		else if (Figure == "CIRC") {
			CCirc* C = new CCirc;
			C->Load(In);
			pManager->AddFigure(C);
		}
		else if (Figure == "HEXA") {
			CHexa* H = new CHexa;
			H->Load(In);
			pManager->AddFigure(H);
		}

	}
	In.close();
};
