//Code by Katarzyna Ludwa

#include <iostream>
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
        int n;
        cin >> n;
        vector <int> f(n);
        for (auto& x : f) cin >> x;
        vector <int> dp(n);
 
        dp[0] = f[0];
        if (n > 1) {
            dp[1] = f[0] + f[1];
        } if (n > 2) {
            dp[2] = max(f[0] + f[1], max(f[0] + f[2], f[1] + f[2]));
 
            for (int i = 3; i < n; i++)
                dp[i] = max(dp[i - 1], max(dp[i - 2] + f[i], dp[i - 3] + f[i] + f[i - 1]));
        }
        cout << dp.back() << "\n";
    }
}
