#include "CFigure.h"
int CFigure::LastID=1;
CFigure::CFigure()
{
	ID = LastID++;
	Selected = false;
	hidden = false;
	FigGfxInfo.isFilled = 0;
}
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	ID=LastID++;
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	hidden = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s;
}

void CFigure::Sethidden(bool h) {
	hidden = h;
}	//hide/unhide the figure
bool CFigure::Ishidden() const {
	return hidden;
}	//check whether fig is hidden

bool CFigure::IsSelected() const
{
	return Selected;
}
void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
color CFigure::get_color() {
	if(FigGfxInfo.isFilled)
	return FigGfxInfo.FillClr;
	return GRAY;
}
string CFigure::GetDrawClrName()
{
	if (FigGfxInfo.DrawClr == RED) return "RED";
	else if (FigGfxInfo.DrawClr == ORANGE) return "ORANGE";
	else if (FigGfxInfo.DrawClr == BLUE) return  "BLUE";
	else if (FigGfxInfo.DrawClr == GREEN) return  "GREEN";
	else if (FigGfxInfo.DrawClr == YELLOW) return "YELLOW";
	else if (FigGfxInfo.DrawClr == BLACK) return "BLACK";
}
string CFigure::GetFillClrName()
{
	if (FigGfxInfo.FillClr == RED) return "RED";
	else if (FigGfxInfo.FillClr == ORANGE) return "ORANGE";
	else if (FigGfxInfo.FillClr == BLUE) return  "BLUE";
	else if (FigGfxInfo.FillClr == GREEN) return  "GREEN";
	else if (FigGfxInfo.FillClr == YELLOW) return "YELLOW";
	else if (FigGfxInfo.FillClr == BLACK) return "BLACK";
}
void CFigure::SetDrawClrName()
{
	if (DrawColor == "RED")    FigGfxInfo.DrawClr=RED;
	else if (DrawColor == "ORANGE") FigGfxInfo.DrawClr=ORANGE;
	else if (DrawColor == "BLUE")   FigGfxInfo.DrawClr= BLUE;
	else if (DrawColor == "GREEN")  FigGfxInfo.DrawClr= GREEN;
	else if (DrawColor == "YELLOW") FigGfxInfo.DrawClr=YELLOW;
	else if (DrawColor == "BLACK")  FigGfxInfo.DrawClr=BLACK;
}
void CFigure::SetFillClrName()
{
	if (FillColor == "RED")         FigGfxInfo.FillClr = RED;
	else if (FillColor == "ORANGE") FigGfxInfo.FillClr = ORANGE;
	else if (FillColor == "BLUE")   FigGfxInfo.FillClr = BLUE;
	else if (FillColor == "GREEN")  FigGfxInfo.FillClr = GREEN;
	else if (FillColor == "YELLOW") FigGfxInfo.FillClr = YELLOW;
	else if (FillColor == "BLACK")  FigGfxInfo.FillClr = BLACK;
}
;