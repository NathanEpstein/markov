#include <math.h>
#include <vector>
#include <random>

bool sortAsc(double,double);

std::vector<double>poissP(double, double);

std::vector<double> brownian(double, double, double, int);

std::vector<double> geoBrownian(double,double,double, double, int);

std::vector<int> DTMC (std::vector< std::vector<double> >, int, int);

class CTMC{
public:
  CTMC(std::vector< std::vector<double> > initMatrix);
  ~CTMC();
  void simulate(double T, int state);
  std::vector<int> getStates();
  std::vector<double> transTimes();
protected:
  std::vector< std::vector<double> > matrix;
  std::vector<int> states;
  std::vector<double> times;
};
