#include "RedoAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

RedoAction::RedoAction(ApplicationManager* pApp) :Action(pApp)
{}

void RedoAction::ReadActionParameters()
{
	
}

void RedoAction::Execute(bool w)
{

}

bool RedoAction::isrecord()
{
	return false;
}
void RedoAction::undo()
{
}
void RedoAction::redo()
{
}