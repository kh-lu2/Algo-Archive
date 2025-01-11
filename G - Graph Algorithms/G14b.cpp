//Code by Katarzyna Ludwa

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef tuple<int, int, int> NodeID;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int z;
    cin >> z;
 
    while (z--) {
        int h, w;
        cin >> h >> w;
 
        vector<string> M(h);
        for (auto& s : M) cin >> s;
        int x0 = 0, y0 = 0, xk = 0, yk = 0;
 
        for (int i = 0; i < h; i++) {
            if (count(M[i].begin(), M[i].end(), '@')) {
                y0 = i;
                x0 = M[i].find('@');
            }
            if (count(M[i].begin(), M[i].end(), '>')) {
                yk = i;
                xk = M[i].find('>');
            }
        }
 
        vector<vector<array<int, 2>>> D(h, vector<array<int, 2>>(w, { -1, -1 }));
        queue<NodeID> Q;
 
        array<char, 2> drzwi = { '+', 'o' };
 
        auto step = [&](NodeID xyz, int d) {
            auto [x, y, z] = xyz;
            if (x < 0 || x >= w || y < 0 || y >= h ||
                M[y][x] == '#' ||
                D[y][x][z] != -1 ||
                M[y][x] == drzwi[!z])
                return;
 
 
            D[y][x][z] = d;
            Q.push({ x, y, z });
            if (M[y][x] == '%') {
                D[y][x][!z] = d;
                Q.push({ x, y, !z });
            }
        };
 
        D[y0][x0][0] = 0;
        Q.push({ x0, y0, 0 });
        while (!Q.empty()) {
            auto [x, y, z] = Q.front(); Q.pop();
            auto d = D[y][x][z];
            step({ x + 1, y, z }, d + 1);
            step({ x - 1, y, z }, d + 1);
            step({ x, y + 1, z }, d + 1);
            step({ x, y - 1, z }, d + 1);
        }
 
        if (D[yk][xk][0] == -1)
            cout << "NIE\n";
        else cout << D[yk][xk][0] << "\n";
    }
}
