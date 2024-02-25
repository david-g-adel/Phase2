#include "PlayToDesign.h"
#include "Grid.h"
PlayToDesign::PlayToDesign(ApplicationManager* pApp) :Action(pApp)
{

}
void PlayToDesign::ReadActionParameters()
{

}
void PlayToDesign::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->CreateDesignModeToolBar();
}
PlayToDesign::~PlayToDesign()
{

}
