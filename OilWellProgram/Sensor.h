#pragma once
#pragma warning(disable : 4996)
#include <string.h>
#include <iostream>
#include "OilFieldDataParser.h"
#include "AlgoStrategy.h"
#include "AlgoFactory.h"

using namespace std;

class Sensor
{
private:
	bool sen_minUDF;
	bool sen_maxUDF;
	char sen_type[70];
	char sen_className[70];
	char sen_displayName[70];
	double sen_min;
	double sen_max;
	double sen_currVal;
	double sen_step;
	char sen_units[70];
	char sen_unitAbbrev[70];
	char sen_DGA[70];
	char sen_LinkType[70];
	bool displayStatus;
	AlgoStrategy* algoStrategy;
	Sensor* sensorLink;
public:
	Sensor(char*, char*, char*, double&, bool&, double&, bool&, double&, char*, char*, char*, char*);
	Sensor();
	void displayValues();
	void setDisplayStatus(bool);
	bool getDisplayStatus();
	char* getSensorUnitType();
	void setCurrentValue(double);
	double getCurrentValue();
	char* getAlgoName();
	void setAlgoStrategy(AlgoStrategy*);
	AlgoStrategy* getAlgoStrategy();
	double getMinValue();
	double getMaxValue();
	double getStepValue();
	bool getMinUDF();
	bool getMaxUDF();
	void createLinkToSensor(Sensor*);
	Sensor* getLinkedSensor();
	void setLinkSensorToNULL();
	void displayDisplayName();
	char* getTypeName();
};
