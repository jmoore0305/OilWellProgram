#pragma once

#include <vector>
#include "Sensor.h"
#include <iostream>
#include <string>

using namespace std;

class OilWell
{
private:
	char m_wellID[32];
	char m_wellOptr[64];
	bool displayStatus;
	int m_sensorCount;
	char** sensorArray;
	vector<Sensor*> sensorList;

public:
	OilWell(char*, char*, int, char**);
	OilWell();
	char* getWellId();
	void setWellId(char*);
	void setDisplayValue(bool);
	bool getDisplayValue();
	char* getOptrName();
	int getSensorCount();
	void displaySensorArray();
	char** getSenArray();
	void addSensorToList(Sensor*);
	vector<Sensor*> getSensorList();
	Sensor* getSensor(int);
	void displayData();
	bool searchSensorList(string);
	int getSensorListSize();
};



