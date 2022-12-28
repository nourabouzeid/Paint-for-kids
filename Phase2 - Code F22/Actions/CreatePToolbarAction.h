#pragma once
#include "Action.h"
class CreatePToolbarAction :  public Action
{
private:
public:
	CreatePToolbarAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

