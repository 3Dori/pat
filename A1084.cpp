#include <iostream>
#include <string>
#include <map>
#define P(x) cout << #x " is " << x << endl;

using namespace std;

int main() {
  string org, out;
  map<char, bool> detected;
  cin >> org >> out;
  for (size_t i = 0, j = 0; i < org.length() && j < out.length();) {
    if (org[i] == out[j]) {
      i++;
      j++;
    }
    else {
      if (org[i] >= 'a' && org[i] <= 'z')
        org[i] -= 32;
      if (detected.find(org[i]) == detected.end()) {
        cout << org[i];
        detected[org[i]] = true;
      }
      i++;
    }
  }
  return 0;
}
