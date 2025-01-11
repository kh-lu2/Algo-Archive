//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
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
        vector <tuple<int, int, int>> v(m);
        vector <bool> taken(n);
        long long res = 0;
        for (auto& [w, a, b] : v) {
            cin >> a >> b >> w;
            a--; b--;
        }
 
        vector <int> P(n), R(n);
        iota(P.begin(), P.end(), 0);
 
        function<int(int)> Find = [&](int v) {
            if (P[v] != v) P[v] = Find(P[v]);
            return P[v];
        };
 
        auto Union = [&](int idA, int idB) {
            if (R[idA] < R[idB])
                P[idA] = idB;
            else {
                P[idB] = idA;
                R[idA] += (R[idA] == R[idB]);
            }
        };
 
        sort(v.begin(), v.end());
        for (auto& [w, a, b] : v) {
            int idA = Find(a), idB = Find(b);
            if (idA != idB) {
                res += w;
                Union(idA, idB);
            }
        }
 
        cout << res << "\n";
    }
}
