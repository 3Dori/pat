#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct P {
  int exp;
  double coe;

  bool operator<(const P& other) const { return exp > other.exp; }    // sort by exp
};

int main() {
  P p1[10], p2[10];
  vector<P> res;

  int n1, n2, exp;
  double coe;
  cin >> n1;
  for (int i = 0; i < n1; i++) {
    cin >> p1[i].exp >> p1[i].coe;
  }
  cin >> n2;
  for (int i = 0; i < n2; i++) {
    cin >> p2[i].exp >> p2[i].coe;
  }

  int nr = 0;
  for (int i = 0; i < n1; i++) {
    for (int j = 0; j < n2; j++) {
      exp = p1[i].exp + p2[j].exp;
      coe = p1[i].coe * p2[j].coe;
      for (vector<P>::iterator it = res.begin(); it != res.end(); it++) {
        if (it->exp == exp) {
          it->coe += coe;
          goto NEXT;
        }
      }
      res.push_back((P){exp, coe});
      nr++;
    NEXT:;
    }
  }
  sort(res.begin(), res.end());

  int n = 0;
  for (vector<P>::iterator it = res.begin(); it != res.end(); it++) {
    if (abs((int)it->coe) < 1e-5);
    else n++;
  }
  cout << n;
  for (vector<P>::iterator it = res.begin(); it != res.end(); it++) {
    if (abs((int)it->coe) < 1e-5);
    else printf(" %d %.1lf", it->exp, it->coe);
  }
  return 0;
}
