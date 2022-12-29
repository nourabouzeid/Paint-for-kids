#include "PlayRecordAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

PlayRecordAction::PlayRecordAction(ApplicationManager* pApp) :Action(pApp)
{}

void PlayRecordAction::ReadActionParameters()
{
}

void PlayRecordAction::Execute(bool w)
{
	Output* pOut = pManager->GetOutput();
	bool pl = pManager->getplay();
	bool st = pManager->getstop();
	if (pl && st)
	{
		pOut->ClearDrawArea();
		pManager->deleteallfigure();
		pManager->excuteplayactions();
	}
	else
		pOut->PrintMessage("ERROR  <you must start recording and stop it>");

}

bool PlayRecordAction::isrecord()
{
	return false;
}

