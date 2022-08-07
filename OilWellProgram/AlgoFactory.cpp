#include "AlgoFactory.h"

AlgoFactory* AlgoFactory::getInstance()
{
    static AlgoFactory* theInstance = NULL;
    if (theInstance == NULL)
    {
        theInstance = new AlgoFactory();
    }
    return theInstance;
}

AlgoFactory::AlgoFactory()
{
}


AlgoStrategy* AlgoFactory::getDataGenAlgoForSensor(double min, double max, double step, bool minUDF, bool maxUDF, char* AlgoType)
{

    const char* s = (const char*)AlgoType;

    string str(s);



    if (str == "RAND_MIN2MAX")
        return new AlgoOne(min, max, step, minUDF, maxUDF);
    else if (str == "STEPINC_MIN2MAX")
        return new AlgoTwo(min, max, step, minUDF, maxUDF);
    else if (str == "STEPDEC_MAX2MIN")
        return new AlgoThree(min, max, step, minUDF, maxUDF);
    else if (str == "FOLLOWLINK_IFGREATER")
        return new AlgoFour(min, max, step, minUDF, maxUDF);
    else if (str == "FOLLOWLINK_IFCHANGED")
        return new AlgoFive(min, max, step, minUDF, maxUDF);
    else
    {
        cout << "Algorithm does not exist for sensor" << endl;
        return NULL;
    }
       
}
