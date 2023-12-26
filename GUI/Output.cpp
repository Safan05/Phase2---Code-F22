#include "Output.h"
#include "cmath"
#include"UI_Info.h"
Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	UI.width = 1500;
	UI.height = 700;
	UI.wx = 5;
	UI.wy = 5;
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 55;
	UI.DrawColor = BLACK;	//Drawing color
	UI.FillColor = Transparent;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = WHITE;	//Background color
	UI.ToolBarColor = AZURE;
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 4;	//width of the figures frames
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	CreateDrawToolBar();
	CreateStatusBar();
}

Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBuffering(1);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, UI.PenWidth);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	pW->UpdateBuffer();
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, UI.PenWidth);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
	pWind->UpdateBuffer();
}
void Output::CreateFigureToolBar() const
{
	UI.InterfaceMode = MODE_FIGURES;

	ClearToolbar();
	string MenuItemImages[FIGURE_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Rectangle.jpg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\Square.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Triangle.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Circle.jpg";
	MenuItemImages[ITM_HEXA] = "images\\MenuItems\\Hexagon.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\MenuItems\\Menu_Back.jpg";

	for (int i = 0; i < FIGURE_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	pWind->UpdateBuffer();

}
void Output::CreatePickToolBar() const
{
	UI.InterfaceMode = MODE_PICK;
	ClearToolbar();
	string MenuItemImages[Pick_COUNT];
	MenuItemImages[ITM_Pick_figure] = "images\\MenuItems\\figure.jpg";
	MenuItemImages[ITM_Pick_color] = "images\\MenuItems\\color.jpg";
	MenuItemImages[ITM_Pick_both] = "images\\MenuItems\\both.jpg";
	MenuItemImages[ITM_Back_play] = "images\\MenuItems\\Menu_Back.jpg";
	for (int i = 0; i < Pick_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	pWind->UpdateBuffer();
}
void Output::Updatebuffer()
{
	pWind->UpdateBuffer();
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolbar() const
{
	//Clear Tool bar by drawing a filled white rectangle
	pWind->SetPen(UI.ToolBarColor, UI.PenWidth);
	pWind->SetBrush(UI.ToolBarColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, UI.PenWidth);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;
	ClearToolbar();
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_FIGURES] = "images\\MenuItems\\Menu_Shapes.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_CLEAR] = "images\\MenuItems\\Menu_Clear.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	MenuItemImages[ITM_SAVEGRAPH] = "images\\MenuItems\\Save_graph.jpg";
	MenuItemImages[ITM_LOADGRAPH] = "images\\MenuItems\\load.jpg";
	MenuItemImages[ITM_StartRecording] = "images\\MenuItems\\Start_Recording.jpg";
	MenuItemImages[ITM_StopRecording] = "images\\MenuItems\\Stop_Recording.jpg";
	MenuItemImages[ITM_PlayRecord] = "images\\MenuItems\\Play_Record.jpg";
	MenuItemImages[ITM_Switch_Play] = "images\\MenuItems\\To_Play.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\Menu_Undo.jpeg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\Menu_Redo.jpeg";
	MenuItemImages[ITM_FILLING] = "images\\MenuItems\\Menu_Fill.jpeg";
	MenuItemImages[ITM_DRAWING] = "images\\MenuItems\\Menu_Draw.jpeg";
	MenuItemImages[ITM_BLACK1] = "images\\MenuItems\\Menu_Black.jpeg";
	MenuItemImages[ITM_YELLOW1] = "images\\MenuItems\\Menu_Yellow.jpeg";
	MenuItemImages[ITM_ORANGE1] = "images\\MenuItems\\Menu_Orange.jpeg";
	MenuItemImages[ITM_RED1] = "images\\MenuItems\\Menu_Red.jpeg";
	MenuItemImages[ITM_GREEN1] = "images\\MenuItems\\Menu_Green.jpeg";
	MenuItemImages[ITM_BLUE1] = "images\\MenuItems\\Menu_Blue.jpeg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\Menu_Move.jpeg";
	MenuItemImages[ITM_MOVEBYDRAG] = "images\\MenuItems\\MoveByDrag.jpg";
	MenuItemImages[ITM_Voice]= "images\\MenuItems\\Menu_Voice.jpeg";
	MenuItemImages[ITM_TRANSPARENT] = "images\\MenuItems\\Transparent.jpeg";
	MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\resize.jpeg";
	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	//Draw a line under the toolbar
	pWind->SetPen(RED, UI.PenWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	pWind->UpdateBuffer();
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu

	ClearToolbar();
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_EXIT_Play] = "images\\MenuItems\\Menu_Exit.jpg";
	MenuItemImages[ITM_Switch_Draw] = "images\\MenuItems\\Menu_back.jpg";
	MenuItemImages[ITM_Pick] = "images\\MenuItems\\Pick.jpg";

	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	pWind->UpdateBuffer();
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "SWISS");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
	pWind->UpdateBuffer();
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}
void Output::DrawSQ(Point P1, GfxInfo RectGfxInfo, bool selected,int sidelength) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x - sidelength/2, P1.y - sidelength / 2, P1.x + sidelength / 2, P1.y + sidelength / 2, style);
}


void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}
void Output::Drawhexa(Point P1, GfxInfo RectGfxInfo, bool selected,int y) const
{
	int side = y * sqrt(3) / 2;
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int arrX[6] = { P1.x + y/2 , P1.x + y , P1.x + y/2 ,P1.x - y/2, P1.x - y , P1.x - y/2 };
	int arrY[6] = { P1.y + side, P1.y  , P1.y - side, P1.y - side  ,  P1.y  , P1.y + side };

	pWind->DrawPolygon(arrX, arrY, 6, style);
}
void Output::DrawCirc(Point P1, Point P2, GfxInfo CircGfxInfo, bool selected) const
{
	int a, b, r;
	a = abs(P1.x - P2.x);
	b = abs(P1.y - P2.y);
	r = sqrt(a * a + b * b);
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawCircle(P1.x, P1.y, r, style);
}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

