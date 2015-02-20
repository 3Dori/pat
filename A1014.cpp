#include <iostream>
#include <cstdio>
#include <list>
#define INF 0x6ffffff
using namespace std;
struct Customer {
  int index;
  int time;
};

inline int time2min(int hr, int min) {
  return hr * 60 + min;
}

int customers[1000];
int queries[1000], finish[1000];
int n, m, k, q;
list<Customer> windows[20];
const int time_8 = time2min(8, 0);
const int close = time2min(17, 0);

inline Customer pop_q(list<Customer>& q) {
  Customer elem = q.front();
  q.pop_front();
  return elem;
}

inline void print_time(int min) {
  if (min == 0)
    printf("Sorry\n");
  else
    printf("%02d:%02d\n", min / 60, min % 60);
}

inline Customer get_customer(int index) {
  return (Customer){index, customers[index]};
}

int min_index() {
  int min_index = 0, min = INF;
  for (int i = 0; i < n; i++) {
    if (!windows[i].empty())
      if (windows[i].front().time < min) {
        min = windows[i].front().time;
        min_index = i;
      }
  }
  return min_index;
}

void update_time(int time, int window) {
  for (int i = 0; i < n; i++) {
    if (i != window && !windows[i].empty())
      windows[i].front().time -= time;
  }
}

int main() {
  cin >> n >> m >> k >> q;
  for (int i = 0; i < k; i++) {
    cin >> customers[i];
  }
  for (int i = 0; i < q; i++) {
    cin >> queries[i];
  }

  int cut = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (cut < k)
        windows[j].push_back(get_customer(cut++));
      else
        goto BREAK;
    }
  }
 BREAK:;

  int now = time_8;
  int count = 0;
  while (count < k) {
    int min_window = min_index();
    Customer last = pop_q(windows[min_window]);
    now += last.time;
    update_time(last.time, min_window);
    if (cut < k) {
      windows[min_window].push_back(get_customer(cut++));
    }
    finish[last.index] = now;
    if (now >= close)
      break;
    else
      finish[last.index] = now;
    count++;
  }

  for (int i = 0; i < q; i++) {
    print_time(finish[queries[i]-1]);
  }
}
