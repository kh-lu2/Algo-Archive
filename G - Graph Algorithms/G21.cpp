//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
 
using namespace std;
#define int long long
typedef long long LL;
 
int32_t main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
 
    int z; cin >> z;
    while (z--) {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        s--; t--;
 
        vector<vector<int>> G(n);
        vector<vector<int>> F(n, vector<int>(n)), C(n, vector<int>(n));
        while (m--) {
            int a, b, c;
            cin >> a >> b >> c;
            a--; b--;
            G[a].push_back(b);
            G[b].push_back(a);
            C[a][b] += c;
        }
        LL fmax = 0;
        vector<int>P(n, -1);
        auto bfs = [&](int start) {
            queue<int> Q;
            Q.push(start);
            while (!Q.empty()) {
                int u = Q.front(); Q.pop();
                for (auto v : G[u]) {
                    int cp = C[u][v] - F[u][v];
                    if (cp && P[v] == -1) {
                        P[v] = u;
                        Q.push(v);
                    }
                }
            }
        };
        while (1) {
            P = vector<int>(n, -1);
            bfs(s);
            if (P[t] == -1)
                break;
            int M = INT_MAX;
            int v = t;
            while (v != s) {
                int u = P[v];
                M = min(M, C[u][v] - F[u][v]);
                v = u;
            }
            v = t;
            while (v != s) {
                int u = P[v];
                F[u][v] += M;
                F[v][u] -= M;
                v = u;
            }
            fmax += M;
        }
 
        cout << fmax << "\n";
    }
}
