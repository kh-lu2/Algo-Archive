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
        string s1, s2;
        cin >> s1 >> s2;
 
        auto lcs = [&]() {
            vector <vector <int>>dp(2, vector <int>(s1.size() + 1));
            for (int i = 1; i <= s2.size(); i++) {
                for (int j = 1; j <= s1.size(); j++) {
                    if (s1[j - 1] == s2[i - 1])
                        dp[i % 2][j] = dp[(i + 1) % 2][j - 1] + 1;
                    else
                        dp[i % 2][j] = max(dp[i % 2][j - 1], dp[(i + 1) % 2][j]);
                }
            }
            return dp[s2.size() % 2].back();
        };
 
        cout << lcs() << "\n";
    }
}
