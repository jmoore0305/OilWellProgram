#include "AlgoThree.h"


using namespace std;

AlgoThree::AlgoThree(double min, double max, double step, bool minUDF, bool maxUDF)
{
    s_min = min;
    s_max = max;
    s_step = step;
    s_minUDF = minUDF;
    s_maxUDF = maxUDF;
}

double AlgoThree::execute()
{

    int w = static_cast<int>(s_step);
    int x = static_cast<int>(s_min);
    static int y = static_cast<int>(s_max);

    srand(time(0));     //randomizing results... (using time as an input)

    int z = 0 + (std::rand() % (w - 0 + 1));

    y -= z;

    if (y > x)
    {
        double result = static_cast<double>(y);
        return result;
    }
    else
    {
        return s_min;
    }


}