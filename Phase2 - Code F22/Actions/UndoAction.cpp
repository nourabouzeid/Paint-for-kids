#include "UndoAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

UndoAction::UndoAction(ApplicationManager* pApp) :Action(pApp)
{}

void UndoAction::ReadActionParameters()
{
	undoaction=pManager->getundoaction();
}

void UndoAction::Execute(bool w)
{
	Output*pOut=pManager->GetOutput();
	ReadActionParameters();
	if(!undoaction)
	{
		pOut->PrintMessage("No Actions To Undo");
		return;
	}
	undoaction->undo();
	pManager->removefromundolist();
}

bool UndoAction::isrecord()
{
	return false;
}
void UndoAction::undo()
{
}
void UndoAction::redo()
{
}