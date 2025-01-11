//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <array>
 
using namespace std;
#define int long long
typedef long long LL;
 
int inf = 1e9;
 
struct Edge {
    int dest;
    int c;
    int f;
    int id;
};
 
int32_t main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
 
    int z; cin >> z;
    while (z--) {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        s--; t--;
        s += n;
 
        vector<vector<Edge>> G(2 * n);
        for (int i = 0; i < n; i++) {
            int t1 = G[i + n].size(), t2 = G[i].size();
            G[i].push_back({ i + n, 1, 0, t1 });
            G[i + n].push_back({ i, 1, 0, t2 });
        }
 
 
        while (m--) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            //a + n wychodzący, a wchodzący
            int t1 = G[b].size(), t2 = G[a + n].size(), t3 = G[a].size(), t4 = G[b + n].size();
            G[a + n].push_back({ b, inf, 0, t1 });
            G[b].push_back({ a + n, 0, 0, t2 });
            G[b + n].push_back({ a, inf, 0, t3 });
            G[a].push_back({ b + n, 0, 0, t4 });
        }
 
        LL fmax = 0;
        vector<array<int, 2>> P(2 * n, { -1, -1 }); //u, i
        auto bfs = [&](int start) {
            queue<int> Q;
            Q.push(start);
            while (!Q.empty()) {
                int u = Q.front(); Q.pop();
                for (auto [v, c, f, id] : G[u]) {
                    int cp = c - f;
                    if (cp && P[v][0] == -1) { // czm 1 akurat a czm 0 akurat a czm nie uwu uwu
                        P[v] = { u, id };
                        Q.push(v);
                    }
                }
            }
        };
 
        while (1) {
            P = vector <array<int, 2>>(2 * n, { -1, -1 });
            bfs(s);
            if (P[t][0] == -1)
                break;
            int M = INT_MAX;
            int v = t;
            while (v != s) {
               /* int u = P[v];
                M = min(M, C[u][v] - F[u][v]);
                v = u;*/
 
                auto [u, j] = P[v];
                int i = G[v][j].id;
                M = min(M, G[u][i].c - G[u][i].f);
                v = u;
            }
            v = t;
            while (v != s) {
                /*int u = P[v];
                F[u][v] += M;
                F[v][u] -= M;
                v = u;*/
 
                auto [u, j] = P[v];
                int i = G[v][j].id;
                G[u][i].f += M;
                G[v][j].f -= M;
                v = u;
            }
            fmax += M;
        }
 
        cout << fmax << "\n";
        s -= n;
        for (int i = 0; i < n; i++) {
            if (i == s || i == t) continue;
            if (P[i][0] != -1 && P[i + n][0] == -1)
                cout << i + 1 << " ";
        }
        cout << "\n";
    }
}
