#pragma once
#include "Display.h"
#include "Model.h"
#include <string>
#include <iostream>



class View
{
private:
	Model* model;
	Display* display;
public:
	View(Model*);
	void printMenu();
	void printReport();
};
