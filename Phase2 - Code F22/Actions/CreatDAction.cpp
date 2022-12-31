#include "CreatDAction.h"
#include "..\ApplicationManager.h"




CreatDAction::CreatDAction(ApplicationManager* pApp) :Action(pApp)
{}



void CreatDAction::ReadActionParameters()
{}




void CreatDAction::Execute(bool w)
{
	Output* pOut = pManager->GetOutput();
	pOut->CreateDrawColorToolBar();
}

bool CreatDAction::isrecord()
{
	return true;
}
 void CreatDAction::undo(){}
 void CreatDAction::redo(){}