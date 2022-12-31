#include "UndoAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

UndoAction::UndoAction(ApplicationManager* pApp) : Action(pApp)
{}

void UndoAction::ReadActionParameters()
{
	pManager->GetOutput()->PrintMessage("Undo Last Action");
}

//Execute the action
void UndoAction::Execute(bool w)
{
	
	pManager->UndoLastAction();
	if(w)
		{
			ReadActionParameters();
		}
}
bool UndoAction::isrecord()
{
	return true;
}
 void UndoAction::undo(){}
 void UndoAction::redo(){}