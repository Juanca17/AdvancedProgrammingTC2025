/*
* Juan Carlos Sanchez Cruz - A01631462
* Proyecto 3 - Programación Avanzada Ene-May 2018
* CodeChef - Small Airport
*/
#include <stdio.h>

int T;
//p = aeroplanes waiting to land (sky)
//q = aeroplanes waiting to take off (ground)
//m = arrive at
//n = take off waiting
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
        else {
          t++;
        }
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

int main() {
  scanf("%d",&T);
  int p,q,m,n,k;

  for(int i = 0; i < T; i++) {
    scanf("%d%d%d%d%d",&p, &q, &m, &n, &k);
    airport_status(p, q, m, n, k);
  }

  return 0;
}
