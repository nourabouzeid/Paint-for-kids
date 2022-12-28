#include "CreatDAction.h"
#include "..\ApplicationManager.h"




CreatDAction::CreatDAction(ApplicationManager* pApp) :Action(pApp)
{}



void CreatDAction::ReadActionParameters()
{}




void CreatDAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->CreateDrawColorToolBar();
}
