//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
 
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
 
        auto lcs = [&]()->string {
            vector <vector<pair<int, int>>>dp(s2.size() + 1, vector<pair<int, int>>(s1.size() + 1));    //0 - przekatna, 1 z gory, 2 z boku
            for (int i = 1; i <= s2.size(); i++) {
                for (int j = 1; j <= s1.size(); j++) {
                    if (s1[j - 1] == s2[i - 1])
                        dp[i][j].first = dp[i - 1][j - 1].first + 1;
                    else {
                        dp[i][j].first = max(dp[i - 1][j].first, dp[i][j - 1].first);
                        if (dp[i - 1][j].first > dp[i][j - 1].first)
                            dp[i][j].second = 1;
                        else dp[i][j].second = 2;
                    }
                }
            }
            int i = s2.size(), j = s1.size();
            string res;
            while (i && j) {
                if (!dp[i][j].second) {
                    res += s1[j - 1];
                    j--;
                    i--;
                }
                else if (dp[i][j].second == 1)
                    i--;
                else
                    j--;
            }
            reverse(res.begin(), res.end());
            //pair<int, string>p = { dp[s2.size()][s1.size()].first, res };
            return  res;
        };
 
        string s = lcs();
        cout << s.size() << "\n";
        cout << s << "\n";
    }
}
