//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
 
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
 
        vector <vector <int>> G(n), revG(n);
        while(m--) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            G[a].push_back(b);
            revG[b].push_back(a);
        }
        int t = 0;
        vector <pair<int, int>> time(n, { -1, -1 });
        function <void(int)> dfs = [&](int v) {
            if (time[v].second != -1) return;
            time[v].second = v;
            t++;
            for (auto u : G[v])
                if (time[u].second == -1)
                    dfs(u);
            t++;
            time[v].first = t;
        };
 
        for (int v = 0; v < n; v++)
            dfs(v);
 
        sort(time.rbegin(), time.rend());
 
        vector <int> scc(n, -1);
        t = 0;
 
        function <void(int)> dfsscc = [&](int v) {
            if (scc[v] != -1) return;
            scc[v] = t;
            for (auto u : revG[v])
                if (scc[u] == -1)
                    dfsscc(u);
        };
 
        for (auto [tim, v] : time) {
            dfsscc(v);
            t++;
        }
 
        int k;
        cin >> k;
        while (k--) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            if (scc[a] == scc[b]) cout << "TAK\n";
            else cout << "NIE\n";
        }
    }
}
