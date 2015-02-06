#include <iostream>
#include <set>
#include <cstdio>
using namespace std;
#define P(x) cout << #x " is " << x << endl;

void ncnt(set<int>& s1, set<int>& s2) {
  int nc = 0, nt = 0;
  // s1 an s2 are internal sorted
  // and no common in each set
  set<int>::iterator it1, it2;
  it1 = s1.begin();
  it2 = s2.begin();
  while (it1 != s1.end() && it2 != s2.end()) {
    if (*it1 == *it2) {
      nt++;
      nc++;
      it1++;
      it2++;
    }
    else if (*it1 < *it2) {
      nt++;
      it1++;
    }
    else {
      nt++;
      it2++;
    }
  }

  for (; it2 != s2.end(); it2++)
    nt++;
  for (; it1 != s1.end(); it1++)
    nt++;
  printf("%.1lf%%\n", double(nc) / nt * 100);
}

int main() {
  set<int> sets[51];
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int size;
    cin >> size;
    for (int j = 0; j < size; j++) {
      int elem;
      cin >> elem;
      sets[i].insert(elem);
    }
  }
  int K;
  cin >> K;
  for (int i = 0; i < K; i++) {
    int i1, i2;
    cin >> i1 >> i2;
    ncnt(sets[i1 - 1], sets[i2 - 1]);
  }
  return 0;
}
