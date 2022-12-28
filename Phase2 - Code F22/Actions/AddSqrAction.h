#ifndef ADD_SQR_ACTION_H
#define ADD_SQR_ACTION_H

#include "Action.h"
#include "..\Figures\CSquare.h"

class AddSqrAction : public Action
{
private:
	Point P1;
	GfxInfo RectGfxInfo;
public:
	AddSqrAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute(bool w = true);
	bool isrecord();
};

#endif