#include "Sensor.h"





Sensor::Sensor(char* type, char* cName, char* dName, double& min, bool& minUDF, double& max, bool& maxUDF, double& step, char* units, char* unitAbbrev, char* dga, char* linkType)
{
	algoStrategy = NULL;
	sensorLink = NULL;
	sen_minUDF = minUDF;
	sen_maxUDF = maxUDF;
	sen_min = min;
	sen_max = max;
	sen_step = step;
	sen_currVal = 0;
	displayStatus = false;
	strcpy(sen_type, type);
	strcpy(sen_className, cName);
	strcpy(sen_displayName, dName);
	strcpy(sen_units, units);
	strcpy(sen_unitAbbrev, unitAbbrev);
	strcpy(sen_DGA, dga);
	strcpy(sen_LinkType, linkType);
	bool moreSensors = true;

}

Sensor::Sensor()
{
	algoStrategy = NULL;
	sen_minUDF = false;
	sen_maxUDF = false;
	sen_min = 0;
	sen_max = 100;
	sen_step = 0;
	sen_currVal = 0;
	displayStatus = false;
	algoStrategy = NULL;
	sensorLink = NULL;

	char* a = new char[70];
	char* b = new char[70];
	char* c = new char[70];
	char* d = new char[70];
	char* e = new char[70];
	char* f = new char[70];
	char* g = new char[70];


	strcpy(sen_type, a);
	strcpy(sen_className, b);
	strcpy(sen_displayName, c);
	strcpy(sen_units, d);
	strcpy(sen_unitAbbrev, e);
	strcpy(sen_DGA, f);
	strcpy(sen_LinkType, g);
}



void Sensor::displayValues()
{
	cout << "type: " << sen_type << endl;
	cout << "className: " << sen_className << endl;
	cout << "displayName: " << sen_displayName << endl;
	cout << "min: " << sen_min << endl;
	cout << "max: " << sen_max << endl;
	cout << "current val: " << sen_currVal << endl;
	cout << "step: " << sen_step << endl;
	cout << "units: " << sen_units << endl;
	cout << "unit abbrev: " << sen_unitAbbrev << endl;
	cout << "min UDF: " << sen_minUDF << endl;
	cout << "max UDF: " << sen_maxUDF << endl;
	cout << "data gen algo type: " << sen_DGA << endl;
	cout << "link type: " << sen_LinkType << endl;
	cout << "display status: " << displayStatus << endl;

	cout << endl;
	cout << endl;
}

void Sensor::setDisplayStatus(bool status)
{
	displayStatus = status;
}

bool Sensor::getDisplayStatus()
{
	return displayStatus;
}


char* Sensor::getSensorUnitType()
{
	return sen_type;
}

void Sensor::setCurrentValue(double currentValue)
{
	sen_currVal = currentValue;
}

double Sensor::getCurrentValue()
{
	return sen_currVal;
}

char* Sensor::getAlgoName()
{
	char* x = sen_DGA;
	return x;
}

void Sensor::setAlgoStrategy(AlgoStrategy* strategy)
{
	algoStrategy = strategy;
}

AlgoStrategy* Sensor::getAlgoStrategy()
{
	return algoStrategy;
}

double Sensor::getMinValue()
{
	return sen_min;
}

double Sensor::getMaxValue()
{
	return sen_max;
}

double Sensor::getStepValue()
{
	return sen_step;
}

bool Sensor::getMinUDF()
{
	return sen_minUDF;
}

bool Sensor::getMaxUDF()
{
	return sen_maxUDF;
}

void Sensor::createLinkToSensor(Sensor* linkedSensor)
{
	AlgoFactory* algoFactory = algoFactory->getInstance();
	sensorLink = linkedSensor;
}

Sensor* Sensor::getLinkedSensor()
{
	return sensorLink;
}

void Sensor::setLinkSensorToNULL()
{
	sensorLink = NULL;
}

void Sensor::displayDisplayName()
{
	cout << "Sensor display name: " << sen_displayName << endl;
}

char* Sensor::getTypeName()
{
	return sen_type;
}












