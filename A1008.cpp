#include <iostream>
#define forrange(i, N) for (int i = 0; i < N; i++)
using namespace std;

int main() {
  int N, floor, now_floor = 0;
  int time = 0;
  cin >> N;
  forrange(i, N) {
    cin >> floor;
    if (floor > now_floor) {
      time += (floor - now_floor) * 6;
    }
    else {
      time += (now_floor - floor) * 4;
    }
    now_floor = floor;
    time += 5;
  }
  cout << time;
  return 0;
}
