//Code by Katarzyna Ludwa

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
mt19937_64 rng(1313);
 
struct Node {
  Node *left, *right;
  size_t h = rng();
  int key;
  int size;
  Node(int key, Node *left = 0, Node *right = 0)
      : left(left), right(right), key(key) {
    updateNode(this);
  }
 
  friend void updateNode(Node *v);
  friend int getSize(Node *v);
};
 
Node *&find(Node *&v, int k) {
  Node **pp = &v;
  while (*pp && (*pp)->key != k)
    pp = &((k < (*pp)->key) ? (*pp)->left : (*pp)->right);
  return *pp;
}
 
int getSize(Node *v) {
  if (!v)
    return 0;
  return v->size;
}
 
void updateNode(Node *v) {
  if (!v)
    return;
  v->size = getSize(v->left) + getSize(v->right) + 1;
}
 
pair<Node *, Node *> splitByKey(Node *v, int k) {
  if (!v)
    return {nullptr, nullptr};
  if (v->key < k) {
    auto [l, r] = splitByKey(v->right, k);
    v->right = l;
    updateNode(v);
    return {v, r};
  } else {
    auto [l, r] = splitByKey(v->left, k);
    v->left = r;
    updateNode(v);
    return {l, v};
  }
}
 
Node *join(Node *l, Node *r) {
  if (!l)
    return r;
  if (!r)
    return l;
  if (l->h > r->h) {
    l->right = join(l->right, r);
    updateNode(l);
    return l;
  } else {
    r->left = join(l, r->left);
    updateNode(r);
    return r;
  }
}
 
Node *insert(Node *v, Node *e, LL &res) {
  if (!v)
    return e;
  auto [l, r] = splitByKey(v, e->key);
  res += getSize(l);
  v = join(join(l, e), r);
  updateNode(v);
  return v;
}
 
void eraseAll(Node *v) {
  if (!v)
    return;
  eraseAll(v->left);
  eraseAll(v->right);
  delete v;
}
 
void print(Node *v) {
  if (!v)
    return;
  print(v->right);
  cout << v->key << " ";
  print(v->left);
}
 
int main() {
  ios::sync_with_stdio();
  cin.tie();
 
  int z;
  cin >> z;
  while (z--) {
    int n;
    cin >> n;
    Node *T = nullptr;
    LL res = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      T = insert(T, new Node(x), res);
    }
 
    print(T);
    cout << "\n" << res << "\n";
    eraseAll(T);
  }
}
