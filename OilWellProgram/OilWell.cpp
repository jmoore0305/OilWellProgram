#include "OilWell.h"


OilWell::OilWell(char* wellID, char* wellOptr, int sensorCount, char** senArray)
{
	sensorArray = senArray;
	displayStatus = false;
	strcpy(m_wellID, wellID);
	strcpy(m_wellOptr, wellOptr);
	m_sensorCount = sensorCount;
}

OilWell::OilWell()
{
	sensorArray = NULL;
	displayStatus = false;
	char* x = new char[32];
	char* y = new char[64];
	strcpy(m_wellID, x);
	strcpy(m_wellOptr, y);
	m_sensorCount = 0;
}

char* OilWell::getWellId()
{
	return m_wellID;
}

void OilWell::setWellId(char* id)
{
	strcpy(m_wellID, id);
}

void OilWell::setDisplayValue(bool status)
{
	displayStatus = status;
}

bool OilWell::getDisplayValue()
{
	return displayStatus;
}

char* OilWell::getOptrName()
{
	return m_wellOptr;
}


int OilWell::getSensorCount()
{
	return m_sensorCount;
}



void OilWell::displaySensorArray()
{
	for (int i = 0; i < m_sensorCount; i++)
	{
		cout << sensorArray[i] << endl;
	}
}

char** OilWell::getSenArray()
{
	return sensorArray;
}

void OilWell::addSensorToList(Sensor* sensor)
{
	sensorList.push_back(sensor);
	m_sensorCount++;
}

vector<Sensor*> OilWell::getSensorList()
{
	return sensorList;
}

Sensor* OilWell::getSensor(int i)
{
	return sensorList.at(i);
}

void OilWell::displayData()
{
	cout << "Well ID : " << m_wellID << endl;
	cout << "Well Operator: " << m_wellOptr << endl;
}

bool OilWell::searchSensorList(string sensorName)
{

	bool found = false;

	for (int i = 0; i < sensorList.size(); i++)
	{
		Sensor* sensor = sensorList.at(i);

		if (sensor->getTypeName() == sensorName)
		{
			found = true;
			sensor->setDisplayStatus(found);
		}
	}

	return found;
}

int OilWell::getSensorListSize()
{
	return sensorList.size();
}

