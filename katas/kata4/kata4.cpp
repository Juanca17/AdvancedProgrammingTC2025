#include <string>
#include <iostream>
#include <ctype.h>
using namespace std;

bool isNumber(string s) {
  int i = 0;

  while (s[i] ==  ' ') {
    i++;
  }

  if (s[i] == '+' || s[i] == '-') {
    i++;
  }
  else if (s[i] == '.') {
    for (int j = 1; j < s.length() - 1; j++) {
      if (isdigit(s[j]) == 0 && s[j] != ' ') {
        return 0;
      }
    }
    i++;
  }
  else if (isdigit(s[i]) == 0) {
    return 0;
  }

  int digit, point;
  for(digit = 0, point = 0; isdigit(s[i]) || s[i]=='.'; i++) {
    if (s[i] == '.') {
      if (isdigit(s[i+1])) {
        point++;
      }
      else {
        return 0;
      }
    }
    else {
      digit++;
    }
  }

  if(point>1 || digit<1) {
    return 0;
  }

  if(s[i] == 'e') {
    i++;
    if(s[i] == '+' || s[i] == '-') {
      i++;
    }
    int exponent = 0;
    while (isdigit(s[i])) {
      i++;
      exponent++;
    }
    if(exponent<1) {
      return 0;
    }
  }

  while (s[i] ==  ' ') {
    i++;
  }

  return s[i] == 0;
}
int main(int argc, char const *argv[]) {
  cout << boolalpha;
	cout << isNumber(".53 ") << endl;
  return 0;
}
