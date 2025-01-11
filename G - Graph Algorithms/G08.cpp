//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;
        vector<string> names(n);
        unordered_map <string, int> M;
        vector<vector<pair<int, int>>>G(n);
        vector<vector<int>>dist(n, vector<int>(n, 1e9));
 
        //input
        for (int i = 0; i < n; i++) {
            cin >> names[i];
            M[names[i]] = i;
            dist[i][i] = 0;
        }
        int m;
        cin >> m;
 
        while (m--) {
            string A, B;
            int a, b;
            int w;
            cin >> A >> B >> w;
            a = M[A];
            b = M[B];
            G[a].push_back({ b, w });
            G[b].push_back({ a, w });
            dist[a][b] = w;
            dist[b][a] = w;
        }
 
        //algo
        auto floyd_warshall = [&]() {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    for (int k = 0; k < n; k++)
                        if (dist[j][k] > dist[j][i] + dist[i][k])
                            dist[j][k] = dist[j][i] + dist[i][k];
 
        };
 
        floyd_warshall();
 
        //output
        auto castint = [&](int x) {
            string xstr = to_string(x);
            return string(12 - xstr.size(), ' ') + xstr;
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
