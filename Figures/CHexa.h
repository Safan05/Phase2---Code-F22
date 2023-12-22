#pragma once
#include "CFigure.h"
class CHexa :public CFigure
{
private:
	Point Center;
public:
	CHexa();
	CHexa(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool is_inside(int x, int y) const;
	void PrintInfo(Output* pOut);
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	virtual void Move(Point c, Output* out);
	virtual char type();
	virtual void ReSize(Point c, Output* out);
	virtual CFigure* copy();
};