#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define P(x) cout << #x " is " << x << endl
#define For(i, x) for (int i = 0; i < x; i++)
using namespace std;

int N, M;
struct Stu {
  int c, m, e, a;
  int ar, cr, mr, er;

  Stu() {}
  Stu(int c, int m, int e):
    c(c), m(m), e(e), a((c+m+e)/2)
  {}
};
typedef Stu *pStu;

inline int cmpc(const pStu lhs, const pStu rhs) {
  return lhs->c > rhs->c;
}

inline int cmpm(const pStu lhs, const pStu rhs) {
  return lhs->m > rhs->m;
}

inline int cmpa(const pStu lhs, const pStu rhs) {
  return lhs->a > rhs->a;
}

inline int cmpe(const pStu lhs, const pStu rhs) {
  return lhs->e > rhs->e;
}

vector<pStu> stus;
map<int,Stu> has_stu;

int main() {
  cin >> N >> M;
  For (i, N) {
    int id, c, m, e;
    cin >> id >> c >> m >> e;
    has_stu[id] = Stu(c, m, e);
    stus.push_back(&has_stu[id]);
  }
  int rank, last, rank_count;
  // sort by a, c, m, e
  // a
  sort(stus.begin(), stus.end(), cmpa);
  rank = 0; last = -1; rank_count = 1;
  for (vector<pStu>::iterator it = stus.begin();
       it != stus.end(); it++) {
    if (last == (*it)->a) {
      rank_count++;
      (*it)->ar = rank;
    }
    else {
      rank += rank_count;
      (*it)->ar = rank;
      rank_count = 1;
    }
    last = (*it)->a;
  }
  // c
  sort(stus.begin(), stus.end(), cmpc);
  rank = 0; last = -1; rank_count = 1;
  for (vector<pStu>::iterator it = stus.begin();
       it != stus.end(); it++) {
    if (last == (*it)->c) {
      rank_count++;
      (*it)->cr = rank;
    }
    else {
      rank += rank_count;
      (*it)->cr = rank;
      rank_count = 1;
    }
    last = (*it)->c;
  }
  // m
  sort(stus.begin(), stus.end(), cmpm);
  rank = 0; last = -1; rank_count = 1;
  for (vector<pStu>::iterator it = stus.begin();
       it != stus.end(); it++) {
    if (last == (*it)->m) {
      rank_count++;
      (*it)->mr = rank;
    }
    else {
      rank += rank_count;
      (*it)->mr = rank;
      rank_count = 1;
    }
    last = (*it)->m;
  }
  // e
  sort(stus.begin(), stus.end(), cmpe);
  rank = 0; last = -1; rank_count = 1;
  for (vector<pStu>::iterator it = stus.begin();
       it != stus.end(); it++) {
    if (last == (*it)->e) {
      rank_count++;
      (*it)->er = rank;
    }
    else {
      rank += rank_count;
      (*it)->er = rank;
      rank_count = 1;
    }
    last = (*it)->e;
  }

  For (i, M) {
    int id;
    cin >> id;
    if (has_stu.find(id) != has_stu.end()) {
      Stu& s = has_stu[id];
      int maxr = s.er;
      char maxrt = 'E';
      if (s.mr <= maxr) {
        maxr = s.mr;
        maxrt = 'M';
      }
      if (s.cr <= maxr) {
        maxr = s.cr;
        maxrt = 'C';
      }
      if (s.ar <= maxr) {
        maxr = s.ar;
        maxrt = 'A';
      }
      cout << maxr << " " << maxrt << endl;
    }
    else {
      cout << "N/A\n";
    }
  }
  return 0;
}
