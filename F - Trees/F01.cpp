//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
 
using namespace std;
 
int main() {
      cin.tie(0);
      ios::sync_with_stdio(0);
 
      int z;
      cin >> z;
      while (z--) {
              int n;
              cin >> n;
              vector<vector<pair<int, int>>> G(n);
 
              for (int i = 0; i < n - 1; i++) {
                      int a, b, d;
                      cin >> a >> b >> d;
                      G[--a].push_back({ --b, d });
                      G[b].push_back({ a, d });
              }
 
              vector<int> dist(n, -1);
 
              function<void(int, int)> dfs = [&](int v, int p) {
                      for (auto & [u, d ] : G[v]) {
                              if (dist[u] == -1) {
                                      dist[u] = dist[v] + d;
                                      dfs(u, v);
                              }
                      }
                      return;
              };
 
              dist[0] = 0;
              dfs(0, -1);
              int t = distance(dist.begin(), max_element(dist.begin(), dist.end()));
              dist = vector<int>(n, -1);
              dist[t] = 0;
              dfs(t, -1);
              t = distance(dist.begin(), max_element(dist.begin(), dist.end()));
              vector<int>dist2 = dist;
              dist = vector<int>(n, -1);
              dist[t] = 0;
              dfs(t, -1);
 
              for (int i = 0; i < n; i++)
                      cout << max(dist[i], dist2[i]) << " ";
 
              cout << "\n";
      }
}
