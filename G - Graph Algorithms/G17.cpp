//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <functional>
#include <algorithm>
 
using namespace std;
typedef long long ll;
 
int main() {
      ios::sync_with_stdio(0);
      cin.tie(0);
 
      int z; cin >> z;
      while (z--) {
              int n; cin >> n;
              vector<vector<int>> G(n);
              for (int i = 0; i < n; i++) {
                      int x; cin >> x;
                      while (x--) {
                              int y; cin >> y;
                              G[--y].push_back(i);
                      }
              }
 
              vector<int> tin(n, -1), low(n), scc(n, -1);
              stack<int> S;
              int cnt = 0, sccC =0;
              vector<pair<int, int>>sccS(1);
 
              function<void(int)> dfs = [&](int v) {
                      tin[v] = low[v] = cnt;
                      S.push(v);
                      cnt++;
 
                      for (auto& u : G[v]) {
                              if (tin[u] == -1) {
                                      dfs(u);
                                      low[v] = min(low[v], low[u]);
                              }
                              else if (tin[v] != INT_MAX)
                                      low[v] = min(low[v], tin[u]);
                      }
 
                      if (low[v] == tin[v]) {
                              int u;
                              do {
                                      u = S.top(); S.pop();
                                      tin[u] = INT_MAX;
                                      scc[u] = sccC;
                                      sccS.back().first++;
                              } while (u != v);
                              sccS.back().second = sccC;
                              sccC++;
                              sccS.resize(sccS.size() + 1);
                      }
              };
              for (int v = 0; v < n; v++)
                      if (tin[v] == -1) dfs(v);
 
              sccS.resize(sccS.size() - 1);
 
              for (int v = 0; v < n; v++)
                      for (auto& u : G[v])
                              if (scc[v] != scc[u])
                                      sccS[scc[u]].first = INT_MAX;
 
              sort(sccS.begin(), sccS.end());
 
              cout << sccS.front().first << "\n";
              for (int v = 0; v < n; v++)
                      if (scc[v] == sccS.front().second) cout << v + 1 << " ";
              cout << "\n";
      }
}
