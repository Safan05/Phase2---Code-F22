#pragma once
#include "CFigure.h"
class CCirc : public CFigure
{
private:
	Point Center;
	Point point;
public:
	CCirc(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool is_inside(int x,int y) const;
	void PrintInfo(Output* pOut);
	void Save(ofstream& OutFile);
};