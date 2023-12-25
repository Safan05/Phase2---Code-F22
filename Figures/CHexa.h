#pragma once
#include "CFigure.h"
class CHexa :public CFigure
{
private:
	int SideLength;
	Point Center;
	double Height;
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
	virtual void Resize(Point c, Output* out);
	virtual CFigure* copy();
	virtual void Undocolor(ApplicationManager* p);
	virtual void UndoMove(ApplicationManager* p);
	virtual Point GetCenter();
	virtual void RedoMove(ApplicationManager* p);
	virtual void Undocolordraw(ApplicationManager* p);
	virtual void Redocolor(ApplicationManager* p);
	virtual void Redocolordraw(ApplicationManager* p);
};