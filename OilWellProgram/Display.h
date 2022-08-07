#pragma once
#include "Model.h"



class Display
{
private:
	Model* model;
public:
	Display(Model*);
	void displayWellNamesAndIDs();
	void displayActivelySelectedWellData();
	void displayActivelySelectedSensorData();
};
