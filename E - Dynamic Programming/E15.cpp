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
 
        vector <vector <bool>> A(n, vector <bool>(n));
        for (auto& v : A) {
            string s;
            cin >> s;
            for (int i = 0; i < n; i++)
                v[i] = s[i] == '1';
        }
 
        vector <vector<bool>> dp(n + 1, vector <bool>(n));
        //dp[d][i] czy na przedziale od i o długoci d da się tak zorganizować walki, żeby muszkieter i, i + d walczyli razem (chyba) ---- jubert
        dp[1] = vector <bool>(n, 1);
 
        for (int d = 2; d <= n; d++) {
            for (int i = 0; i < n; i++) {
                for (int e = 1; e < d; e++) {
                    if (dp[e][i] && dp[d - e][(i + e) % n] && (A[i][(i + e) % n] || A[(i + d) % n][(i + e) % n])) {
                        dp[d][i] = 1;
                        break;
                    }
                }
            }
        }
        cout << count(dp[n].begin(), dp[n].end(), 1) << "\n";
        for (int i = 0; i < n; i++)
            if (dp[n][i])
                cout << i + 1 << "\n";
 
    }
}
