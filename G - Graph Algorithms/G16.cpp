//Code by Katarzyna Ludwa

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int z; cin >> z;
  while (z--) {
    LL n, m;
    cin >> n >> m;
    vector<vector<PII>> G(n);
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b; a--; b--;
      G[a].push_back({b, i});
      G[b].push_back({a, i});
    }
    vector<int> Tin(n, -1);
    vector<int> Low(n);
    int cnt = 0;
    // int dcccnt = 0;
    // stack<int> S;
    // vector<int> DCC(m);
 
    vector<LL> Res(n, n * (n - 1));
    vector<int> Size(n, 1);
    function<void(int, int)> dfs = [&](int v, int p) {
      LL ile_odpadlo = 0;
      Tin[v] = Low[v] = cnt++;
      for (auto [u, k]: G[v]) {
        if (u == p) continue;
        if (Tin[u] == -1) {
          //S.push(k);
          dfs(u, v);
          Size[v] += Size[u];
          Low[v] = min(Low[v], Low[u]);
 
          if (Low[u] >= Tin[v]) {
            Res[v] -= (Size[u] * (n - Size[u]));
            ile_odpadlo += Size[u];
 
            //int kk;
            //do {
              //kk = S.top(); S.pop();
              //DCC[k] = dcccnt;
            //} while (kk != k);
            //dcccnt++;
          }
        } else if (Tin[v] > Tin[u]) {
          Low[v] = min(Low[v], Tin[u]);
          //S.push(k);
        }
      }
      Res[v] -= (ile_odpadlo + 1) * (n - ile_odpadlo - 1);
    };
 
    dfs(0, -1);
 
    for (auto &x: Res) {
      cout << x - (n - 1) << "\n";
    }
  }
}
