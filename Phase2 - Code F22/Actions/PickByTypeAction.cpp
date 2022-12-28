#include "PickByTypeAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

PickByTypeAction::PickByTypeAction(ApplicationManager* pApp):Action(pApp)
{}

void PickByTypeAction::ReadActionParameters()
{

}

void PickByTypeAction::Execute()
{
	ReadActionParameters();
}
