#pragma once
#include <sys/types.h>     // needed for the _ftime() function
#include <sys/timeb.h>     // contains definition of _timeb struct
#include <time.h>          // needed for other time functions and structures
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "Model.h"
#include "View.h"


using namespace std;


class OilWellSimulation
{
private:
	Model* model;
	View* view;
	struct _timeb tStruct;
	double thisTime;
	double outputTime;
	bool done;  // while loop flag
	bool running;
	int hit;     // key hit flag
	char ch;     // character key which was hit
	char response;
	
public:
	OilWellSimulation();
	void runSimulation();
};