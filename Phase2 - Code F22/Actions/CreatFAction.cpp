#include "CreatFAction.h"
#include "..\ApplicationManager.h"




CreatFAction::CreatFAction(ApplicationManager* pApp) :Action(pApp)
{}



void CreatFAction::ReadActionParameters()
{}




void CreatFAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->CreateFillColorToolBar();
}