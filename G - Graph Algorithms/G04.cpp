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
        vector<vector<int>>G(n);
        while (m--) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            G[a].push_back(b);
        }
 
        vector<int>vis(n);
        vector<int>res;
        function<bool(int)> dfs = [&](int v) {
            if (vis[v]) return vis[v] == 1;
            vis[v] = 1;
 
            for (auto& u : G[v])
                if (dfs(u)) return true;
            vis[v] = 2;
 
            res.push_back(v+1);
            return false;
        };
 
        bool cykl = 0;
        for (int v = 0; v < n; v++)
            if (dfs(v))
                cykl = 1;
 
        if (cykl)
            cout << "CYKL\n";
        else {
            cout << "OK\n";
            reverse(res.begin(), res.end());
            for (auto& x : res) cout << x << " ";
            cout << "\n";
        }
    }
}
