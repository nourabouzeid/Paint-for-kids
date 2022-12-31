#include "RedoAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

RedoAction::RedoAction(ApplicationManager* pApp) : Action(pApp)
{}

void RedoAction::ReadActionParameters()
{
	pManager->GetOutput()->PrintMessage("Redo Last Action");
}

//Execute the action
void RedoAction::Execute(bool w)
{
	pManager->RedoLastAction();
	if(w)
	{
		ReadActionParameters();
	}
}
bool RedoAction::isrecord()
{
	return true;
}
 void RedoAction::undo(){}
 void RedoAction::redo(){}