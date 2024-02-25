#pragma once
#include "Action.h"
#include <fstream>
#include <string>
using namespace std;
class SaveGridAction :
    public Action
{
	string OutputFile;
public:

	SaveGridAction(ApplicationManager* pApp);

	virtual void ReadActionParameters(); 

	virtual void Execute(); 


	virtual ~SaveGridAction(); // Virtual Destructor


};

