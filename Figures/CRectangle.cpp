#include "CRectangle.h"
#include <fstream>
#include "..\ApplicationManager.h"
CRectangle::CRectangle()
{}

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}


void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle::is_inside(int x, int y) const {
	int h = abs(Corner1.y - Corner2.y);
	int w = abs(Corner1.x - Corner2.x);
	int m_x = (Corner1.x + Corner2.x) / 2;
	int m_y = (Corner1.y + Corner2.y) / 2;
	if (x > m_x + w / 2 || x<m_x - w / 2 || y>m_y + h / 2 || y < m_y - h / 2)
		return 0;
	return 1;
}

void CRectangle::PrintInfo(Output* pOut)
{
	int h = abs(Corner1.y - Corner2.y);
	int w = abs(Corner1.x - Corner2.x);
	pOut->PrintMessage("Rectangle   ID " + std::to_string(ID) + "       Corner 1 ( " + std::to_string(Corner1.x) + " , " + std::to_string(Corner1.y) + " ) " + "      Corner 2 ( " + std::to_string(Corner1.x) + " , " + std::to_string(Corner1.y) + " ) " +"   Length = " + std::to_string(w) + "  Width = " + std::to_string(h));
}

void CRectangle::Save(ofstream& OutFile)
{
	OutFile << "RECT\t" << ID << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x << "\t" << Corner2.y << "\t" << GetDrawClrName() << "\t";
	if (FigGfxInfo.isFilled) {
		OutFile << GetFillClrName() << endl;
	}
	else OutFile << "NO_FILL\n";
}

void CRectangle::Load(ifstream& Infile)
{
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> DrawColor;
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
void CRectangle::Move(Point c, Output* out)
{
	Point c2;
	int x = Corner2.x - Corner1.x;
	int y = Corner2.y - Corner1.y;
	c2.x = c.x + x;
	c2.y = c.y + y;
	if (((c.y > UI.ToolBarHeight) && (c.y < UI.height - UI.StatusBarHeight)) && ((c2.y > UI.ToolBarHeight) && (c2.y < UI.height - UI.StatusBarHeight)))
	{

		Corner1 = c;
		Corner2.x = c2.x;
		Corner2.y = c2.y;
	}
	else
		out->PrintMessage("Invalid point");
}