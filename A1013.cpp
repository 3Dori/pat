#include <iostream>
#include <cstring>

#define P(x) cout << #x " is " << x << endl
#define SIZE 1001
#define For(i, x) for (int i = 0; i < (x); i++)
using namespace std;

int n, m, k;
int edge[SIZE][SIZE];
int visited[SIZE];
int city;

void dfs(int x) {
  for (int i = 1; i <= n; i++) {
    if (edge[i][x] && !visited[i]) {
      visited[i] = 1;
      dfs(i);
    }
  }
}

int repair() {
  int cc = 0;
  memset(visited, 0, sizeof(visited));
  visited[city] = 1;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      visited[i] = 1;
      dfs(i);
      cc++;
    }
  }
  return cc - 1;
}

int main() {
  cin >> n >> m >> k;
  For (i, m) {
    int x, y;
    cin >> x >> y;
    edge[x][y] = edge[y][x] = 1;
  }
  For (i, k) {
    cin >> city;
    cout << repair() << endl;
  }
  return 0;
}
