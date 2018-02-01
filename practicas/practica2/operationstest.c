#include <stdio.h>
#include "operations.h"

void printTestMessage(int, char *, char *);
void doTestAddition();
void doTestSubstraction();


int main() {
  doTestAddition();
  doTestSubstraction();
  return 0;
}

void printTestMessage(int testResult, char *passedMessage, char *failedMessage) {
  if(testResult) {
    if (result == expected) {
      printf("%s\n", passedMessage);
    }
    else {
      printf("%s\n", failedMessage);
    }
  }
}
void doTestAddition(){
  // Test addition
  int a = 21;
  int b = 7;
  int result = add(a, b);
  int expected = a + b;
  printTestMessage(result == expected, "Addition test passed", "Addition test failed");
}
void doTestSubstraction(){
  // Test Substraction
  int a = 21;
  int b = 7;
  int result = substraction(a, b);
  int expected = a - b;
  printTestMessage(result == expected, "Substraction test passed", "Substraction test failed");
}
