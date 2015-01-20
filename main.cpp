#include <iostream>
#include <math.h>
#include <vector>
#include <random>

using namespace std;

// functions: GBM(done), BM(done), DTMC(done), CTMC, PoissP(done)

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


  //simulate path
  double t = 0;
  double lambda = 0;
  for (int i=0; i<trans[start].size();i++){
    lambda += trans[start][i];
  };


    //1) start: t = 0
    //2) t += outward transition time ~exp(lambda = sum(state_row))
    //3)
    // if t < T
      // get next state via p(current_state -> state i) = state_row[i]/lambda
      // save transition state/time pair
      // go back to 2)
    // else
      // return transition history
};


int main(){

  vector< vector<double> > matrix (3);
  for ( int i = 0 ; i < 3 ; i++ ){
    matrix[i].resize(3);
  };
  matrix[0][1] = 0.25;
  matrix[0][2] = 0.75;
  matrix[1][0] = 1;
  matrix[2][0] = 1;

  vector< vector<double> > results = CTMC(matrix,1000,0);

  for(int i=0; i<results.size();i++){
    cout<<results[i]<<"\n";
  };

  return 1;
}