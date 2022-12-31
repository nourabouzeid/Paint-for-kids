#pragma once
#include "Action.h"
class UndoAction : public Action
{
public:
	UndoAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute(bool w = true);
	bool isrecord();
	virtual void undo();
	virtual void redo();
};
