#include <stdio.h>

typedef struct d {
    unsigned char day:5;
    unsigned char month:4;
    unsigned short year;
} Date;

int main(int argc, char const *argv[]) {
  Date today = {26, 4, 2018};
  printf("Today is %d/%d/%d \n", today.day, today.month, today.year);
  
  if(today.day ^ 26 == 0) {
    printf("today is 26\n");
  }
  return 0;
}
