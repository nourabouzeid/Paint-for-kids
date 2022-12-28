#include "CreatFigureAction.h"
#include "..\ApplicationManager.h"




CreatFigureAction::CreatFigureAction(ApplicationManager* pApp) :Action(pApp)
{}



void CreatFigureAction::ReadActionParameters()
{}




void CreatFigureAction::Execute(bool w)
{
	Output* pOut = pManager->GetOutput();
	pOut->CreateFigureToolBar();
}

bool CreatFigureAction::isrecord()
{
	return true;
}
