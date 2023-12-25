#include "CSquare.h"
#include<fstream>
#include "..\ApplicationManager.h"
CSquare::CSquare()
{
}
CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	SideLength = 150;
}

void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSquare to draw a square on the screen	
	pOut->DrawSQ(Center, FigGfxInfo, Selected,SideLength);

}
char CSquare::type() {
	return 'S';
}
CFigure* CSquare::copy() {
	CSquare* c = new CSquare(*this);
	return c;
};
bool CSquare::is_inside(int x, int y) const {
	if (x > Center.x + SideLength/2 || x<Center.x - SideLength/2 || y>Center.y + SideLength/2 || y < Center.y - SideLength/2)
		return 0;
	return 1;
}

void CSquare::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("Square   ID " + std::to_string(ID) + "       Center ( " + std::to_string(Center.x) + " , " + std::to_string(Center.y) + " ) " + "      Length = 100");
}

void CSquare::Save(ofstream& OutFile)
{
	OutFile << "SQUARE\t" << ID << "\t" << Center.x << "\t" << Center.y << "\t" << GetDrawClrName() << "\t" ;
	if (FigGfxInfo.isFilled) {
		OutFile << GetFillClrName() << "\n";
	}
	else OutFile << "NO_FILL\n";
}

void CSquare::Load(ifstream& Infile)
{
	Infile >> ID >> Center.x >> Center.y >> DrawColor;
	SetDrawClrName();
	Infile >> FillColor;
	if (FillColor == "NO_FILL") {
		FigGfxInfo.isFilled = 0;
	}
	else {
		FigGfxInfo.isFilled = 1;
		SetFillClrName();
	}
}
void CSquare::Move(Point c, Output* out)
{
	if (((c.y + SideLength/2 - UI.ToolBarHeight) > SideLength) && (UI.height - (c.y + SideLength/2) > UI.StatusBarHeight))
	{
		Center = c;
	}
	else
		out->PrintMessage("Invalid point");

}
void CSquare::Resize(Point c, Output* out) {
	int a = c.x - Center.x;
	int b = c.y - Center.y;
	int S = sqrt(a * a + b * b)*sqrt(2);
	if (((Center.y + SideLength / 2 - UI.ToolBarHeight) > SideLength) && (UI.height - (Center.y + SideLength / 2) > UI.StatusBarHeight))
	{
		SideLength = S;
	}
	else
		out->PrintMessage("Invalid point");
}

Point CSquare::GetCenter()
{
	return Center;
}

void CSquare::UndoMove(ApplicationManager* p)
{
	Center = p->Getpoint();
}

void CSquare::Undocolor(ApplicationManager* p)
{
	FigGfxInfo.FillClr = p->Getfillcolor();
	p->defill();
	if (p->Getnumoffill() == 0 && FigGfxInfo.isFilled == true)
	{
		FigGfxInfo.isFilled = false;
	}
}

void CSquare::RedoMove(ApplicationManager* p)
{
	Center = p->GetpointRedo();
}

void CSquare::Undocolordraw(ApplicationManager* p)
{
	//if (p->Getnumofdraw() != 0)
	//{
	FigGfxInfo.DrawClr = p->Getdrawcolor();
	p->deldraw();
	//}
	/*else
	{
		FigGfxInfo.DrawClr = BLUE;
	}*/
}

void CSquare::Redocolor(ApplicationManager* p)
{
	if (p->Getnumoffill() == 0 && FigGfxInfo.isFilled == false)
	{
		FigGfxInfo.isFilled = true;
	}
	p->Incrementfill();
	FigGfxInfo.FillClr = p->GetfillRedo();
}

void CSquare::Redocolordraw(ApplicationManager* p)
{

	p->Incrementdraw();
	FigGfxInfo.DrawClr = p->GetdrawRedo();
}
