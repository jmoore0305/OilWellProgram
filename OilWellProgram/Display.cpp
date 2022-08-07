#include "Display.h"
#include <iostream>

Display::Display(Model* theModel)
{
	model = theModel;
}

void Display::displayWellNamesAndIDs()
{
	OilWellList* wellList = model->getWellList();
	
	for (int i = 0; i < wellList->getWellCount(); i++)
	{
		OilWell* well = wellList->getWell(i);

		well->displayData();

	}
}

void Display::displayActivelySelectedWellData()
{
	OilWellList* wellList = model->getWellList();
	
	for (int i = 0; i < wellList->getWellCount(); i++)
	{
		OilWell* well = wellList->getWell(i);

		if (well->getDisplayValue() == true)
			well->displayData();
		
	}
}

void Display::displayActivelySelectedSensorData()
{
	OilWellList* wellList = model->getWellList();

	for (int i = 0; i < wellList->getWellCount(); i++)
	{
		OilWell* well = wellList->getWell(i);

		if (well->getDisplayValue() == true)
		{
			for (int i = 0; i < well->getSensorListSize(); i++)
			{
				Sensor* sensor = well->getSensor(i);

				if (sensor->getDisplayStatus() == true)
				{
					sensor->displayValues();
				}
			}
		}

	}
}


