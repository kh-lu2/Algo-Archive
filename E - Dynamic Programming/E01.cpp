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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
 
        if (s.back() == '0')
            cout << 0 << "\n";
        else {
            vector <int> dp(n);
            dp[0] = 1;
            for (int i = 0; i < n - 1; i++) {
                for (int j = i+1; j <= i + 6 && j < n; j++) {
                    if (s[j] == '1') {
                        dp[j] += dp[i];
                        dp[j] %= k;
                    }
                }
            }
            cout << dp.back() << "\n";
        }
    }
}
