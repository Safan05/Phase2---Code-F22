#include "CFigure.h"
int CFigure::LastID=1;
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
	return FigGfxInfo.DrawClr;
};