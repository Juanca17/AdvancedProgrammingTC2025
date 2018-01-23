#include <cstdio>
#include <vector>
#include <map>
using namespace std;

static vector<int> doFindAnagramMappings(vector<int>& A, vector<int>& B) {
  vector<int> r;
  map<int, int> hashtable;

  for (int i = 0; i < B.size(); i++) {
    hashtable.insert(pair <int,int> (B[i],i));
  }
  for (int i = 0; i < A.size(); i++) {
    r.push_back(hashtable.at(A[i]));
  }
  return r;
}

int main() {
  int a[] = {12,28,46,32,50};
  vector<int> A(begin(a), end(a));
  int b[] = {50,12,32,46,28};
  vector<int> B(begin(b), end(b));

  vector<int> r = doFindAnagramMappings(A, B);
  printf("\n{");
  for (int i = 0; i < r.size() - 1; i++) {
    printf("%d, ",r[i]);
  }
  printf("%d}\n\n",r[r.size()]);
  return 0;
}
