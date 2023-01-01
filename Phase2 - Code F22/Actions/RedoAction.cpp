#include "RedoAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

RedoAction::RedoAction(ApplicationManager* pApp) :Action(pApp)
{}

void RedoAction::ReadActionParameters()
{
	redoaction=pManager->getredoaction();
}

void RedoAction::Execute(bool w)
{
	Output* pOut = pManager->GetOutput();	
	ReadActionParameters();
	if(!redoaction)
	{
		pOut->PrintMessage("No Actions To redo");
		return;
	}
	redoaction->redo();
	pManager->addtoundolist(pManager->getcpyundoaction());
	pManager->removefromredolist();
}

bool RedoAction::isrecord()
{
	return false;
}
void RedoAction::undo()
{
	redoaction->undo();
}
void RedoAction::redo()
{
}