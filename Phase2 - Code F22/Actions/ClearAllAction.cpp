#include "ClearAllAction.h"
#include "..\ApplicationManager.h"




ClearAllAction::ClearAllAction(ApplicationManager* pApp) :Action(pApp)
{}



void ClearAllAction::ReadActionParameters()
{}




void ClearAllAction::Execute(bool w)
{
	Output* pOut = pManager->GetOutput();
	Fout.open("undo.txt");
	Fout<<pManager->clrtostring(UI.DrawColor)<<"   "<<pManager->clrtostring(UI.FillColor)<<endl; 
	pManager->SaveAll(Fout);
	Fout.close();
	pOut->ClearDrawArea();
	pManager->clearallfigure();
}

bool ClearAllAction::isrecord()
{
	return false;
}
void ClearAllAction::undo() 
{
	Fin.open("undo.txt");
	while(Fin>>fig)
	{
		if(fig=="RECTANGLE")
		{
			CRectangle* rect=new CRectangle();
			rect->Load(Fin);
			pManager->AddFigure(rect);
		}
		if(fig=="CIRCLE")
		{
			CCircle* circle=new CCircle();
			circle->Load(Fin);
			pManager->AddFigure(circle);
		}
		if(fig=="SQUARE")
		{
			CSquare* square=new CSquare();
			square->Load(Fin);
			pManager->AddFigure(square);
		}
		if(fig=="HEXAGON")
		{
			CHex* Hex=new CHex();
			Hex->Load(Fin);
			pManager->AddFigure(Hex);
		}
		if(fig=="TRIANGLE")
		{
			CTriangle* triangle=new CTriangle();
			triangle->Load(Fin);
			pManager->AddFigure(triangle);
		}
	}
}

void ClearAllAction::redo() 
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pManager->clearallfigure();
}

