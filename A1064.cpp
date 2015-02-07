#include <iostream>
#include <cassert>
#define left_child(n) (((n + 1) << 1) - 1)
#define right_child(n) ((((n + 1) << 1) | 1) - 1)
#define P(x) cout << #x " is " << x << endl;

using namespace std;
int *seq, *tree;
int sizes[] = {0, 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047};
int N;

void make_tree(int left, int right, int tree_pos = 0, int pos_before = 0) {
  // included
  int size = right - left + 1;
  if (size <= 0)
    return;
  if (size == 1) {
    tree[tree_pos] = seq[left];
    return;
  }
  int index;
  for (index = 0; size > sizes[index]; index++);
  int smaller_size = sizes[--index];
  int even_smaller = sizes[--index];
  int pos;
  if (size - smaller_size - 1 < even_smaller) {
    pos = size - even_smaller - 1;
  }
  else {
    pos = smaller_size;
  }
  tree[tree_pos] = seq[pos_before + pos];
  if (left > pos_before + pos - 1) {
    P(pos_before);
    P(pos);
  }
  make_tree(left, pos_before + pos - 1, left_child(tree_pos), pos_before);
  make_tree(pos_before + pos + 1, right, right_child(tree_pos), pos_before + pos + 1);
}

int main() {
  cin >> N;
  seq = new int[N];
  tree = new int[N];
  for (int i = 0; i < N; i++)
    cin >> seq[i];
  sort(seq, seq + N);
  make_tree(0, N - 1);
  cout << tree[0];
  for (int i = 1; i < N; i++)
    cout << " " << tree[i];
  delete[] seq;
  delete[] tree;
}
