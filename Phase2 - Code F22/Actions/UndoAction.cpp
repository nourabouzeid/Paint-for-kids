#include "UndoAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

UndoAction::UndoAction(ApplicationManager* pApp) :Action(pApp)
{
	pManager->setisundo(false);
	pManager->setisredo(true);
}

void UndoAction::ReadActionParameters()
{
	undoaction=pManager->getundoaction();
}

bool UndoAction::Execute(bool w)
{
	Output*pOut=pManager->GetOutput();
	if(w)
	ReadActionParameters();
	if(!undoaction)
	{
		pOut->PrintMessage("No Actions To Undo");
		if (recordeddd())
			return false;
		else
			return true;
	}
	undoaction->undo();
	pManager->removefromundolist();

	if (recordeddd())
		return false;
	else
		return true;
}

bool UndoAction::isrecord()
{
	return true;
}
void UndoAction::undo()
{
}
void UndoAction::redo()
{
	undoaction->redo();
}