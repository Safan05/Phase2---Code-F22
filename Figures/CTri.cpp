#include "CTri.h"
#include<fstream>
int mini(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}
#include "..\ApplicationManager.h"
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
	Center.x = (Vertex1.x+ Vertex2.x+ Vertex3.x)/3;
	Center.y = (Vertex1.y + Vertex2.y + Vertex3.y) / 3;
}
char CTri::type() {
	return 'T';
}
CFigure* CTri::copy() {
	CTri* c = new CTri(*this);
	return c;
};
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
	pOut->PrintMessage("Triangle  ID " + std::to_string(ID) + "       Vertex 1 ( " + std::to_string(Vertex1.x) + " , " + std::to_string(Vertex1.y) + " ) " + "       Vertex 2 ( " + std::to_string(Vertex2.x) + " , " + std::to_string(Vertex2.y) + " ) " + +"       Vertex 3 ( " + std::to_string(Vertex3.x) + " , " + std::to_string(Vertex3.y) + " ) ");
}

void CTri::Save(ofstream& OutFile)
{
	OutFile << "TRIANG\t" << ID << "\t" << Vertex1.x << "\t" << Vertex1.y << "\t" << Vertex2.x << "\t" << Vertex2.y << "\t" << Vertex3.x << "\t" << Vertex3.y << "\t" << GetDrawClrName() << "\t";
	if (FigGfxInfo.isFilled) {
		OutFile << GetFillClrName() << "\n";
	}
	else OutFile << "NO_FILL\n";
}

void CTri::Load(ifstream& Infile)
{
	Infile >> ID >> Vertex1.x >> Vertex1.y >> Vertex2.x >> Vertex2.y >> Vertex3.x >> Vertex3.y >> DrawColor ;
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
void CTri::Move(Point c, Output* out)
{
	Point v1,v2, v3;
	int Xcc1 = CalcDistfromCenter(Vertex1, Center, 'x');
	int Xcc2 = CalcDistfromCenter(Vertex2, Center, 'x');
	int Xcc3 = CalcDistfromCenter(Vertex3, Center, 'x');
	int Ycc1 = CalcDistfromCenter(Vertex1, Center, 'y');
	int Ycc2 = CalcDistfromCenter(Vertex2, Center, 'y');
	int Ycc3 = CalcDistfromCenter(Vertex3, Center, 'y');
	v1.x = c.x + Xcc1;
	v2.x = c.x + Xcc2;
	v3.x = c.x + Xcc3;
	v1.y = c.y + Ycc1;
	v2.y = c.y + Ycc2;
	v3.y = c.y + Ycc3;
	if ((c.y > UI.ToolBarHeight) && (c.y < UI.height - UI.StatusBarHeight) && (v2.y > UI.ToolBarHeight) && (v2.y < UI.height - UI.StatusBarHeight) && (v3.y > UI.ToolBarHeight) && (v3.y < UI.height - UI.StatusBarHeight) && (v1.y > UI.ToolBarHeight) && (v1.y < UI.height - UI.StatusBarHeight))
	{
		Vertex1 = v1;
		Vertex2 = v2;
		Vertex3 = v3;
		Center = c ;
	}
	else
		out->PrintMessage("Invalid point");
}
void CTri::Resize(Point c, Output* out){
 {
		if ((c.y > UI.ToolBarHeight) && (c.y < UI.height - UI.StatusBarHeight) && (Vertex2.y > UI.ToolBarHeight) && (Vertex2.y < UI.height - UI.StatusBarHeight) && (Vertex3.y > UI.ToolBarHeight) && (Vertex3.y < UI.height - UI.StatusBarHeight))
		{
			Vertex1 = c;
		}
		else
			out->PrintMessage("Invalid point");
	}
}

int CTri::CalcDistfromCenter(Point P, Point C, char cord)
{
	if (cord == 'x') {
		int a = P.x - C.x;
		return a;
	}
	else if (cord == 'y') {
		int b = P.y - C.y;
		return b;
	}
}

Point CTri::GetCenter()
{
	return Point();
}

void CTri::Undocolor(ApplicationManager* p)
{
	FigGfxInfo.FillClr = p->Getfillcolor();
	p->defill();
	if (p->Getnumoffill() == 0 && FigGfxInfo.isFilled == true)
	{
		FigGfxInfo.isFilled = false;
	}
}

void CTri::UndoMove(ApplicationManager* p)
{
}

void CTri::RedoMove(ApplicationManager* p)
{
}

void CTri::Undocolordraw(ApplicationManager* p)
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

void CTri::Redocolor(ApplicationManager* p)
{
	if (p->Getnumoffill() == 0 && FigGfxInfo.isFilled == false)
	{
		FigGfxInfo.isFilled = true;
	}
	p->Incrementfill();
	FigGfxInfo.FillClr = p->GetfillRedo();
}

void CTri::Redocolordraw(ApplicationManager* p)
{
	p->Incrementdraw();
	FigGfxInfo.DrawClr = p->GetdrawRedo();
}