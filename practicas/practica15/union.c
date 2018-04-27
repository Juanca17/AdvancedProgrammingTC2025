#include <stdio.h>

typedef union i{
  char parts[4];
  unsigned dir;
}IpAddress;

int main(int argc, char const *argv[]) {
  IpAddress myAddress;
  myAddress.parts[0] = 127;
  myAddress.parts[1] = 0;
  myAddress.parts[2] = 0;
  myAddress.parts[3] = 1;

  printf("The number is %ud \n", myAddress.dir);
  myAddress.dir += 1;
  printf("The %d %d \n", myAddress.parts[0], myAddress.parts[3]);

  return 0;
}
