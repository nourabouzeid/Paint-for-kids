#pragma once
#include "Action.h"


class ClearAllAction : public Action
{
private:
public:
	ClearAllAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

