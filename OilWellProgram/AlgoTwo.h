#pragma once
#include "AlgoStrategy.h"
#include <iostream>
#include <ctime>
#include <cstdlib>


class AlgoTwo : public AlgoStrategy
{
private:
    double s_min;
    double s_max;
    double s_step;
    bool s_minUDF;
    bool s_maxUDF;
public:
    AlgoTwo(double, double, double, bool, bool);
    double execute();
};