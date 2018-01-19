#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a[] = {1,2,3,4,5};
  int *pa = a;
  *pa = 27;
  pa[2] = 45;
  *(pa + 3) = 200;
  for (int i = 0; i < sizeof(a)/sizeof(int); i++) {
    printf("\na[%d] = %d\n",i,a[i]);
  }
  printf("\n");
  return 0;
}
