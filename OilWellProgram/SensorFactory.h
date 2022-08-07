#pragma once
#pragma warning(disable : 4996)
#include "Sensor.h"
#include "OilWellList.h"
#include <iostream>
#include "OilWell.h"
#include "AlgoFactory.h"

class SensorFactory
{
private:
    bool s_moreSensors;

    char s_type[70];
    char s_className[70];
    char s_displayName[70];
    double s_min;
    bool s_minUDF;
    double s_max;
    bool s_maxUDF;
    double s_step;
    char s_units[70];
    char s_unitAbbrev[70];
    char s_DGA[70];
    char s_LinkType[70];

	SensorFactory();
public:
	

	static SensorFactory* getInstance();
	void addSensorsToWell(OilWell*, int, char**);
};

