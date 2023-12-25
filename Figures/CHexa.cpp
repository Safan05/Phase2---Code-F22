#include "CHexa.h"
#include<fstream>
#include "..\ApplicationManager.h"
double area_cal(double x1, double x2, double x3, double y1, double y2, double y3) {
	double area = abs((x1 * y2) - (x1 * y3) - (y1 * x2) + (y1 * x3) + (y3 * x2) - (y2 * x3));
	return area;
}
CHexa::CHexa()
{
}
CHexa::CHexa(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	SideLength = 100;
	Center = P1;
}

void CHexa::Draw(Output* pOut) const
{
	//Call Output::Drawhexa to draw a hexagon on the screen	
	pOut->Drawhexa(Center, FigGfxInfo, Selected);

}
CFigure* CHexa::copy() {
	CHexa* c = new CHexa(*this);
	return c;
};
char CHexa::type() {
	return 'H';
}
bool CHexa::is_inside(int x, int y) const {
	
	double cos = SideLength * sqrt(3) / 2;
	double area_hex = (3.0/2)*(sqrt(3))*SideLength*SideLength*2;
	          //area_cal(P1.x         , x, P2.x         ,P1.y    ,y,         P2,y)
	double a1 = area_cal(Center.x + SideLength, x, Center.x + SideLength/2.0,Center.y,y,Center.y-cos );
	double a2 = area_cal(Center.x + SideLength, x, Center.x + SideLength / 2.0, Center.y, y, Center.y + cos);
	double a3 = area_cal(Center.x - SideLength/2.0, x, Center.x + SideLength / 2.0, Center.y+ cos, y, Center.y + cos);
	double a4 = area_cal(Center.x - SideLength / 2.0, x, Center.x - SideLength, Center.y + cos, y, Center.y );
	double a5 = area_cal(Center.x - SideLength / 2.0, x, Center.x - SideLength, Center.y - cos, y, Center.y);
	double a6 = area_cal(Center.x - SideLength / 2.0, x, Center.x + SideLength / 2.0, Center.y - cos, y, Center.y- cos);
	double flag = a1 + a2 + a3 + a4 + a5 + a6;
	if(floor(flag)==floor(area_hex))
	return 1;
	return 0;
}
void CHexa::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("Hexagon    ID " + std::to_string(ID)+ "       Center ( " + std::to_string(Center.x) + " , " + std::to_string(Center.y) + " ) " + "      Side = 50");
}

void CHexa::Save(ofstream& OutFile)
{
	OutFile << "HEXA\t" << ID << "\t" << Center.x << "\t" << Center.y << "\t" << GetDrawClrName() << "\t";
	if (FigGfxInfo.isFilled) {
		OutFile << GetFillClrName() << "\n";
	}
	else OutFile << "NO_FILL\n";

}

void CHexa::Load(ifstream& Infile)
{
	Infile >> ID >> Center.x >> Center.y >> DrawColor ;
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

void CHexa::Move(Point c, Output* out)
{
	if ((((c.y + 43.3 - UI.ToolBarHeight) > 86.6) && ((UI.height - UI.StatusBarHeight) - c.y >= 43.3)))
	{
		Center = c;
	}
	else
		out->PrintMessage("Invalid point");
}
void CHexa::Resize(Point c, Output* out) {

}

Point CHexa::GetCenter()
{
	return Center;
}

void CHexa::Undocolor(ApplicationManager* p)
{
	FigGfxInfo.FillClr = p->Getfillcolor();
	p->defill();
	if (p->Getnumoffill() == 0 && FigGfxInfo.isFilled == true)
	{
		FigGfxInfo.isFilled = false;
	}
}

void CHexa::UndoMove(ApplicationManager* p)
{

	Center = p->Getpoint();
}

void CHexa::RedoMove(ApplicationManager* p)
{
	Center = p->GetpointRedo();
}

void CHexa::Undocolordraw(ApplicationManager* p)
{
	if (p->Getnumofdraw() != 0)
	{
		FigGfxInfo.DrawClr = p->Getdrawcolor();
		p->deldraw();
	}
	else
	{
		FigGfxInfo.DrawClr = BLUE;
	}
}

void CHexa::Redocolor(ApplicationManager* p)
{
	if (p->Getnumoffill() == 0 && FigGfxInfo.isFilled == false)
	{
		FigGfxInfo.isFilled = true;
	}
	p->Incrementfill();
	FigGfxInfo.FillClr = p->GetfillRedo();
}

void CHexa::Redocolordraw(ApplicationManager* p)
{
	p->Incrementdraw();
	FigGfxInfo.DrawClr = p->GetdrawRedo();
}
