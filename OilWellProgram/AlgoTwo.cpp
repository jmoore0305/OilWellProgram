#include "AlgoTwo.h"

using namespace std;

AlgoTwo::AlgoTwo(double min, double max, double step, bool minUDF, bool maxUDF)
{
    s_min = min;
    s_max = max;
    s_step = step;
    s_minUDF = minUDF;
    s_maxUDF = maxUDF;
}



double AlgoTwo::execute()
{
    static int total = 0;
    int w = static_cast<int>(s_step);
    int x = static_cast<int>(s_min);
    int y = static_cast<int>(s_max);

    srand(time(0));     //randomizing results... (using time as an input)

    int z = 0 + (std::rand() % (w - 0 + 1));

    total += z;

    if (total < y)
    {
        double result = static_cast<double>(total);

        return result;

    }
    else
    {
        return s_max;
    }

}


