//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int z;
    cin >> z;
    while (z--) {
        int n, m;
        cin >> n >> m;
        vector <vector<int>> G(n);
        while (m--) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        int me;
        cin >> me;
        me--;
 
        vector <int> dist(n, INT_MAX);
 
 
        auto bfs = [&](int v) {
            if (dist[v]==-1)
                return;
            queue <int> Q;
            dist[v] = 0;
            Q.push(v);
 
            while (!Q.empty()) {
                auto v = Q.front();
                Q.pop();
                for (auto u : G[v]) {
                    if (dist[u] == INT_MAX) {
                        dist[u] = dist[v] + 1;
                        Q.push(u);
                    }
                }
            }
        };
 
        bfs(me);
 
        cout << "Znajomi numeru " << me + 1 << ":\n";
        for (int i = 0; i < n; i++)
            if (dist[i] != INT_MAX && i!=me)
                cout << i + 1 << ": " << dist[i] << "\n";
 
        int ccCnt = 1;
        for (int i = 0; i < n; i++) {
            if (dist[i]==INT_MAX) {
                bfs(i);
                ccCnt++;
            }
        }
        cout << "Grup znajomych jest " << ccCnt << ".\n";
    }
}
