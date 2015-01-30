#markov

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

  return 0;
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

  return 0;
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

  return 0;
}
```

#### Discrete Time Markov Chains
```c++
#include "../markov/markov.h"

int main(){
  //SIMULATE DISCRETE TIME MARKOV CHAIN
  std::vector< std::vector<double> > matrix(3,std::vector<double> (3)); //initializes a 3x3 matrix with zeros

  //set transition matrix
  matrix[0][1] = 1;
  matrix[1][2] = 1;
  matrix[2][0] = 1;

  int steps = 10;
  int start = 0;
  double T = 8.5;
  //simulate discrete time Markov Chain
  std::vector<int> discreteMC = DTMC(matrix,steps,start);

  return 0;
}
```

#### Continuous Time Markov Chains
```c++
#include "../markov/markov.h"

int main(){
  //SIMULATE CONTINUOUS TIME MARKOV CHAIN
  std::vector< std::vector<double> > matrix(3,std::vector<double> (3)); //initializes a 3x3 matrix with zeros

  //set transition matrix
  matrix[0][1] = 1;
  matrix[1][2] = 1;
  matrix[2][0] = 1;

  int start = 0;
  double T = 8.5;
  //simulate continuous time Markov Chain
  CTMC continuousMC(matrix);
  continuousMC.simulate(T,start);

  std::vector<double> times = continuousMC.transTimes();
  std::vector<int> states = continuousMC.getStates();

  return 0;
}
```

### Previous Version

This library initially implemented CTMC as a function which returned a matrix instead of a class. To access the original (deprecated) version use `git clone -b v1 https://github.com/NathanEpstein/markov.git`

## License

**The MIT License (MIT)**

> Copyright (c) 2014 Nathan Epstein
>
> Permission is hereby granted, free of charge, to any person obtaining a copy
> of this software and associated documentation files (the "Software"), to deal
> in the Software without restriction, including without limitation the rights
> to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
> copies of the Software, and to permit persons to whom the Software is
> furnished to do so, subject to the following conditions:
>
> The above copyright notice and this permission notice shall be included in
> all copies or substantial portions of the Software.
>
> THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
> IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
> FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
> AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
> LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
> OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
> THE SOFTWARE.



