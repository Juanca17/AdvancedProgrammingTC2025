#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  int pid;
  pid = fork();
  if (pid == 0) {
    execl("/Applications/Calculator.app/Contents/MacOS/Calculator", "Calculator", (char *)0);
    printf("Hola soy el hijo mundo\n");
  }
  else {
    printf("Hola soy el padre mundo\n");
  }
  return 0;
}
