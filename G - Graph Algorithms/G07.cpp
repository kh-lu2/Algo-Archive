//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <functional>
#include <climits>
 
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
        vector<vector<pair<int, int>>>G(n);
        while (m--) {
            int a, b, w;
            cin >> a >> b >> w;
            a--; b--;
            G[a].push_back({ b, w });
        }
        int s, t;
        cin >> s >> t;
        s--; t--;
 
        function<pair<long long, bool>(int, int)> bellmann_ford = [&](int s, int k)->pair<long long, bool> {
            vector <long long> dist(n, LLONG_MAX);
            bool relax = 1;
            dist[s] = 0;
            bool cykl = 0;
            for (int t = 0; t < n && relax; t++) {
                relax = 0;
                for (int u = 0; u < n; u++) {
                    if (dist[u] == LLONG_MAX) continue;
                    for (auto [v, w] : G[u]) {
                        if (dist[v] > dist[u] + w) {
                            dist[v] = dist[u] + w;
                            relax = 1;
                        }
                    }
                }
            }
            if (relax) cykl = 1;
            return {dist[k], cykl};    //relax
        };
 
        auto [d, c] = bellmann_ford(s, t);
        if (c)
            cout << "Luka w systemie bankowym!\n";
        else if (d == LLONG_MAX)
            cout << "Bank niedostepny!\n";
        else cout << "Minimalny koszt: " << d << "\n";
    }
}
