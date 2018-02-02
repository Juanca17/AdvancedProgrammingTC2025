#include <iostream>
#include <string>
using namespace std;

bool isRouteCircle(string moves) {
  int x = 0;
  int y = 0;
  for (int i = 0; i < moves.length(); i++) {
    switch (moves[i]) {
      case 'U' : y++; break;
      case 'D' : y--; break;
      case 'R' : x++; break;
      case 'L' : x--; break;
    }
  }
  return x == 0 && y == 0;
}

int main(int argc, char const *argv[]) {
  string moves;
  cin >> moves;
  bool robot = isRouteCircle(moves);
  printf("%s\n", robot ? "true" : "false");
  return 0;
}
