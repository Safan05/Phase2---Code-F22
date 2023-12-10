#include "CTri.h"
#include<fstream>
int area_cal(int x1, int x2, int x3, int y1, int y2, int y3) {
	int area = abs((x1 * y2) - (x1 * y3) - (y1 * x2) + (y1 * x3) + (y3 * x2) - (y2 * x3));
	return area;
}
CTri::CTri()
{
}
CTri::CTri(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Vertex1 = P1;
	Vertex2 = P2;
	Vertex3 = P3;
}

void CTri::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a triangle on the screen	
	pOut->DrawTri(Vertex1, Vertex2, Vertex3, FigGfxInfo, Selected);

}
bool CTri::is_inside(int x, int y) const {
	int area, a1, a2, a3;
	area = area_cal(Vertex1.x, Vertex2.x, Vertex3.x, Vertex1.y, Vertex2.y, Vertex3.y);
	a1 = area_cal(x, Vertex2.x, Vertex3.x, y, Vertex2.y, Vertex3.y);
	a2 = area_cal(Vertex1.x, x, Vertex3.x, Vertex1.y, y, Vertex3.y);
	a3 = area_cal(Vertex1.x, Vertex2.x, x, Vertex1.y, Vertex2.y, y);
	if ((a1 + a2 + a3) == area)
		return 1;
	return 0;
}

void CTri::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("Triangle  ID " + std::to_string(ID));
}

void CTri::Save(ofstream& OutFile)
{
	OutFile << "TRIANG\t" << ID << "\t" << Vertex1.x << "\t" << Vertex1.y << "\t" << Vertex2.x << "\t" << Vertex2.y << "\t" << Vertex3.x << "\t" << Vertex3.y << "\t" << GetDrawClrName() << "\t" << GetFillClrName()<<endl;
}

void CTri::Load(ifstream& Infile)
{
	Infile >> ID >> Vertex1.x >> Vertex1.y >> Vertex2.x >> Vertex2.y >> Vertex3.x >> Vertex3.y >> DrawColor >> FillColor;
	SetDrawClrName();
	SetFillClrName();
}
