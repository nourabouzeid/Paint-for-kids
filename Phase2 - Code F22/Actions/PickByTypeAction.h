#pragma once
#include "Action.h"
class PickByTypeAction:public Action
{
private:
	
public:
	PickByTypeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};