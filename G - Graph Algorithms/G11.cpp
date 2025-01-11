//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <stack>
#include <vector>
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
        vector <vector<pair<int, int>>> G(n+1);   //v, idE
 
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            G[a].push_back({ b,i });
            G[b].push_back({ a,i });
        }
 
        vector <int> odd;
        for (int i=1; i<=n; i++)
            if (G[i].size() % 2 == 1)
                odd.push_back(i);
 
        if (odd.size()==0) {
            G[0].push_back({ 1, m });
            G[1].push_back({ 0, ++m });
        }
        else {
            for (auto v : odd) {
                G[0].push_back({ v, m });
                G[v].push_back({ 0, m++ });
            }
        }
 
        vector <int> res;
        vector <bool> vis(m);
        stack <int> S;
        S.push(0);
        while (!S.empty()) {
            int v = S.top();
            if (G[v].size() == 0) {
                S.pop();
                res.push_back(v);
                continue;
            }
            auto [w, i] = G[v].back();
            G[v].pop_back();
            if (!vis[i]) {
                vis[i] = 1;
                S.push(w);
            }
        }
 
        res[0] = -1;
        cout << count(res.begin(), res.end(), 0) << "\n";
        vector <int> temp;
        for (size_t i = 1; i < res.size(); i++) {
            if (res[i] == 0) {
                cout << temp.size() << " ";
                for (auto& x : temp) cout << x << " ";
                cout << "\n";
                temp.clear();
            }
            else
                temp.push_back(res[i]);
        }
    }
}
