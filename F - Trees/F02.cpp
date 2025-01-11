//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
 
using namespace std;
 
#define __lg log2
 
int main()
{
    cin.tie();
    ios::sync_with_stdio(0);
 
    int z;
    cin >> z;
 
    while (z--) {
        int n; cin >> n;
        vector<vector<int>> G(n);
 
        for (int i = 1; i < n; i++) {
            int x; cin >> x;
            G[x].push_back(i);
        }
 
        vector<pair<int, int>>E;
        vector<int>S(n, -1);
        vector<int>D(n, -1);
        D[0] = 0;
 
 
        function<void(int)> dfs = [&](int v) {
            if (S[v] == -1) S[v] = E.size();
            E.push_back({ D[v], v });
            for (auto& u : G[v]) {
                if (D[u] == -1) {
                    D[u] = D[v] + 1;
                    dfs(u);
                    E.push_back({ D[v], v });
                }
            }
        };
        dfs(0);
        int s = E.size();
        int K = __lg(s);
        vector<vector<pair<int, int>>>rmq(K + 1, vector<pair<int, int>>(s));
 
        for (int i = 0; i < s; i++)
            rmq[0][i] = E[i];
 
        for (int k = 1; k <= K; k++)
            for (int i = 0; i + (1 << k) < s; i++)
                rmq[k][i] = min(rmq[k - 1][i], rmq[k - 1][i + (1 << (k-1))]);
 
 
        int m; cin >> m;
        while (m--) {
            int a, b;
            cin >> a >> b;
 
            int p = min(S[a], S[b]), q = max(S[a], S[b]);
            int L = __lg(q - p + 1);
 
            cout << (min(rmq[L][p], rmq[L][q - (1 << L) + 1])).second << "\n";
        }
    }
}
