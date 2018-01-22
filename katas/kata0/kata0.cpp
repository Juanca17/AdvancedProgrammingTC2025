#include <cstdio>
#include <vector>
#include <map>
using namespace std;

static vector<int> twoSum1(vector<int>& a, int t) {
  vector<int> r;

  for (int i = 0; i < a.size(); i++) {
    for (int j = i + 1; j < a.size(); j++) {
      if (a[j] == t - a[i]) {
        r.push_back(i);
        r.push_back(j);
        return r;
      }
    }
  }
  return r;
}

static vector<int> twoSum2(vector<int>& a, int t) {
  vector<int> r;
  map<int, int> hashtable;
  int temp;

  for (int i = 0; i < a.size(); i++) {
    hashtable.insert(pair <int,int> (a[i],i));
  }
  for (int i = 0; i < a.size(); i++) {
    temp = t - a[i];
    if (hashtable.count(temp) && hashtable.at(temp) != i) {
      r.push_back(i);
      r.push_back(hashtable.at(temp));
      return r;
    }
  }
  return r;
}

int main() {
  int nums[] = {5,4,8,3,7};
  vector<int> a(begin(nums), end(nums));
  int target = 7;

  //vector<int> r1 = twoSum1(a,target);
  //printf("\n{%i,%i}\n\n",r1[0],r1[1]);

  vector<int> r2 = twoSum2(a,target);
  printf("\n{%i,%i}\n\n",r2[0],r2[1]);
  return 0;
}
