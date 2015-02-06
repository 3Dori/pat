#include <iostream>
#include <algorithm>

using namespace std;
struct Mooncake {
  double inventory;
  double price;
  double ratio;

  bool operator<(const Mooncake& other) const { return ratio > other.ratio; }
};

Mooncake mc[1001];

int main() {
  int N, demand, used;
  double total;
  cin >> N >> demand;
  //Mooncake *mc = new Mooncake[N];
  for (int i = 0; i < N; i++)
    cin >> mc[i].inventory;
  for (int i = 0; i < N; i++)
    cin >> mc[i].price;
  for (int i = 0; i < N; i++)
    mc[i].ratio = mc[i].price / mc[i].inventory;
  sort(mc, mc + N);
  used = 0; total = 0;
  for (int i = 0; i < N; i++) {
    if (used >= demand) break;
    if (mc[i].inventory <= demand - used) {
      used += mc[i].inventory;
      total += mc[i].price;
    }
    else {
      total += (double)(demand - used) / mc[i].inventory * mc[i].price;
      used = demand;
    }
  }
  printf("%.2lf", total);
  return 0;
}
