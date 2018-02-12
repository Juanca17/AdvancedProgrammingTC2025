/*
* Juan Carlos Sanchez Cruz - A01631462
* Proyecto 1 - Programación Avanzada Ene-May 2018
* Timus Online Judge - 1203. Scientific Conference
*/
#include <cstdio>
#include <algorithm>
using namespace std;

struct report{
  int start;
	int end;
};

bool operator<(report a, report b) {
	return a.end < b.end;
}

int main(int argc, char const *argv[]) {
  int N;
  scanf("%d", &N);

  report reports[100000];

  for(int i = 0; i < N; i++) {
    scanf("%d %d", &reports[i].start, &reports[i].end);
  }
  sort(reports, reports + N);

  int lastAttended = 0, count = 0;

  for (int i = 0; i < N; i++) {
    if (reports[i].start > lastAttended) {
      lastAttended = reports[i].end;
      count++;
    }
  }

  printf("%d\n", count);

  return 0;
}
