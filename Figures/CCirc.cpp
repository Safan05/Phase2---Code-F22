#include "CCirc.h"
#include<fstream>
CCirc::CCirc()
{
}
CCirc::CCirc(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	point = P2;
	int a, b;
	a = abs(Center.x - point.x);
	b = abs(Center.y - point.y);
	r = sqrt(a * a + b * b);
}

void CCirc::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a circle on the screen	
	pOut->DrawCirc(Center, point, FigGfxInfo, Selected);

}
char CCirc::type() {
	return 'C';
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
	pOut->PrintMessage("Circle    ID " + std::to_string(ID) + "       Center ( " + std::to_string(Center.x) + " , " + std::to_string(Center.y) + " ) " + "      Radius = " + std::to_string(r));
}
void CCirc::Save(ofstream& OutFile)
{
	OutFile << "CIRC\t" << ID << "\t" << Center.x << "\t" << Center.y << "\t" << point.x << "\t" << point.y << "\t" << GetDrawClrName() << "\t";
	if (FigGfxInfo.isFilled) {
		OutFile << GetFillClrName() << "\t";
	}
	else OutFile << "NO_FILL\t";
	if (IsSelected()) {
		OutFile << "Selected\n";
	}
	else OutFile << "NotSelected\n";
}
void CCirc::Load(ifstream& Infile)
{
	Infile >> ID >> Center.x >> Center.y >> point.x >> point.y >> DrawColor;
	SetDrawClrName();
	Infile >> FillColor;
	if (FillColor == "NO_FILL") {
		FigGfxInfo.isFilled = 0;
	}
	else {
		FigGfxInfo.isFilled = 1;
		SetFillClrName();
	}
	Infile >> Selectedstring;
	if (Selectedstring == "Selected") {
		SetSelected(true);
	}
	else SetSelected(false);
}

void CCirc::Move(Point c, Output* out)
{
	Point c2;
	int x = point.x - Center.x;
	int y = point.y - Center.y;
	c2.x = c.x + x;
	c2.y = c.y + y;
	int a, b, r;
	a = abs(c.x - c2.x);
	b = abs(c.y - c2.y);
	r = sqrt(a * a + b * b);
	if ((((c.y - UI.ToolBarHeight) >= r) && ((UI.height - UI.StatusBarHeight) - c.y >= r)))
	{
		Center = c;
		point = c2;

	}
	else
		out->PrintMessage("Invalid point");


}
void CCirc::ReSize(Point c, Output* out)
{
	Point c2;
	if ((((c.y - UI.ToolBarHeight) >= r) && ((UI.height - UI.StatusBarHeight) - c.y >= r)))
	{
		point = c;

	}
	else
		out->PrintMessage("Invalid point");

}