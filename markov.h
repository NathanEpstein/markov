#include <math.h>
#include <vector>
#include <random>

bool sortAsc(double,double);

std::vector<double>poissP(double, double);

std::vector<double> brownian(double, double, double, int);

std::vector<double> geoBrownian(double,double,double, double, int);

std::vector<int> DTMC (std::vector< std::vector<double> >, int, int);

std::vector< std::vector<double> > CTMC(std::vector< std::vector<double> >, double, int);