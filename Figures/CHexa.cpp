#include "CHexa.h"
#include<fstream>
double area_cal(int x1, int x2, int x3, int y1, int y2, int y3) {
	double area = abs((x1 * y2) - (x1 * y3) - (y1 * x2) + (y1 * x3) + (y3 * x2) - (y2 * x3));
	return area;
}
CHexa::CHexa()
{
}
CHexa::CHexa(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}

void CHexa::Draw(Output* pOut) const
{
	//Call Output::Drawhexa to draw a hexagon on the screen	
	pOut->Drawhexa(Center, FigGfxInfo, Selected);

}
bool CHexa::is_inside(int x, int y) const {
	double area_hex = 13050;
	          //area_cal(P1.x         , x, P2.x         ,P1.y    ,y,         P2,y)
	double a1 = area_cal(Center.x + 50, x, Center.x + 25,Center.y,y,Center.y-43.3 );
	double a2 = area_cal(Center.x + 50, x, Center.x + 25, Center.y, y, Center.y + 43.3);
	double a3 = area_cal(Center.x - 25, x, Center.x + 25, Center.y+43.3, y, Center.y + 43.3);
	double a4 = area_cal(Center.x - 25, x, Center.x -50, Center.y + 43.3, y, Center.y );
	double a5 = area_cal(Center.x - 25, x, Center.x - 50, Center.y - 43.3, y, Center.y);
	double a6 = area_cal(Center.x - 25, x, Center.x + 25, Center.y - 43.3, y, Center.y-43.3);
	double flag = a1 + a2 + a3 + a4 + a5 + a6;
	if(flag==area_hex)
	return 1;
	return 0;
}
void CHexa::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("Hexagon    ID " + std::to_string(ID));
}

void CHexa::Save(ofstream& OutFile)
{
	OutFile << "HEXA\t" << ID << "\t" << Center.x << "\t" << Center.y << "\t" << GetDrawClrName() << "\t";
	if (FigGfxInfo.isFilled) {
		OutFile << GetFillClrName() << endl;
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
