#include <iostream>
using namespace std;

int main() {
  int cases;
  double a, b, c;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    cin >> a >> b >> c;
    cout << "Case #" << i + 1 << ": ";
    if (a + b > c)
      cout << "true" << endl;
    else
      cout << "false" << endl;
  }
  return 0;
}
