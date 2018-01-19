#include <stdio.h>

int swap_no(int a,int b) {
  int t;
  t = b;
  b = a;
  a = t;
  return 0;
}

int swap(int *a,int *b) {
  int t;
  t = *b;
  *b = *a;
  *a = t;
  return 0;
}

int main(int argc, char const *argv[]) {
  int i = 5, j = 10;
  swap_no(i,j);
  printf("\ni = %d, j = %d\n",i,j);
  swap(&i,&j);
  printf("\ni = %d, j = %d\n\n",i,j);
  return 0;
}
