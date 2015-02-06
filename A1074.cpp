#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

struct List {
  int val, next;
};

List L[100000];

int main() {
  int first_addr, N, K, addr;
  stack<int> S;

  cin >> first_addr >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> addr;
    cin >> L[addr].val >> L[addr].next;
  }

  addr = first_addr;
  int now = 0, next;
  while (now + K <= N) {
    for (int i = 0; i < K; i++) {
      S.push(addr);
      addr = L[addr].next;
    }    // push K
    next = addr;
    addr = S.top();
    for (int i = 0; i < K - 1; i++) {
      printf("%05d ", addr);
      printf("%d ", L[addr].val);
      S.pop();
      addr = S.top();
      printf("%05d\n", addr);
    }
    if (now + K != N) {
      printf("%05d ", addr);
      printf("%d ", L[addr].val);
      S.pop();
      printf("%05d\n", next);
    }
    else {
      printf("%05d ", addr);
      printf("%d ", L[addr].val);
      printf("-1");
    }
    now += K;
    addr = next;
  }
  for (; now < N; now++) {
    printf("%05d ", addr);
    printf("%d ", L[addr].val);
    if (now == N - 1)
      printf("-1");
    else {
      addr = L[addr].next;
      printf("%05d\n", addr);
    }
  }

  return 0;
}
