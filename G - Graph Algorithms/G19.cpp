//Code by Katarzyna Ludwa

#include<iostream>
#include<vector>
#include<stack>
#include<functional>
#include<string>
 
using namespace std;
 
int main() {
      cin.tie(0);
      ios::sync_with_stdio(0);
 
      int z; cin >> z;
      while (z--) {
              int n, m; cin >> n >> m;
 
              vector<vector<int>>G(2 * n), rG(2 * n);
              while (m--) {
                      char as, bs;
                      int a, b;
                      cin >> as >> a >> bs >> b;
                      a--; b--;
                      a *= 2; b *= 2;
                      a += (as == '+' ? 1 : 0);
                      b += (bs == '+' ? 1 : 0);
 
                      G[a].push_back(b ^ 1);
                      G[b].push_back(a ^ 1);
 
                      rG[a ^ 1].push_back(b);
                      rG[b ^ 1].push_back(a);
              }
 
        vector <bool> vis(2 * n);
        vector <int> scc(2 * n, -1);
        stack<int> s;
 
        function <void(int)> dfs = [&](int v) {
            if (vis[v])
                return;
            vis[v] = 1;
            for (auto u : G[v])
                dfs(u);
            s.push(v);
        };
 
        for (int i = 0; i < 2 * n; i++)
            dfs(i);
 
        function <void(int, int)> rdfs = [&](int v, int c) {
            if (scc[v] != -1)
                return;
            scc[v] = c;
            for (auto u : rG[v])
                rdfs(u, c);
        };
 
 
        int c = 0;
        while (!s.empty()) {
            int v = 0;
            v = s.top();
            s.pop();
            if (scc[v] == -1)
                rdfs(v, c++);
        }
 
        string odp = "TAK\n"; bool d = 0;
        for (int i = 0; i < 2 * n; i += 2) {
            if (scc[i] == scc[i + 1])
                d = 1;
 
            odp += to_string(scc[i] > scc[i + 1]) + " ";
        }
        cout << (d ? "NIE" : odp) << "\n";
      }
}
