#include <iostream>
#include <cstdio>
using namespace std;

int time2sec(int hr, int min, int sec) {
  return hr * 3600 + min * 60 + sec;
}

int main() {
  int N;
  int hr, min, sec, total_sec;
  string id, in_id, out_id;
  int earliest, latest;
  earliest = time2sec(23, 59, 59);
  latest = time2sec(0, 0, 0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> id;
    scanf("%d:%d:%d", &hr, &min, &sec);
    total_sec = time2sec(hr, min, sec);
    if (total_sec < earliest) {
      earliest = total_sec;
      in_id = id;
    }
    scanf("%d:%d:%d", &hr, &min, &sec);
    total_sec = time2sec(hr, min, sec);
    if (total_sec > latest) {
      latest = total_sec;
      out_id = id;
    }
  }
  cout << in_id << " " << out_id;

  return 0;
}
