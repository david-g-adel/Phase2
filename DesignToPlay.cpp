#include "DesignToPlay.h"
#include "Grid.h"
DesignToPlay::DesignToPlay(ApplicationManager* pApp) :Action(pApp)
{

}
void DesignToPlay::ReadActionParameters()
{

}
void DesignToPlay::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->CreatePlayModeToolBar();
}
DesignToPlay::~DesignToPlay()
{

}
