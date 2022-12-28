#pragma once
#include "Action.h"
class MoveAction : public Action
{
private:
	Point p;
public:
	MoveAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

