#include "CreatePToolbarAction.h"
#include "..\ApplicationManager.h"




CreatePToolbarAction::CreatePToolbarAction(ApplicationManager* pApp) :Action(pApp)
{}



void CreatePToolbarAction::ReadActionParameters()
{}




void CreatePToolbarAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Fout.open("PlayMode.txt");
	Fout<<pManager->clrtostring(UI.DrawColor)<<"   "<<pManager->clrtostring(UI.FillColor)<<endl; 
	pManager->SaveAll(Fout);
	Fout.close();
	pOut->CreatePlayToolBar();
}