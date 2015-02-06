#include <iostream>
#define P(x) cout << #x " = " << x << endl
#define For(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;

inline int max(int a, int b) {
  return (a > b) ? a : b;
}

struct node {
  int key;
  char height;
  node* left;
  node* right;
  node(int k) { key = k; left = right = NULL; height = 0; }
};

inline char height(node* T) {
  return T ? T->height: -1;
}

inline int bfactor(node *T) {
  return height(T->left) - height(T->right);
}

node* rotateright(node* T) {
  node* child;
  child = T->right;

  T->right = child->left;
  child->left = T;

  T->height = max(height(T->left), height(T->right)) + 1;
  child->height = max(T->height, height(child->right)) + 1;

  return child;
}

node* rotateleft(node* T) {
  node* child;
  child = T->left;

  T->left = child->right;
  child->right = T;

  T->height = max(height(T->left), height(T->right)) + 1;
  child->height = max(T->height, height(child->left)) + 1;

  return child;
}

node* insert(node* T, int k) {
  int bf;
  if (!T) return new node(k);
  if (k < T->key)
    T->left = insert(T->left, k);
  else
    T->right = insert(T->right, k);

  bf = bfactor(T);
  if (bf == 2) {
    if (bfactor(T->left) < 0)
      T->left = rotateright(T->left);
    return rotateleft(T);
  }
  if (bf == -2) {
    if (bfactor(T->right) > 0)
      T->right = rotateleft(T->right);
    return rotateright(T);
  }
  T->height = max(height(T->left), height(T->right)) + 1;
  return T;
}

void dispose(node* T) {
  if (!T)
    return;
  dispose(T->left);
  dispose(T->right);
  delete T;
}

void print(node* T, int depth = 0) {
  if (!T)
    return;
  for (int i = 0; i < depth; i++)
    cout << " ";
  cout << T->key << endl;
  print(T->left, depth + 1);
  print(T->right, depth + 1);
}

int main() {
  node* T = NULL;
  int N, k;
  cin >> N;
  For(i, 0, N) {
    cin >> k;
    T = insert(T, k);
  }
  cout << T->key;
  return 0;
}
