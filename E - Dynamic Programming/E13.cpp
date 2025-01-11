//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int z; cin >> z;
    while (z--) {
        int a, n; cin >> a >> n;
        vector <vector <long long>> dp(n + 2, vector <long long>(n+2, LLONG_MAX));
        for (auto& x : dp[1]) x = 0;
 
        vector <int>d;
        d.push_back(0);
        d.push_back(a);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            d.push_back(x);
        }
        sort(d.begin(), d.end());
 
        for (int s = 2; s <= n + 1; s++) {
            for (int i = 0; i <= n + 1 - s; i++) {
                for (int e = 1; e < s; e++) {
                    dp[s][i] = min(dp[s][i], dp[e][i] + dp[s - e][i + e] + max(d[i + e] - d[i], d[i + s] - d[i + e]));
                }
            }
        }
        cout << dp[n + 1][0] << "\n";
    }
}
