#pragma once
#include "SensorFactory.h"

using namespace std;

SensorFactory::SensorFactory()
{
    s_moreSensors = true;

    
    s_min = 0;
    s_minUDF = false;
    s_max = 0;
    s_maxUDF = false;
    s_step = 0;
    

    char* a = new char[70];
    char* b = new char[70];
    char* c = new char[70];
    char* d = new char[70];
    char* e = new char[70];
    char* f = new char[70];
    char* g = new char[70];


    strcpy(s_type, a);
    strcpy(s_className, b);
    strcpy(s_displayName, c);
    strcpy(s_units, d);
    strcpy(s_unitAbbrev, e);
    strcpy(s_DGA, f);
    strcpy(s_LinkType, g);
}


SensorFactory* SensorFactory::getInstance()
{
    static SensorFactory* theInstance = NULL;
    if (theInstance == NULL)
    {
        theInstance = new SensorFactory();
    }
    return theInstance;
}



void SensorFactory::addSensorsToWell(OilWell* well, int senCount, char** sensorArray)
{


    bool moreSensors = true;


    

        OilFieldDataParser* sensorParser = sensorParser->getInstance();

        for (int i = 0; i < senCount; i++)
        {
            //changed everything from char* to char[70]
            char* x = new char[70];
            x = sensorArray[i];
            char type[70];
            strcpy(type, x);
            
            string ifGreater = "FOLLOWLINK_IFGREATER";
            string ifChanged = "FOLLOWLINK_IFCHANGED";

            moreSensors = sensorParser->getSensorData(type, s_className, s_displayName,
                &s_min, &s_minUDF, &s_max, &s_maxUDF, &s_step, s_units, s_unitAbbrev, s_DGA, s_LinkType);




            Sensor* sensor = new Sensor(type, s_className, s_displayName,
                s_min, s_minUDF, s_max, s_maxUDF, s_step, s_units, s_unitAbbrev, s_DGA, s_LinkType);
            



            if (s_DGA == ifGreater || s_DGA == ifChanged)
            {
                

                strcpy(type, s_LinkType);


                    
                moreSensors = sensorParser->getSensorData(type, s_className, s_displayName,
                    &s_min, &s_minUDF, &s_max, &s_maxUDF, &s_step, s_units, s_unitAbbrev, s_DGA, s_LinkType);
           

                Sensor* linkedSensor = new Sensor(type, s_className, s_displayName,
                    s_min, s_minUDF, s_max, s_maxUDF, s_step, s_units, s_unitAbbrev, s_DGA, s_LinkType);

               
                AlgoFactory* algoFactory = algoFactory->getInstance();


                AlgoStrategy* strat = algoFactory->getDataGenAlgoForSensor(linkedSensor->getMinValue(), linkedSensor->getMaxValue(), linkedSensor->getStepValue(), linkedSensor->getMinUDF(), linkedSensor->getMaxUDF(), linkedSensor->getAlgoName());

                
                linkedSensor->setAlgoStrategy(strat);

         
                sensor->createLinkToSensor(linkedSensor);

            }
            else
            {
                sensor->setLinkSensorToNULL();
            }


         

            //get data generation algorithm
            AlgoFactory* algoFactory = algoFactory->getInstance();
                  
            AlgoStrategy* strat = algoFactory->getDataGenAlgoForSensor(sensor->getMinValue(), sensor->getMaxValue(), sensor->getStepValue(), sensor->getMinUDF(), sensor->getMaxUDF(), sensor->getAlgoName());

            sensor->setAlgoStrategy(strat);

            well->addSensorToList(sensor);

       

        }
      

}



