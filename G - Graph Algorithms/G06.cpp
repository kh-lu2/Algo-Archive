//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
 
using namespace std;
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int z;
    cin >> z;
    while(z--) {
        int n, m;
        cin >> n >> m;
 
        vector<vector<pair<int, int>>>G(n);
        while (m--) {
            int a, b, w;
            cin >> a >> b >> w;
            a--; b--;
            G[a].push_back({ b, w });
        }
 
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
 
            return dist.back();
        };
 
        long long res = dijkstra(0);
        if (res == LLONG_MAX)
            cout << "BRAK\n";
        else
            cout << res << "\n";
    }
}
