#include "StartAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

StartAction::StartAction(ApplicationManager* pApp) :Action(pApp)
{}

void StartAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage(" recording......");
}

void StartAction::Execute(bool w)
{
	Output* pOut = pManager->GetOutput();
	int fn;
	bool rec;
	if (w)
	ReadActionParameters();
	fn = pManager->getfigcount();
	rec= pManager->getrecording();
	if (fn == 0 || rec)
	{
		pManager->setrecording(true);
		pManager->setplay(true);
	}
	else 
		pOut->PrintMessage(" ERROR   <CantRecord>");
    Action* acttype;
	acttype = pManager->getlastaction();
	if ((acttype->isrecord()))
		pManager->setlastaction(acttype);
}

bool StartAction::isrecord()
{
	return false;
}
void StartAction::undo(){}
void StartAction::redo(){}

