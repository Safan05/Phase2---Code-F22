#include "CCirc.h"
#include<fstream>
CCirc::CCirc()
{
}
CCirc::CCirc(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	point = P2;
}

void CCirc::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a circle on the screen	
	pOut->DrawCirc(Center, point, FigGfxInfo, Selected);

}
bool CCirc::is_inside(int x, int y) const {
	int a, b, c, d, r1, r2;
	a = abs(Center.x - point.x);
	b = abs(Center.y - point.y);
	r1 = sqrt(a * a + b * b);
	c = abs(Center.x - x);
	d = abs(Center.y - y);
	r2 = sqrt(c * c + d * d);
	if (r2 <= r1)
		return 1;
	return 0;
}
void CCirc::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("Circle    ID " + std::to_string(ID));
}
void CCirc::Save(ofstream& OutFile)
{
	OutFile << "CIRC\t" << ID << "\t" << Center.x << "\t" << Center.y << "\t" << point.x << "\t" << point.y << "\t" << GetDrawClrName() << "\t";
	if (FigGfxInfo.isFilled) {
		OutFile << GetFillClrName() << endl;
	}
	else OutFile << "NO_FILL\n";
}
void CCirc::Load(ifstream& Infile)
{
	Infile >> ID >> Center.x >> Center.y >> point.x >> point.y >> DrawColor;
	SetDrawClrName();
	Infile >> FillColor;
	if (FillColor == "NO_FILL") {
		FigGfxInfo.isFilled = 0;
	}
	else SetFillClrName();
}
;