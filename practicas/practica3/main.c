#include <stdio.h>
#include <math.h>

double buf[128 * 1024];
int main() {
  int i = 0;
  unsigned long long n;
  while (scanf("%llu", &n) != EOF) {
    buf[i] = (double)sqrt(n * 1.0);
    i++;
  }
  while (i != 0) {
    i--;
    printf("%.4lf\n", buf[i]);
  }

  return 0;
}
