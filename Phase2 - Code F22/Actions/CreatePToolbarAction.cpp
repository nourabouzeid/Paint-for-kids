#include "CreatePToolbarAction.h"
#include "..\ApplicationManager.h"




CreatePToolbarAction::CreatePToolbarAction(ApplicationManager* pApp) :Action(pApp)
{}



void CreatePToolbarAction::ReadActionParameters()
{}




void CreatePToolbarAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->CreatePlayToolBar();
}