#include "CreateDToolbarAction.h"
#include "..\ApplicationManager.h"




CreateDToolbarAction::CreateDToolbarAction(ApplicationManager* pApp) :Action(pApp)
{}



void CreateDToolbarAction::ReadActionParameters()
{}




void CreateDToolbarAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->CreateDrawToolBar();
}