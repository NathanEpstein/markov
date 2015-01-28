#Markov.cpp

##Usage

1) Clone this library into your project

`git clone https://github.com/NathanEpstein/markov.git`

2) Make markov.o and libmarkov.a by calling `make` on this library's Makefile (assuming you aren't using a package manager which does this for you).

`cd markov && make`

3) Include the appropriate header in your project file

```c++
#include "../markov/markov.h"

int main(){
  // your code here...
}
```

4) Compile with `g++ myFile.cpp -L ../markov -l markov`

##Examples

####Poisson Process
```c++
#include "../markov/markov.h"

int main(){
  //SIMULATE A POISSON PROCESS
  double lambda = 6.2;
  double T = 10;
  std::vector<double> P = poissP(lambda,T) ;

  return 1;
}
```

#### Brownian Motion
```c++
#include "../markov/markov.h"

int main(){
  //SIMULATE BROWNIAN MOTION
  double mu = 0.8;
  double sigma = 0.2;
  double T = 10;
  int steps = 100;
  std::vector<double> brown = brownian(mu,sigma,T,steps);

  return 1;
}
```

#### Geometric Brownian Motion
```c++
#include "../markov/markov.h"

int main(){
  //SIMULATE GEOMETRIC BROWNIAN MOTION
  double S0 = 5;
  double mu = 0.8;
  double sigma = 0.2;
  double T = 10;
  int steps = 100;
  std::vector<double> geo = geoBrownian(S0,mu,sigma,T,steps);

  return 1;
}
```

#### Discrete and Continuous Time Markov Chains
```c++
#include "../markov/markov.h"

int main(){
  //SIMULATE DISCRETE AND CONTINUOUS TIME MARKOV CHAINS
  std::vector< std::vector<double> > matrix(3,std::vector<double> (3)); //initializes a 3x3 matrix with zeros

  //set transition matrix
  matrix[0][1] = 1;
  matrix[1][2] = 1;
  matrix[2][0] = 1;

  int steps = 10;
  int start = 0;
  double T = 8.5;
  //simulate discrete and continuous Markov Chains
  std::vector<int> discreteMC = DTMC(matrix,steps,start);
  std::vector< std::vector<double> > continousMC = CTMC(matrix,T,start);


  return 1;
}
```



