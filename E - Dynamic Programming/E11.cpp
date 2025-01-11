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
        vector <vector <int>> dp(n, vector <int>(n));
        int s = 0;
        for (auto& x : dp[0]) {
            cin >> x;
            s += x;
        }
 
        for (int d = 1; d < n; d++)
            for (int i = 0; i < n; i++)
                dp[d][i] = max(dp[0][i] - dp[d - 1][(i + 1) % n], dp[0][(i + d) % n] - dp[d - 1][i]);
 
        int d = *max_element(dp[n - 1].begin(), dp[n - 1].end()),
            w = (s+d)/2;
        cout << w << " " << w - d << "\n";
    }
}
