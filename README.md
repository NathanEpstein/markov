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

##