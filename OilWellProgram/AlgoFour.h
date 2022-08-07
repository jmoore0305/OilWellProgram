#pragma once
#include "AlgoStrategy.h"
#include <iostream>
#include "Sensor.h"

class AlgoFour : public AlgoStrategy
{
private:
    double s_min;
    double s_max;
    double s_step;
    bool s_minUDF;
    bool s_maxUDF;
    double sensorCurrVal;
    double linkedSensorCurrVal;
public:
    AlgoFour(double, double, double, bool, bool);
    double execute();
    void sendData(double, double);
};