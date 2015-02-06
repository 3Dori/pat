#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define P(x) cout << #x " = " << x << endl;
using namespace std;
int full_score[6];
int problem_n, people_n, submit_n;

class User {
public:
  int id;
  int scores[6];
  bool show_in_list;

  User(int id): id(id), show_in_list(false) {
    for (int p_id = 0; p_id < problem_n; p_id++)
      scores[p_id] = -1;    // un compiled
  }

  void update(int p_id, int score) {
    if (score != -1) {
      scores[p_id] = max(scores[p_id], score);
      show_in_list = true;
    }
    else if (scores[p_id] == -1)
      scores[p_id] = 0;
  }

  int get_total_score() const {
    int sum = 0;
    for (int p_id = 0; p_id < problem_n; p_id++)
      if (scores[p_id] != -1)
        sum += scores[p_id];
    return sum;
  }

  int perfect_solve() const {
    int count = 0;
    for (int p_id = 0; p_id < problem_n; p_id++)
      if (scores[p_id] == full_score[p_id])
        count++;
    return count;
  }

  void print_score() const {
    printf("%05d %d", id, get_total_score());
    for (int p_id = 0; p_id < problem_n; p_id++)
      if (scores[p_id] == -1)
        printf(" -");
      else
        printf(" %d", scores[p_id]);
  }

  bool operator<(const User& other) const {
    int this_total, other_total;
    this_total = get_total_score();
    other_total = other.get_total_score();
    if (this_total > other_total)    // the higher the score is, the smaller the rank is
      return true;
    if (this_total < other_total)
      return false;
    // equal
    int this_perfect, other_perfect;
    this_perfect = perfect_solve();
    other_perfect = other.perfect_solve();
    if (this_perfect > other_perfect)
      return true;
    if (this_perfect < other_perfect)
      return false;
    // equal
    return id < other.id;
  }
};

int main() {
  int id, p_id, score;
  int rank, samerank, rankscore;
  vector<User> users;

  cin >> people_n >> problem_n >> submit_n;
  for (int i = 0; i < problem_n; i++)
    cin >> full_score[i];

  for (int id = 0; id < people_n; id++)
    users.push_back(User(id + 1));

  for (int i = 0; i < submit_n; i++) {
    cin >> id >> p_id >> score;
    users[id - 1].update(p_id - 1, score);
  }

  sort(users.begin(), users.end());
  rank = 1;
  samerank = 1;
  rankscore = users[0].get_total_score();
  if (users[0].show_in_list){
    printf("1 ");
    users[0].print_score();
  }
  else
    return 0;

  for (int i = 1; i < people_n; i++) {
    if (!users[i].show_in_list)
      return 0;
    if (users[i].get_total_score() == rankscore)
      samerank++;
    else {
      rank += samerank;
      samerank = 1;
      rankscore = users[i].get_total_score();
    }
    printf("\n%d ", rank);
    users[i].print_score();
  }
  return 0;
}
