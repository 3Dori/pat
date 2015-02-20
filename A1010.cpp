#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

inline long long c2d(char c) { return c >= '0' && c <= '9'? c - '0': c - 'a' + 10; }

long long s2i(char *s, long long radix) {
  long long res = 0;
  for (int i = 0; s[i]; i++) res = res * radix + c2d(s[i]);
  return res;
};

int main() {
  char s1[11], s2[11];
  int tag;
  long long r, n1;

  scanf("%s%s%d%lld", s1, s2, &tag, &r);

  if (tag == 2) {
    char tmp[11]; strcpy(tmp, s2); strcpy(s2, s1); strcpy(s1, tmp);
  }

  n1 = s2i(s1, r);

  long long Min = 2, Max = 2;
  for (int i = 0; s2[i]; i++) Min = max(Min, c2d(s2[i]) + 1);
  while (s2i(s2, Max) < n1) Max <<= 1;

  while (Min < Max) {
    long long mid = Min + ((Max - Min) >> 1);
    if (s2i(s2, mid) >= n1) Max = mid;
    else Min = mid + 1;
  }

  if (s2i(s2, Min) == n1) cout << Min;
  else cout << "Impossible";

  return 0;
}
