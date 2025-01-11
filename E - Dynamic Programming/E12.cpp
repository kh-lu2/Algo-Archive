//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <functional>
#include <algorithm>
 
using namespace std;
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int z; cin >> z;
    while (z--) {
        int n; cin >> n;
        vector <pair<int, int>> p(n);
        for (auto& [x,y] : p) {
            cin >> x >> y;
        }
        auto dist = [&](int i, int j) {
            return ((long long) (pow(p[i].first - p[j].first, 2) + pow(p[i].second - p[j].second, 2)));
        };
 
        vector <vector<pair<long long, int>>> dp(n, vector <pair<long long, int>>(n, {LLONG_MAX, 0}));
        for (auto &[koszt, e] : dp[1]) {
            koszt = 0;
            e = 1;
        }
 
        for (int d = 2; d < n; d++) {
            for (int i = 0; i < n - d; i++) {
                for (int e = 1; e < d; e++) {
                    dp[d][i] = min(dp[d][i], make_pair(dp[e][i].first + dp[d - e][i + e].first + dist(i, i + d), e));
                }
            }
        }
 
        long long ans = dp[n - 1][0].first - dist(0, n - 1);
        cout << ans << " ";
 
        function<void(int, int)> f = [&](int d, int i) {
            if (d == 1) return;
            int e = dp[d][i].second;
            if (d != n-1)
                cout << i << " " << (i + d) % n << " ";
            f(e, i);
            f(d - e, (i + e)%n);
        };
        if (n != 2 && ans > 0)
            f(n - 1, 0);
        cout << "\n";
    }
}
