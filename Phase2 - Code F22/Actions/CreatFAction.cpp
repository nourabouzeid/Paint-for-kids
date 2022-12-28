#include "CreatFAction.h"
#include "..\ApplicationManager.h"




CreatFAction::CreatFAction(ApplicationManager* pApp) :Action(pApp)
{}



void CreatFAction::ReadActionParameters()
{}




void CreatFAction::Execute(bool w)
{
	Output* pOut = pManager->GetOutput();
	pOut->CreateFillColorToolBar();
}

bool CreatFAction::isrecord()
{
	return true;
}
