/*
* Juan Carlos Sanchez Cruz - A01631462
* Proyecto 2 - Programación Avanzada Ene-May 2018
* Google Code Jam Round 1A 2015 - Problem B. Haircut
*/
#include <cstdio>
using namespace std;

int T, B, M[1010];
long long N;

long long costumersServed(long long t) {
  long long costumers = 0;
  for(int i = 1; i <= B; i++) { // total number of costumers served by all barbers at time t
    costumers += t / M[i]+1;
  }
  return costumers;
}

int getBarberNumber() {
  long long leftBound = 0, rightBound = N * M[1];

  while(leftBound < rightBound) { // binary search for a time to make the simulation
    long long mid = leftBound + (rightBound - leftBound)/2;
    if(costumersServed(mid) < N) {
      leftBound = mid + 1;
    }
    else {
      rightBound = mid;
    }
  };

  int c = 0;
  long long lastCostumer = costumersServed(leftBound-1); // customer where to start the simulation

  if(N == lastCostumer) {
    return B;
  }
  else {
    for(int i = 1; i <= B; i++) {
      if(leftBound % M[i] == 0) { // if a barber is available
        if(c+1 == N-lastCostumer) {
          return i;
        }
        else {
          c++;
        }
      }
    }
  }

  return 0;
}

int main(int argc, char const *argv[]) {
  scanf("%d", &T);

  for(int i = 1; i <= T; i++) {
    scanf("%d %lld", &B, &N);
    for(int j = 1; j <= B; j++) {
      scanf("%d", &M[j]);
    }
    fprintf(stdout, "Case #%d: %d\n", i, getBarberNumber());
  }
  return 0;
}
