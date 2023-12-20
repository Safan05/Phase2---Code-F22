#include "CSquare.h"
#include<fstream>
CSquare::CSquare()
{
}
CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}

void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSquare to draw a square on the screen	
	pOut->DrawSQ(Center, FigGfxInfo, Selected);

}
char CSquare::type() {
	return 'S';
}
bool CSquare::is_inside(int x, int y) const {
	if (x > Center.x + 75 || x<Center.x - 75 || y>Center.y + 75 || y < Center.y - 75)
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
		OutFile << GetFillClrName() << endl;
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
	if (((c.y + 50 - UI.ToolBarHeight) > 100) && (UI.height - (c.y + 50) > UI.StatusBarHeight))
	{
		Center = c;
	}
	else
		out->PrintMessage("Invalid point");

}