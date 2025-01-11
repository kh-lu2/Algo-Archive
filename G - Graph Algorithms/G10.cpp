//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <queue>
#include <string>
#include <climits>
 
using namespace std;
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int z;
    cin >> z;
    while (z--) {
        //input
        int n;
        cin >> n;
        vector <vector <pair<int, long long>>> G(n);
        vector <string> names(n);
        unordered_map <string, int> M;
        for (int i = 0; i < n; i++) {
            cin >> names[i];
            M[names[i]] = i;
        }
 
        int m;
        cin >> m;
        while (m--) {
            string A, B;
            int a, b;
            long long w;
            cin >> A >> B >> w;
            a = M[A];
            b = M[B];
            G[a].push_back({ b, w });
        }
 
        //algo
        vector <vector <long long>> dist(n);
        auto johnson = [&]() {
            vector<pair<int, long long>> q(n);
            for (int i = 0; i < n; i++)
                q[i].first = i;
            G.push_back(q);
 
            vector <long long> h(n+1);
            auto bellmann_ford = [&](int s) {
                vector <long long> dist(n+1, LLONG_MAX);
                bool relax = 1;
                dist[s] = 0;
                for (int t = 0; t < n+1 && relax; t++) {
                    relax = 0;
                    for (int u = 0; u < n+1; u++) {
                        if (dist[u] == LLONG_MAX) continue;
                        for (auto [v, w] : G[u]) {
                            if (dist[v] > dist[u]+w) {
                                dist[v] = dist[u] + w;
                                relax = 1;
                            }
                        }
                    }
                }
                return dist;    //relax
            };
            h = bellmann_ford(n);
            for (int u = 0; u < n; u++)
                for (auto& [v, w] : G[u])
                    w += h[u] - h[v];
            G.pop_back();
 
            auto dijkstra = [&](int s) {
                vector <long long> dist(n, LLONG_MAX);
                priority_queue<pair<long long, int>, vector <pair<long long, int>>, greater<pair<long long, int>>> Q;
 
                Q.push({ dist[s] = 0, s });
                while (!Q.empty()) {
                    auto [du, u] = Q.top();
                    Q.pop();
                    if (du != dist[u]) continue;
                    for (auto [v, w] : G[u])
                        if (dist[v] > (long long)(du + w))
                            Q.push({ dist[v] = du + w, v });
                }
 
                return dist;
            };
 
            for (int u = 0; u < n; u++) {
                dist[u] = dijkstra(u);
                for (int v = 0; v < n; v++)
                    dist[u][v] += h[v] - h[u];
            }
        };
        johnson();
 
        //output
        auto castint = [&](long long x) {
            string xstr = to_string(x);
            return string( 12 - xstr.size(), ' ') + xstr;
        };
        auto caststr = [&](string x) {
            return string(12 - x.size(), ' ') + x;
        };
 
        cout << string(12, ' ');
 
        for (auto& name : names) cout << caststr(name);
        cout << "\n";
 
        for (int i = 0; i < n; i++) {
            cout << caststr(names[i]);
            for (int j = 0; j < n; j++)
                cout << castint(dist[i][j]);
            cout << "\n";
        }
 
    }
}
