#include <iostream>
#include <cmath>
#define P(x) cout << #x " is " << x << endl
using namespace std;

bool is_prime(int n) {
  if (n <= 1) return false;
  int q = (int)sqrt(n+0.1);
  for (int i = 2; i <= q; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

int reverse(int n, int d) {
  int res = 0;
  while (n) {
    res = res * d + n % d;
    n /= d;
  }
  return res;
}

int main() {
  int n, d;
  while (true) {
    cin >> n;
    if (n > 0) {
      cin >> d;
      if (is_prime(n) && is_prime(reverse(n, d)))
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
    else
      break;
  }

  return 0;
}
