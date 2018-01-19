#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a = 2147483647;
  int j,k,l;
  int *p;
  long int d = (long) a * a;
  float f = 4.67;
  int e = 4;
  int c = (int)f + e;
  p = &a;
  *p = 400;
  p++;
  *p = 5555;

  //printf("\na = %p, d = %ld, f = %f, e = %d, c = %d\n\n",&a,d,f,e,c);
  printf("\na = %d, p = %p, j = %d, k = %d, l = %d\n\n",a,p,j,k,l);
  return 0;
}
