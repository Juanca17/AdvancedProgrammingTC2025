#include <cstdio>
#include <vector>
using namespace std;

bool validUtf8(vector<int>& data) {
  int continuation_bytes = 0;
  for (int i = 0; i < data.size(); i++) {
    if (continuation_bytes == 0) {
      if ((data[i] >> 5) == 0b110) continuation_bytes = 1;
      else if ((data[i] >> 4) == 0b1110) continuation_bytes = 2;
      else if ((data[i] >> 3) == 0b11110) continuation_bytes = 3;
      else if ((data[i] >> 7)) return false; // 0xxxxxxx
    }
    else {
      if ((data[i] >> 6) != 0b10) {
        return false;
      }
      continuation_bytes--;
    }
  }

  return continuation_bytes == 0;
}

int main(int argc, char const *argv[]) {
  vector<int> data;
  data.push_back(197);
  data.push_back(130);
  data.push_back(1);
  printf("%s\n", validUtf8(data) ? "true" : "false");

  data.clear();
  data.push_back(235);
  data.push_back(140);
  data.push_back(4);
  printf("%s\n", validUtf8(data) ? "true" : "false");
  return 0;
}
