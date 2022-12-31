#include "ApplicationManager.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	SelectedFig = NULL;
	lastaction = NULL;
	actnum = 0;
	FigCount = 0;
	undocount=0;
	redocount=0;
	startrecord = NULL;
	recording = false;
	play = false;
	stop = false;
	f = 0;
	ID=1;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
	for (int i = 0; i < 20; i++)
		act[i] = NULL;
	for (int i = 0; i < maxundoredocount; i++)
		UndoList[i] = NULL;
	for (int i = 0; i < maxundoredocount; i++)
		RedoList[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	   case FIG:
		   pAct = new CreatFigureAction(this);  
		   break;
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_SQUARE:
			pAct = new AddSqrAction(this);
			break;
		case DRAW_HEXA:
			pAct = new AddHexAction(this);
			break;
		case DRAW_CIRCLE:
			pAct = new AddCircleAction(this);
			break;
		case DRAW_TRIANGLE:
			pAct = new AddTriangleAction(this);
			break;
		case SELECT:
			pAct = new SelectAction(this);
			break;
		case TO_DRAW1:
			pAct = new CreateDToolbarAction(this);
			break;
		case TO_DRAW2:
			pAct = new CreateDToolbar2Action(this);
			break;
		case DRAW_COLOR:
			pAct = new CreatDAction(this);
			f = 1;
			break;
		case FILL_COLOR:
			pAct = new CreatFAction(this);
			f = 2;
			break;
		case BLACK_COLOR:
			c1 = BLACK;
			if (f == 1)
				pAct = new DrawCAction(this);
			else if(f==2)
				pAct = new FillCAction(this);
			break;
		case YELLOW_COLOR:
			c1 = YELLOW;
			if (f == 1)
				pAct = new DrawCAction(this);
			else if (f == 2)
				pAct = new FillCAction(this);
			break;
		case ORANGE_COLOR:
			c1 = ORANGE;
			if (f == 1)
				pAct = new DrawCAction(this);
			else if (f == 2)
				pAct = new FillCAction(this);
			break;
		case RED_COLOR:
			c1 = RED;
			if (f == 1)
				pAct = new DrawCAction(this);
			else if (f == 2)
				pAct = new FillCAction(this);
			break;
		case GREEN_COLOR:
			c1 = GREEN;
			if (f == 1)
				pAct = new DrawCAction(this);
			else if (f == 2)
				pAct = new FillCAction(this);
			break;
		case BLUE_COLOR:
			c1 = BLUE;
			if (f == 1)
				pAct = new DrawCAction(this);
			else if (f == 2)
				pAct = new FillCAction(this);
			break;
		case TO_PLAY:
			pAct = new CreatePToolbarAction(this);
			break;
		case MOVE:
			pAct = new MoveAction(this);
			break;
		case SAVE:
			pAct=new SaveAction(this);
			break;
		case LOAD:
			pAct=new LoadAction(this);
			break;
		case PICKWITHTYPE:
			pAct=new PickByTypeAction(this);
			break;
		case PICKWITHCOLOR:
			pAct=new PickByColorAction(this);
			break;
		case PICKWITHTYPEANDCOLOR:
			pAct=new PickByColorAndTypeAction(this);
			break;
		case CLEAR:
			pAct = new ClearAllAction(this);
			break;
		case STARTRECORDING:
			pAct = new StartAction(this);
			startrecord = pAct;
			break;
		case STOPRECORDING:
			pAct = new StopAction(this);
			break;
		case PLAYRECORDING:
			pAct = new PlayRecordAction(this);
			break;
		case DELET:
			pAct = new DeleteFigureAction(this);
			break;
			case UNDO :
				pAct = new UndoAction(this);
			break;
		case REDO:
			pAct = new RedoAction(this);
			break;
		case EXIT:
			///create ExitAction here
			pAct=new ExitAction(this);
			break;
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	pOut->ClearStatusBar();
	lastaction = pAct;
	//Execute the created action
	if (pAct != NULL)
	{
		if ( pOut->GetInterfaceMode() == (MODE_DRAW||MODE_FIG||MODE_DRAWCOLOR||MODE_FILLCOLOR) )
		{
			if (ActType != SAVE && ActType != LOAD  && ActType != UNDO && ActType != REDO && ActType != EXIT && ActType != SELECT)
			{
				AddToUndoList(pAct);

				if (redocount!=0)
				{
					for (int i = 0; i < maxundoredocount; i++)
					{
						RedoList[i]=NULL;
					}
				}
			}
		}
	}
	pAct->Execute(true);//Execute
		if (recording && ActType != STARTRECORDING)
		{
			startrecord->Execute(true);
		}
		pAct = NULL;
	}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

void ApplicationManager::clearallfigure()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	for (int i = 0; i < actnum; i++)
	{
		delete act[i];
		act[i] = NULL;
	}
	actnum = 0;
	FigCount = 0;
	SelectedFig = NULL;
}

Action* ApplicationManager::getlastaction()
{
	return lastaction;
}

void ApplicationManager::setrecording(bool rec)
{
	recording = rec;
}

bool ApplicationManager::getrecording()
{
	return recording;
}

void ApplicationManager::setplay(bool rec)
{
	play = rec;
}

bool ApplicationManager::getplay()
{
	return play;
}

void ApplicationManager::setstop(bool rec)
{
	stop = rec;
}

bool ApplicationManager::getstop()
{
	return stop;
}

int ApplicationManager::getfigcount()
{
	return FigCount;
}

void ApplicationManager::deletefigure(CFigure* cf1)
{
	CFigure* temp;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == cf1 && i < (FigCount-1))
		{
			temp = FigList[i];
			FigList[i] = FigList[i + 1];
			FigList[i + 1] = temp;
		}
		if (FigList[i] == cf1 && i == (FigCount - 1))
		{
			delete FigList[i];
			FigList[i] = NULL;
			FigCount = FigCount - 1;
			SelectedFig = NULL;
		}
	}
}
string ApplicationManager::clrtostring(color clr)
{	
	string s;
	if(clr==BLUE)
	s="BLUE";
	if(clr==GREEN)
	s="GREEN";
	if(clr==RED)
	s="RED";
	if(clr==ORANGE)
	s="ORANGE";
	if(clr==YELLOW)
	s="YELLOW";
	if(clr==BLACK)
	s="BLACK";
	return s;
}
color ApplicationManager::getcolor()
{
	return c1;
}
void ApplicationManager::MOVEE(Point p) const
{
	if(SelectedFig!=NULL)
	SelectedFig->move(p);
}

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(pFig->getID()!=0)
	pFig->setID(ID++);
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
		
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::setselectedfigure(CFigure* cf)
{
	SelectedFig = cf;
}

CFigure* ApplicationManager::getselectedfigure()
{
	return SelectedFig;
}

void ApplicationManager::setlastaction(Action* Act)
{
	if (actnum < 20)
		act[actnum++] = Act;
}

void ApplicationManager::excuteplayactions()
{
	for (int i = 0; i < actnum; i++)
	{
		Sleep(1000);
		act[i]->Execute(false);
		pOut->ClearDrawArea();
		UpdateInterface();
	}
}

void ApplicationManager::deleteallfigure()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
	SelectedFig = NULL;
}

CFigure* ApplicationManager::GetFigure(Point p) const
{
	for (int i = FigCount-1; i>=0; i--)
	{
		if (FigList[i]->isinside(p))
		{
			return FigList[i];
		}
	}
	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
void ApplicationManager::SaveAll(ofstream& Fout)
{
	Fout<<FigCount<<endl;
	for(int i=0; i<FigCount; i++)
		FigList[i]->Save(Fout);
}
	Action* ApplicationManager::UndoLastAction() 
	{
		if (undocount==0) return NULL;
	Action* lastAct = UndoList[undocount];
	delete UndoList[undocount--];
	RedoList[redocount++]=lastAct;
	return lastAct;
	}
	Action* ApplicationManager::RedoLastAction() 
	{
		if (redocount==0) return NULL;
	Action* lastAct = RedoList[redocount];
	delete UndoList[redocount--];
	UndoList[undocount++]=lastAct;
	return lastAct;
	}
	void ApplicationManager::AddToUndoList(Action* pAct)
	{
		if (undocount == maxundoredocount)
		{
			delete UndoList[0];
			for (int i = 0; i < maxundoredocount-1; i++)
			{
				UndoList[i]=UndoList[i+1];
			}
		}
	UndoList[undocount]=pAct;
	}
	bool ApplicationManager::DeleteLastFig()
	{
	if (FigCount == 0)
		return false;
	delete FigList[FigCount - 1];
	FigList[FigCount - 1] = NULL;
	FigCount--;
	return true;
	}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}

