#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int lbound, hbound;

enum cls {sage, nobleman, fool, small, out};
struct p {
  int id;
  int v;
  int t;
  cls thecls;

  void set_thecls() {
    if (t < lbound || v < lbound)
      thecls = out;
    else if (v >= hbound && t >= hbound)
      thecls = sage;
    else if (v >= hbound && t < hbound)
      thecls = nobleman;
    else if (t < hbound && v < hbound && v >= t)
      thecls = fool;
    else
      thecls = small;
  }

  bool operator<(const p& other) const {
    if (thecls < other.thecls)
      return true;
    if (thecls > other.thecls)
      return false;
    if (v + t > other.v + other.t)
      return true;
    if (v + t < other.v + other.t)
      return false;
    if (v > other.v)
      return true;
    if (v < other.v)
      return false;
    return id < other.id;
  }
};

int main() {
  int N;
  p people[100000], tmp;
  cin >> N >> lbound >> hbound;
  int count = 0;
  for (int i = 0; i < N; i++) {
    cin >> tmp.id >> tmp.v >> tmp.t;
    tmp.set_thecls();
    if (tmp.thecls != out) {
      people[count++] = tmp;
    }
  }
  sort(people, people + count);
  cout << count << endl;
  for (int i = 0; i < count; i++)
    printf("%08d %d %d\n", people[i].id, people[i].v, people[i].t);

  return 0;
}
