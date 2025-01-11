//Code by Katarzyna Ludwa

#include <bits/stdc++.h>
 
using namespace std;
vector<int> Z(string& W) {
    vector<int> R(W.size() + 1);
    R[0] = W.size();
    for (int i = 1, j = 0, k; i <= W.size(); i += k, j = max(0, j - k)) {
        while (i + j < W.size() && W[j] == W[i + j]) j++;
        R[i] = j;
        for (k = 1; k + R[k] < j; k++) R[i + k] = R[k];
    }
    return R;
}
 
vector<int> Z(const string& T, const string& W, const vector<int>& Z) {
    vector<int> R(T.size() + 1);
    for (int i = 0, j = 0, k; i <= T.size(); i += k, j = max(0, j - k)) {
        while (j < W.size() && i + j < T.size() && W[j] == T[i + j]) j++;
        R[i] = j;
        for (k = 1; k + Z[k] < j; k++) R[i + k] = Z[k];
    }
    return R;
}
 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int z;
    cin >> z;
    while (z--) {
        int w;
        cin >> w;
        string W;
        cin >> W;
        int n;
        cin >> n;
        string T;
        cin >> T;
 
        vector<int> z = Z(T, W, Z(W));
        reverse(W.begin(), W.end());
        reverse(T.begin(), T.end());
        vector<int> zp = Z(T, W, Z(W));
        reverse(zp.begin(), zp.end());
        vector<int>V(n + 1);
        for (int i = 0; i <= n; i++) {
            if (z[i] + zp[i] >= w) {
                V[i - zp[i]]++;
                V[i + z[i] - w + 1]--;
            }
        }
        partial_sum(V.begin(), V.end(), V.begin());
        int cnt = 0;
        for (auto& x : V) cnt += !!x;
 
        cout << cnt << " ";
        for (int i = 0; i <= n; i++)
            if (V[i] > 0) cout << i << " ";
        cout << "\n";
 
    }
}
