#include <stdio.h>
#include <string.h>

#include "operations.h"

int main() {
  char operation[200];
  char addCheck[200] = "add";
  char subCheck[200] = "substraction";

  int operator1, operator2;
  printf("%s\n","What is the operation?");
  scanf("%s",operation);
  scanf("%d %d",&operator1, &operator2);
  if (strcmp(operation,addCheck) == 0) {
    printf("result: %d\n",add(operator1,operator2));
  }
  else if (strcmp(operation,subCheck) == 0) {
    printf("result: %d\n",substraction(operator1,operator2));
  }

  return 0;
}
