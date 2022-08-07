#include "Model.h"


using namespace std;


Model::Model()
{

	fileName = "OilFieldData2.xml";


	OilFieldDataParser* parser = parser->getInstance();

	parser->initDataFile(fileName);

	wellList = new OilWellList(parser);


	SensorFactory* sensorFactory = sensorFactory->getInstance();

	OilWell* well = new OilWell();


	for (int i = 0; i < wellList->getWellCount(); i++)
	{

		well = wellList->getWell(i);

		sensorFactory->addSensorsToWell(well, well->getSensorCount(), well->getSenArray());

	}
	
	
}

OilWellList* Model::getWellList()
{
	return wellList;
}

void Model::update()
{
	string ifGreater = "FOLLOWLINK_IFGREATER";
	string ifChanged = "FOLLOWLINK_IFCHANGED";

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
					

					if (sensor->getAlgoName() == ifGreater)
					{
						
						double currVal = sensor->getCurrentValue();

						Sensor* linkedSen = sensor->getLinkedSensor();

						AlgoStrategy* theStrat = linkedSen->getAlgoStrategy();

						double linkedCurrVal = theStrat->execute();

						AlgoStrategy* strat = sensor->getAlgoStrategy();

						strat->sendData(currVal, linkedCurrVal);

						double theValue = strat->execute();

						sensor->setCurrentValue(theValue);

					}
					else if (sensor->getAlgoName() == ifChanged)
					{
				

					}
					else
					{
				

						AlgoStrategy* strat = sensor->getAlgoStrategy();

						double val = strat->execute();

						sensor->setCurrentValue(val);

					}


		
				}
			}

		}
	}
}





