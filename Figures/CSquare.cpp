#include "CSquare.h"
#include<fstream>
CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}

void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSquare to draw a square on the screen	
	pOut->DrawSQ(Center, FigGfxInfo, Selected);

}
bool CSquare::is_inside(int x, int y) const {
	if (x > Center.x + 50 || x<Center.x - 50 || y>Center.y + 50 || y < Center.y - 50)
		return 0;
	return 1;
}

void CSquare::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("Square   ID " + std::to_string(ID));
}

void CSquare::Save(ofstream& OutFile)
{
	OutFile << "SQUARE\t" << ID << Center.x << "\t" << Center.y << "\t" << GetDrawClrName() << "\t" << GetFillClrName()<<endl;
}
