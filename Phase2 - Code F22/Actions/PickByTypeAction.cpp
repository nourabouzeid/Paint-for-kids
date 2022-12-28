#include "PickByTypeAction.h"
#include "..\ApplicationManager.h"
#include<cstdlib>
#include<time.h>
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "SelectAction.h"

PickByTypeAction::PickByTypeAction(ApplicationManager* pApp):Action(pApp)
{}

void PickByTypeAction::ReadActionParameters()
{

}

void PickByTypeAction::Execute()
{
	string random[5];
	string fig;
	int r=0,c=0,s=0,h=0,t=0;
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Fin.open("PlayMode.txt");
	int i=0;
	while(Fin>>fig)
	{
		if(fig=="RECTANGLE")
		{
			if(!r)
			random[i++]=fig+'S';
			r++;
		}
		if(fig=="CIRCLE")
		{
			if(!c)
			random[i++]=fig+'S';
			c++;
		}
		if(fig=="SQUARE")
		{
			if(!s)
			random[i++]=fig+'S';
			s++;
		}
		if(fig=="HEXAGON")
		{
			if(!h)
			random[i++]=fig+'S';
			h++;
		}
		if(fig=="TRIANGLE")
		{
			if(!t)
			random[i++]=fig+'S';
			t++;
		}
	}
	srand(time(0));
	pOut->PrintMessage("Pick all "+random[rand()%(sizeof(random)/sizeof(random[0]))]);
	SelectAction*select=new SelectAction(pManager);
	select->Execute();

}
