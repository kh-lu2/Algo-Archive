//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int z;
    cin >> z;
    while (z--) {
        int n, B;
        cin >> n >> B;
        vector <int> s(n), v(n);
        for (int i = 0; i < n; i++)
            cin >> s[i] >> v[i];
        vector<vector<int>>dp(n+1, vector<int>(B + 1));
        for (int i = 1; i <= n; i++) {
            for (int g = 1; g <= B; g++) {
                if (s[i-1] > g) dp[i][g] = dp[i-1][g];
                else dp[i][g] = max(dp[i-1][g], dp[i-1][g - s[i-1]] + v[i-1]);
            }
        }
        cout << dp[n][B] << "\n";
    }
}
