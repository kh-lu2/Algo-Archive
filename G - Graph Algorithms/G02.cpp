//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <functional>
using namespace std;
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int z;
    cin >> z;
 
    while (z--) {
        int n, m;
        cin >> n >> m;
        vector <vector <int>> G(n);
 
        while (m--) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
 
        vector <int> res(n);        //0-not vis, 1-A, 2-B
 
        function<bool(int, bool)> dfs = [&](int v, bool curr) {
            if (res[v]) return res[v] != curr + 1;
 
            res[v] = curr+1;
            for (auto& u : G[v]) {
                 if(dfs(u, !curr))
                     return true;
            }
            return false;
        };
 
        bool errored = 0, curr=0;
        for (int v = 0; v < n; v++) {
            if (!res[v])
                if (dfs(v, curr))
                    errored = 1;
        }
 
        if (errored)
            cout << "NIE\n";
        else {
            cout << "TAK\n";
            for (auto&& x : res)
                if (x-1) cout << "A ";
                else cout << "B ";
            cout << "\n";
        }
    }
}
