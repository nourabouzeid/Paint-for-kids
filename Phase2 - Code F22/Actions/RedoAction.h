#pragma once
#include "Action.h"
class RedoAction : public Action
{
public:
	RedoAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute(bool w = true);
	bool isrecord();
	virtual void undo();
	virtual void redo();
};