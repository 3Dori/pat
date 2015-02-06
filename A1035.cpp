#include <iostream>
#include <string>
#include <vector>
#include <utility>
#define P(x) cout << #x " is " << x << endl
using namespace std;

bool replace_all(string& str, const string& from, const string& to) {
  if (from.empty())
    return false;
  size_t start_pos = 0;
  bool found = false;
  while ((start_pos = str.find(from, start_pos)) != string::npos) {
    str.replace(start_pos, from.length(), to);
    start_pos += to.length();
    found = true;
  }
  return found;
}

int main() {
  int N;
  string username, password;
  bool replaced;
  typedef vector<pair<string,string> > Record;
  Record record;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> username >> password;
    replaced = false;
    replaced |= replace_all(password, "1", "@");
    replaced |= replace_all(password, "0", "%");
    replaced |= replace_all(password, "l", "L");
    replaced |= replace_all(password, "O", "o");
    if (replaced)
      record.push_back(make_pair(username, password));
  }

  if (record.size() == 0)
    if (N > 1)
      cout << "There are " << N << " accounts and no account is modified";
    else
      cout << "There is 1 account and no account is modified";
  else {
    cout << record.size() << endl;
    cout << (*record.begin()).first << " " << (*record.begin()).second;
    for (Record::iterator it = record.begin() + 1; it != record.end(); it++) {
      cout << endl << (*it).first << " " << (*it).second;
    }
  }

  return 0;
}
