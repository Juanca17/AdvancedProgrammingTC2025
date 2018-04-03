# Proyecto 2
###### Problem B. Haircut
### Context
You are waiting in a long line to get a haircut at a trendy barber shop. The shop has **B** barbers on duty, and they are numbered 1 through **B**. It always takes the **k** th barber exactly **M<sub>k</sub>** minutes to cut a customer's hair, and a barber can only cut one customer's hair at a time. Once a barber finishes cutting hair, he is immediately free to help another customer.

While the shop is open, the customer at the head of the queue always goes to the lowest-numbered barber who is available. When no barber is available, that customer waits until at least one becomes available.

You are the **N** th person in line, and the shop has just opened. Which barber will cut your hair?

### Input
The first line of the input gives the number of test cases, **T**. **T** test cases follow; each consists of two lines. The first contains two space-separated integers **B** and **N** -- the number of barbers and your place in line. The customer at the head of the line is number 1, the next one is number 2, and so on. The second line contains **M<sub>1</sub>**, **M<sub>2</sub>**, ..., **M<sub>B</sub>**.

### Output
For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the number of the barber who will cut your hair.

### Constraints
1 ≤ **T** ≤ 100.  
1 ≤ **N** ≤ 109.

Small dataset  
1 ≤ **B** ≤ 5.  
1 ≤ **M<sub>k</sub>** ≤ 25.

Large dataset  
1 ≤ **B** ≤ 1000.  
1 ≤ **M<sub>k</sub>** ≤ 100000.

### Break Down
We can build up a simulation looking at every barber at each minute, if it was a graph it would like a **Gantt chart**. But this won't be efficient since we have to look from time 0 up to 1000 * 100000 at the worst case!. So we have to find a good time interval so we can run the simulation from there. A good approach will be by using **binary search** to reduce the area of time where the client N will be served. This restricted interval have to be where the number of possible served customers by all barbers are less than N and the interval length is optimal. After this we can run a simulation; we can say that a barber is available if at a given time t, t is multiple of the his time needed to complete his duty: ```t % M[i] == 0```.

### Solution
```
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
```

### Analysis
This algorithm runs in O(B * (log n)) because the number of barbers affect directly on the time needed to limit the bounds on each binary search iteration.

### Deployment
To submission of [Problem B. Haircut] (https://code.google.com/codejam/contest/4224486/dashboard#s=p1&a=1)

To run the **Sample input** test  
```
make test
```

To run the program with the **Small dataset**  
```
make small
```

To run the program with the **Large dataset**  
```
make large
```
