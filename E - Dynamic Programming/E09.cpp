//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <bit>
 
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
 
        vector<vector<bool>> v(n, vector<bool>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char c;
                cin >> c;
                if (c == '.')
                    v[i][j] = 1;
            }
        }
        vector <long long> dp(1 << n);
        dp[0] = 1;
 
        for (int k = 1; k < (1 << n); k++)
            for (int c = 0; c < n; c++)
                if ((k >> c) & 1)
                    dp[k] += (long long)(v[__builtin_popcount(k) - 1][c]) * dp[k ^ (1 << c)];
        cout << dp.back() << "\n";
    }
}
