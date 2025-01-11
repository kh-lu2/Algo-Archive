//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <functional>
 
using namespace std;
 
int main() {
      cin.tie(0);
      ios::sync_with_stdio(0);
 
      int z; cin >> z;
      while (z--) {
              int n1, n2, m; cin >> n1 >> n2 >> m;
              vector<vector<int>> G(n1);
              vector<int>L(n1, -1), R(n2, -1);
              vector<bool>vis(n1);
 
              while (m--) {
                      int a, b;
                      cin >> a >> b;
                      G[--a].push_back(--b);
              }
 
 
              function<bool(int)> dfs = [&](int v) {
                      if (vis[v]) return 0;
                      vis[v] = 1;
 
                      for (auto w : G[v]) {
                              if (w == L[v]) continue;
                              if (R[w] == -1 || dfs(R[w])) {
                                      L[v] = w, R[w] = v;
                                      return 1;
                              }
                      }
                      return 0;
              };
 
              bool relax = 1;
              while (relax) {
                      relax = 0;
                      vis = vector<bool>(n1);
                      for (int i = 0; i < n1; i++)
                              if (L[i] == -1)
                                      relax = dfs(i) || relax;
              }
 
              cout << n1 - count(L.begin(), L.end(), -1) << "\n";
      }
}
