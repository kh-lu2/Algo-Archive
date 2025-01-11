//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <string>
 
using namespace std;
typedef long long LL;
#define int LL
LL INF = 1e18;
 
struct Edge {
      int v, d, t, a, l;
      Edge(int v, int d, int t, int a, int l) : v(v), d(d), t(t), a(a), l(l) {}
};
 
int32_t main() {
      cin.tie(0);
      ios::sync_with_stdio(0);
      int z; cin >> z;
      while (z--) {
              int n, m; cin >> n >> m;
 
              vector<vector<Edge>> G(n);
 
              while (m--) {
                      int u, v, d, t, a, l;
                      cin >> u >> v >> d >> t >> a >> l;
 
                      G[--u].push_back({ --v, d, t, a, l });
              }
 
              vector<LL> D(n, INF);
              auto dijkstra = [&](int s) {
                      priority_queue <pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> Q;
                      Q.push({ D[s] = 0, s });
                      while (!Q.empty()) {
                              auto [du, u] = Q.top(); Q.pop();
                              if (du != D[u]) continue;
                              for (auto [v, d, t, a, l] : G[u]) {
                                      if (t != 0 && ((du - a + t) % t >= l))
                                              d += t - ((du - a + t) % t);
 
                                      auto& dv = D[v];
                                      if (dv > du + d) Q.push({ dv = du + d, v });
                              }
                      }
              };
              dijkstra(0);
              cout << (D.back() == INF ? "NIE" : to_string(D.back())) << "\n";
      }
}
