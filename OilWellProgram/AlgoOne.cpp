#include "AlgoOne.h"

using namespace std;

AlgoOne::AlgoOne(double min, double max, double step, bool minUDF, bool maxUDF)
{
    s_min = min;
    s_max = max;
    s_step = step;
    s_minUDF = minUDF;
    s_maxUDF = maxUDF;
}

double AlgoOne::execute()
{

    srand(time(0));     //randomizing results... (using time as an input)

    int x = static_cast<int>(s_min);

    int y = static_cast<int>(s_max);

    int z = x + (std::rand() % (y - x + 1));

    double result = static_cast<double>(z);

    return result;
}


