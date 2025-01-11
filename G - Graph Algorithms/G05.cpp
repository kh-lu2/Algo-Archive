//Code by Katarzyna Ludwa

#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int z;
    cin >> z;
 
    while (z--) {
        int n, m;
        cin >> n >> m;
 
        vector<bool> C(n);
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            C[i] = --x;
        }
 
        vector<vector<int>> G(n);
        while (m--) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            G[a].push_back(b);
        }
 
        vector<int> R(n, -1);
 
        function<int(int)>dfs = [&](int v) {
            if (R[v] != -1) return R[v];
 
            int mx = 0;
 
            for (auto &u: G[v])
                mx = max(mx, dfs(u) + (C[u] != C[v]));
 
            return R[v] = mx;
        };
 
        int M =-1;
        bool mC = 0, repeat = 0;
        for (int v =0; v < n; v++) {
            int m = dfs(v);
 
            if (m > M) {//69
                M = m;
                mC = C[v];
                repeat = false;
            }
 
            if(m == M && (C[v] != mC)) repeat = true;
        }
 
        cout << M + repeat << "\n";
    }
}
