#pragma once
#include "Sensor.h"
#include "AlgoStrategy.h"
#include "AlgoOne.h"
#include "AlgoTwo.h"
#include "AlgoThree.h"
#include "AlgoFour.h"
#include "AlgoFive.h"


class AlgoFactory
{
private:
    AlgoFactory();
public:

    static AlgoFactory* getInstance();
    AlgoStrategy* getDataGenAlgoForSensor(double, double, double, bool, bool ,char*);
};

