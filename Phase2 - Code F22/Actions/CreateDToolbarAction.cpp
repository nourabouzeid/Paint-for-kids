#include "CreateDToolbarAction.h"
#include "..\ApplicationManager.h"




CreateDToolbarAction::CreateDToolbarAction(ApplicationManager* pApp) :Action(pApp)
{}



void CreateDToolbarAction::ReadActionParameters()
{}




void CreateDToolbarAction::Execute(bool w)
{
	Output* pOut = pManager->GetOutput();
	pOut->CreateDrawToolBar();
}

bool CreateDToolbarAction::isrecord()
{
	return true;
}
