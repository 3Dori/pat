#include <iostream>
using namespace std;

struct S {
  string name;
  string id;
  int grade;

  S(string name, string id, int grade):
    name(name), id(id), grade(grade)
  {}
};

int main() {
  string name, id;
  char gender;
  int grade;
  bool na;
  int N;
  S max_f("n", "n", -1), min_m("n", "n", 101);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> name >> gender >> id >> grade;
    if (gender == 'M') {
      if (grade < min_m.grade)
        min_m = S(name, id, grade);
    }
    else {
      if (grade > max_f.grade)
        max_f = S(name, id, grade);
    }
  }
  if (max_f.grade == -1) {
    cout << "Absent\n";
    na = true;
  }
  else
    cout << max_f.name << " " << max_f.id << endl;
  if (min_m.grade == 101) {
    cout << "Absent\n";
    na = true;
  }
  else
    cout << min_m.name << " " << min_m.id << endl;
  if (na)
    cout << "NA";
  else
    cout << max_f.grade - min_m.grade;
  return 0;
}
