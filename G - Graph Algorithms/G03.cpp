//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int z;
    cin >> z;
    while (z--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>>G(n+m);
        for (int i = 0; i < m; i++) {
            int k; cin >> k;
            for (int j = 0; j < k; j++) {
                int x;
                cin >> x;
                x--;
                G[x].push_back(n + i);
                G[n + i].push_back(x);
            }
        }
 
        vector<int>dist(n + m, -1);
        auto bfs = [&](int v) {
            dist[v] = 0;
            queue<int> Q;
            Q.push(v);
 
            while (!Q.empty()) {
                int v = Q.front(); Q.pop();
                for (auto& u : G[v]) {
                    if (dist[u] == -1) {
                        dist[u] = dist[v] + 1;
                        Q.push(u);
                    }
                }
            }
        };
 
        bfs(0);
 
        for (int i = 0; i < n; i++) {
            if (dist[i] > 0)
                dist[i] /= 2;
            cout << dist[i] << " ";
        }
        cout << "\n";
 
    }
}
