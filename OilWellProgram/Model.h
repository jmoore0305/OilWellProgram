#pragma once
#include "OilWellList.h"
#include "OilWell.h"
#include <iostream>
#include "SensorFactory.h"
#include <string>


class Model
{
private:
	const char* fileName;
	OilWellList* wellList;
public:
	Model();
	OilWellList* getWellList();
	void update();
};
