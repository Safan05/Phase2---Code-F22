#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
//Base class for all figures
class ApplicationManager;
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	bool hidden;
	string DrawColor, FillColor,Selectedstring;
	/// Add more parameters if needed.

public:
	virtual CFigure* copy()=0;
	static int LastID;
	CFigure();
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool s);	//select/unselect the figure
	void Sethidden(bool h);	//hide/unhide the figure
	bool IsSelected() const;	//check whether fig is selected
	bool Ishidden() const;	//check whether fig is hidden
	virtual bool is_inside(int x,int y) const = 0;
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual char type() = 0; //Return a character which indicates the figure type instead of using dynamic cast
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	color get_color();
	string GetDrawClrName();
	string GetFillClrName();
	void CFigure::SetDrawClrName();
	void CFigure::SetFillClrName();
	int GetID();
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure
	///Decide the parameters that you should pass to each function	
	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
	//print all figure info on the status bar
	virtual void PrintInfo(Output* pOut) = 0;	
	virtual void Move(Point c, Output* out) = 0;	
	virtual void Resize(Point c, Output* out) = 0;
	void setID(int i);
};

#endif