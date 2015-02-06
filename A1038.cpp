#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

#define P(x) (cout << #x  " is " << x << endl)
using namespace std;

inline bool comp(const string& lhs, const string& rhs) {
  // return true if rhs < lhs
  return lhs + rhs > rhs + lhs;
}

int main() {
  int N;
  bool head = true;
  string stmp;
  vector<string> vs;
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> stmp;
    vs.push_back(stmp);
  }
  make_heap (vs.begin(), vs.end(), comp);
  while (!vs.empty()) {
    stmp = vs.front();
    pop_heap (vs.begin(), vs.end(), comp); vs.pop_back();
    if (head){
      if (stoi(stmp) == 0){
        if (vs.empty())
          cout << 0;
      }
      else{
        cout << stoi(stmp);
        head = false;
      }
    }
    else {
      cout << stmp;
    }
  }

  return 0;
}
