#include <iostream>
#include <math.h>
#include <time.h>
#include <vector>
#include <random>

using namespace std;

vector<double> U(int n){
  srand(time(NULL)); //this is still a problem
  vector<double> myVec(n);
  for (int i=0; i<n;i++){
    myVec[i] = (double)rand()/(double)RAND_MAX;
    cout<<myVec[i]<<"\n";
  };
  return myVec;
};

vector<double> exp(int n, double lambda){
  vector<double> myVec = U(n);
  for (int i=0; i<n; i++){
    myVec[i] = (-log(myVec[i])/lambda);
    // cout<<myVec[i]<<"\n";
  };
  return myVec;
};

vector<double> norm(int n, double mu, double sigma){
  vector<double> U1 = U(n);
  vector<double> U2 = U(n); //these two are initialized to the same place in the random sequence.
  vector<double> myVec(n);
  for (int i=0; i<n; i++){
    myVec[i] = sqrt(-2*log(U1[i]))*cos(2*U2[i]*M_PI);
    cout<<myVec[i]<<"\n";
  };
  return myVec;
};

int main(){
  norm(10,0,1);
  return 1;
};