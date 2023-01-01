#include "CreatePToolbarAction.h"
#include "..\ApplicationManager.h"




CreatePToolbarAction::CreatePToolbarAction(ApplicationManager* pApp) :Action(pApp)
{
	pManager->setisundo(false);
	pManager->setisredo(false);
}



void CreatePToolbarAction::ReadActionParameters()
{}




bool CreatePToolbarAction::Execute(bool w)
{
	Output* pOut = pManager->GetOutput();
	Fout.open("PlayMode.txt");
	Fout<<pManager->clrtostring(UI.DrawColor)<<"   "<<pManager->clrtostring(UI.FillColor)<<endl; 
	pManager->SaveAll(Fout);
	Fout.close();
	pOut->CreatePlayToolBar();
	return true;
}

bool CreatePToolbarAction::isrecord()
{
	return false;
}
void CreatePToolbarAction::undo()
{
}
void CreatePToolbarAction::redo()
{
}