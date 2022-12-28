#pragma once
#include "Action.h"
class PickByTypeAction:public Action
{
private:
	ifstream Fin;
public:
	PickByTypeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};