# Proyecto 3
###### Small Airport - CodeChef
### Context
A city has a small Airport with only one runway. At any time one aeroplane can land or one aeroplane can take off, but not both at the same time. Aeroplanes arrive at the airport airspace ready to land after every **m** units of time. The aeroplanes which will land will also take off after waiting **n** units of time. At any given time, the runway may be idle or a plane may be landing or taking off. At any time instant there may be several aeroplanes waiting either to land or take off. As it is always better to keep an aeroplane waiting on the ground than in the air, so this small airport allows an aeroplane to takeoff only when there are no aeroplanes waiting to land. Assuming that there are **p** aeroplanes waiting to land and **q** aeroplanes waiting to take off at time zero, write a program that will give the status of the aeroplanes after **k<sup>th</sup>** unit of time. Units of time are numbered starting from 0. Note that the aeroplanes that are there at the airport at time zero can take off at the earliest opportunity without the stipulated waiting time.

### Input
The number of test cases T (not more than 500) will be specified in the first line followed by the input for each test case. Each test case contains **p**, **q**, **m**, **n** and **k** separated by single spaces.

### Output
For each test case, print on a single line separated by spaces, the number of aeroplanes already landed, the number of aeroplanes already taken off, the number of aeroplanes still waiting to land and the number of aeroplaces still waiting to take off, respectively, after **k<sup>th</sup>** unit of time.

### Constraints
1 ≤ **T** ≤ 500.  
1 ≤ **p** ≤ 20.  
1 ≤ **q** ≤ 50.  
1 ≤ **m** ≤ 100.  
1 ≤ **n** ≤ 50.  
1 ≤ **k** ≤ 100000.

### Sample input
Input:  
3  
2 3 5 2 15  
3 2 3 5 10  
4 6 6 2 18  

Output:  
5 7 0 1  
6 5 0 3  
7 12 0 1  

### Break Down
The first approach I made to this problem is to manually simulate what would happened at minute k. I found then 4 main cases that can be evaluated systematically at each minute. For the case where an airplane wants to land it is simply to increase a variable and decrease **p** as this case is priority. For the case where the first airplane is going to take off, this variable it is increased. Then **qCount** (the number of aeroplanes currently on land) it is checked every n minutes to adjust the counters.

### Solution
```
int airport_status(int p, int q, int m, int n, int k) {
  int qCount = 0;
  int mCount = m;
  int landed = 0;
  int takeoff = 0;

  int time[100000];
  int t = 0;

  int i = 0;
  int j = 0;
  while(t <= k) {
    if(p) { // Case: airplane is on air
      p--;
      landed++;
      time[i] = t;
      i++;
      t++;
      qCount++;
    }
    else {
      if(q) { // Case: airplane want to take off and sky's free
        q--;
        takeoff++;
        t++;
      }
      else { // Case: airplane want to take off after n time
        if(t >= (time[j]+n) && qCount) {
          takeoff++;
          qCount--;
          t++;
          j++;
        }
        else
        t++;
      }
    }

    if(t == mCount) { // Case: airplane arrive after m time
      p++;
      mCount = mCount + m;
    }
  }

  int qWaiting = q + qCount;
  printf("%d %d %d %d\n",landed, takeoff, p, qWaiting);

  return 0;
}
```

### Analysis
This algorithm runs in O(n) as there are not nested loops, and for the simulation the only cost is the max time to check **k**.

### Deployment
To submission of [Small Airport](https://www.codechef.com/problems/NI04)

To run the **Sample input** test  
```
make test
```
