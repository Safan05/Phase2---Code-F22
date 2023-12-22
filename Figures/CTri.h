#pragma once
#include "CFigure.h"

class CTri : public CFigure
{
private:
	Point Vertex1;
	Point Vertex2;
	Point Vertex3;
	Point Center;
public:
	CTri();
	CTri(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool is_inside(int x, int y) const;
	void PrintInfo(Output* pOut);
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	virtual void Move(Point c, Output* out);
	int CalcDistfromCenter(Point P,Point C,char cord);
	virtual char type();
	virtual void ReSize(Point c, Output* out);
	virtual CFigure* copy();

};
