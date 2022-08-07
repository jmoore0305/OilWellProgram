#include "AlgoFour.h"


using namespace std;

AlgoFour::AlgoFour(double min, double max, double step, bool minUDF, bool maxUDF)
{
    s_min = min;
    s_max = max;
    s_step = step;
    s_minUDF = minUDF;
    s_maxUDF = maxUDF;
    sensorCurrVal = 0;
    linkedSensorCurrVal = 0;
}

double AlgoFour::execute()
{
    
    if (linkedSensorCurrVal > sensorCurrVal)
        return linkedSensorCurrVal;
    else
        return sensorCurrVal;
}

void AlgoFour::sendData(double senCurrVal, double linkSenCurrVal)
{
    sensorCurrVal = senCurrVal;
    linkedSensorCurrVal = linkSenCurrVal;
}



