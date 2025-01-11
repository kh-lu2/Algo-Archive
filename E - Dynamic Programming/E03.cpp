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
        int w, h;
        cin >> w >> h;
        vector <vector <int>> v(h, vector <int>(w));
        for (auto& y : v)
            for (auto& x : y)
                cin >> x;
 
        vector <vector <pair<int, bool>>> dp(h, vector<pair<int, bool>>(w));    //1 z góry, 0 z dołu
        dp[0][0].first = v[0][0];
        for (int i = 1; i < w; i++) {
            dp[0][i] = { dp[0][i-1].first + v[0][i], 0 };
        }
        for (int i = 1; i < h; i++)
            dp[i][0] = {dp[i-1][0].first + v[i][0], 1 };
 
        for (int i = 1; i < h; i++) {
            for (int j = 1; j < w; j++) {
                if (dp[i - 1][j].first > dp[i][j - 1].first)
                    dp[i][j].second = 1;
                dp[i][j].first = max(dp[i - 1][j].first, dp[i][j - 1].first) + v[i][j];
            }
        }
 
        cout << dp[h - 1][w - 1].first << " ";
        int i = h - 1, j = w-1;
        string s;
        while (i || j) {
            if (dp[i][j].second) {
                s+="v";
                i--;
            }
            else {
                s+=">";
                j--;
            }
        }
        reverse(s.begin(), s.end());
        cout << s << "\n";
    }
}
