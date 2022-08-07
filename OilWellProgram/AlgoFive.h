#pragma once
#include "AlgoStrategy.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

class AlgoFive : public AlgoStrategy
{
private:
    double s_min;
    double s_max;
    double s_step;
    bool s_minUDF;
    bool s_maxUDF;
    double linkedSenPrevValue;
    double linkedSenCurrValue;
public:
    AlgoFive(double, double, double, bool, bool);
    double execute();
    void sendData(double, double);
};