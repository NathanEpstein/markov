#include <math.h>
#include <vector>
#include <random>

using namespace std;

//sorting function, to sort arrival times in poissP
bool sortAsc(double i,double j){
  return (i<j);
};

//Markov simulation functions
vector<double> poissP(double lambda, double T){
  random_device rd;
  mt19937 gen(rd());
  poisson_distribution<> P(lambda*T);

  //generate number of arrivals (n), arrival times are ~U(0,T) (given n).
  int n = P(gen);
  vector<double> myVec(n);
  for (int i=0; i<n; i++){
    myVec[i] = generate_canonical<double,10>(gen)*T;
  };
  //sort the arrival times and return the vector
  sort(myVec.begin(),myVec.end(),sortAsc);
  return myVec;
};

vector<double> brownian(double mu, double sigma, double T, int steps){
  double dt = T/steps;
  vector<double> myVec(steps+1);

  //generator for determining dB in each increment
  random_device rd;
  mt19937 gen(rd());
  normal_distribution<>norm(mu*dt,sigma*sqrt(dt));

  //generate BM, step by step
  myVec[0] = 0;
  for(int i=0; i<steps; i++){
    myVec[i+1] = myVec[i] + norm(gen);
  };
  return myVec;
};

vector<double> geoBrownian(double S0,double mu,double sigma, double T, int steps){
  // generate BM vector
  vector<double> myVec = brownian(mu,sigma,T,steps);
  // and map each element
  for(int i=0; i<myVec.size();i++){
    myVec[i] = S0*exp(myVec[i]);
  };
  return myVec;
};

vector<int> DTMC (vector< vector<double> > trans, int steps, int start){
  //random generator
  random_device rd;
  mt19937 gen(rd());
  //initialize state vector
  vector<int> myVec(steps+1);
  myVec[0] = start;
  //initialize counter variables
  int count;
  double sum;
  double U;

  //for each step, simulate the next step from the current state row
  for(int i=0; i<steps; i++){
    count = 0;
    sum = 0;
    U = generate_canonical<double,10>(gen);
    while(sum < U){
      sum += trans[myVec[i]][count];
      if(sum > U){
        myVec[i+1] = count;
      };
      count++;
    };
  };
  return myVec;
};

vector< vector<double> > CTMC(vector< vector<double> > trans, double T, int start){
  //random generator
  random_device rd;
  mt19937 gen(rd());
  // results vector
  vector< vector<double> > myVec;

  //include the beggining of the CTMC in the results
  vector<double> myStep;
  myStep.push_back(0); //start time
  myStep.push_back(start); //start state
  myVec.push_back(myStep); //initialize results vector

  // local variables
  double t = 0;
  double lambda;
  double U;
  double sum;
  int j;
  int state;

  //for each transition
  while (t < T){
    lambda = 0;
    state = myStep[1];
    for (int i=0; i<trans[state].size();i++){
      lambda += trans[state][i];
    };
    exponential_distribution<> stepT(lambda);
    t += stepT(gen);
    if (t < T){
      //determine new state
      j = 0;
      sum = 0;
      U = generate_canonical<double,10>(gen);
      while(sum < U){
        sum += trans[state][j]/lambda;
        if (sum > U){
          //push time and state
          myStep.clear();
          myStep.push_back(t);
          myStep.push_back(j);
          myVec.push_back(myStep);
        }
        else{
          j++;
        };
      };
    };

  };
  return myVec;
};