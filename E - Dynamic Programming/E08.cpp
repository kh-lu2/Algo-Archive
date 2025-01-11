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
        vector <int> A(n), C(n);
        for (int i = 0; i < n; i++) cin >> A[i] >> C[i];
        int M, a;
        cin >> M >> a;
        int k = 0;
        vector <long long> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            while (A[k] < A[i - 1] - M) k++;
            dp[i] = min(dp[i - 1] + C[i-1], a + dp[k]);
        }
        cout << dp[n] << "\n";
    }
}
