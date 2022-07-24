#ifndef __PL__
#define __PL__

#include <vector>
#include <string>

class LinearProgram
{
private:
    size_t month;
    std::vector<int> demandas;
    std::vector<int> afluencia;
    int min;
    int max;
    int vini;
    int tmax;
    float k;
    float ct;
    float ca;

public:
    LinearProgram(std::string filename);
    LinearProgram();
    //~LinearProgram();

    void toFile(std::string filename);
};

#endif

// 3        numero de meses
// 900 1000 950   demanda em cada
// 500 800 200    afluencias
// 500 200 1000 1.1    inicial min max k
// 1000 0.2      termo max custo
// 0.005      custo amb