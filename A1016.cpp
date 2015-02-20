#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
#define P(x) cout << #x " is " << x << endl;

using namespace std;

//int rate[24];
int rate[24] = {10, 10, 10, 10, 10, 10, 20, 20, 20, 15, 15, 15, 15, 15, 15, 15, 20, 30, 20, 15, 15, 10, 10, 10};
int N;
string m2str[12] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};

struct Call {
  int day, hr, min;
  bool online;

  Call() {}
  Call(int day, int hr, int min, bool online):
    day(day), hr(hr), min(min), online(online)
  {}

  int operator-(Call& rhs) {
    return (day - rhs.day) * 1440 + (hr - rhs.hr) * 60 + (min - rhs.min);
  }

  Call& operator+=(int dmin) {
    min += dmin;
    if (min >= 60) {
      min = 0; hr++;
    }
    if (hr >= 24) {
      hr = 0; day++;
    }
    return *this;
  }

  bool operator<(const Call& rhs) const{
    if (day < rhs.day) return true;
    else if (day > rhs.day) return false;
    else if (hr < rhs.hr) return true;
    else if (hr > rhs.hr) return false;
    else if (min < rhs.min) return true;
    else return false;
  }
};

int get_bill(Call& begin, Call& end) {
  int total_min = end - begin;
  int bill = 0;
  printf("%02d:%02d:%02d ",
         begin.day, begin.hr, begin.min);
  while (begin < end) {
    if (end - begin < 60) {
      if (begin.hr == end.hr)
        bill += (end.min - begin.min) * rate[begin.hr];
      else {
        bill += (60 - begin.min) * rate[begin.hr];
        bill += (end.min) * rate[end.hr];
      }
      break;
    }
    if (begin.min != 0) {
      bill += (60 - begin.min) * rate[begin.hr];
      begin += 60 - begin.min;
    }
    else {
      bill += 60 * rate[begin.hr];
      begin += 60;
    }
  }
  printf("%02d:%02d:%02d %d $%.2lf\n",
         end.day, end.hr, end.min,
         total_min, (double)bill / 100);
  return bill;
}

struct Person {
  vector<Call> calls[12];    // each month

  void print_bill(string name) {
    for (int m = 0; m < 12; m++) {
      bool has_call = false;
      bool online = false;
      int total_amount = 0;
      if (!calls[m].empty()) {
        sort(calls[m].begin(), calls[m].end());
        Call begin, end;
        for (vector<Call>::iterator it = calls[m].begin();
             it != calls[m].end(); it++) {
          if (it->online) {
            begin = Call(*it);
            online = true;
          }
          else { // it->offline
            if (online) {
              if (!has_call) {
                has_call = true;
                cout << name << " " << m2str[m] << endl;
              }
              end = Call(*it);
              total_amount += get_bill(begin, end);
              online = false;
            }
            // else: no match
          }
        }
      }
      if (has_call)
        printf("Total amount: $%.2lf\n", (double)total_amount / 100);
    }
  }
};

void test() {
  Person p;
  Call begin(28, 15, 41, true), end(28, 16, 5, false);
  p.calls[0].push_back(begin);  p.calls[0].push_back(end);
  p.print_bill("CYJJ");
  return;
}

int main() {
  string name;
  char type[10];
  int mon, day, hr, min;
  map<string, Person> persons;
  // test(); return 0;
  for (int i = 0; i < 24; i++)
    cin >> rate[i];
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> name;
    scanf("%d:%d:%d:%d%s", &mon, &day, &hr, &min, type);
    bool t = (type[1] == 'n');
    persons[name].calls[mon-1].push_back(Call(day, hr, min, t));
  }

  for (map<string, Person>::iterator it = persons.begin();
       it != persons.end(); it++) {
    it->second.print_bill(it->first);    // Person.print_bill(name)
  }
  return 0;
}
