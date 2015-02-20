#include <iostream>
using namespace std;
#define P(x) cout << #x " is " << x << endl;

int get_level(int *root, int i) {
  int level = 0;
  while (i != 1) {   // 01 is root node
    i = root[i];
    level++;
  }
  return level;
}

int main() {
  int root[100];
  static int levels[100]; // set as 0
  static int is_nonleaf[100];  // is nonleaf if 1
  int node_n, nonleaf_n;
  int max_level = 0;
  cin >> node_n >> nonleaf_n;
  for (int i = 0; i < nonleaf_n; i++) {
    int parent, child_n;
    cin >> parent >> child_n;
    is_nonleaf[parent] = 1;
    for (int j = 0; j < child_n; j++) {
      int child;
      cin >> child;
      root[child] = parent;
    }
  }
  for (int i = 1; i <= node_n; i++) {
    int level = get_level(root, i);
    if (level > max_level)
      max_level = level;
    if (!is_nonleaf[i]) {
      levels[level]++;
    }
  }
  for (int i = 0; i <= max_level; i++) {
    if (i == 0)
      cout << levels[i];
    else
      cout << " " << levels[i];
  }
  return 0;
}
