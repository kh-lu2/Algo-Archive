//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int z;
    cin >> z;
    while (z--) {
        int n; cin >> n;
        vector<ll> A(n);
        for (auto& a : A) cin >> a;
        ll M1 = 1e9 + 7, M2 = 1e9 + 9, x1 = 1696969, x2 = 123456;
 
        ll h1 = 0, h2 = 0;
        vector <ll> W1(1), W2(1);
 
        for (auto& a : A) {
            ((h1 *= x1) += a) %= M1;
            ((h2 *= x2) += a) %= M2;
            W1.push_back(h1);
            W2.push_back(h2);
        }
 
        vector <ll> X1(n, x1), X2(n, x2);
        for (int i = 1; i < n; i++) {
            X1[i] = (X1[i - 1] * x1) % M1;
            X2[i] = (X2[i - 1] * x2) % M2;
        }
 
        auto fi = [&](int k) {
            set<pair<ll, ll>> S;
 
            for (int i = 0; i <= n - k; i++)
                S.insert({ (W1[i + k] + (M1 - W1[i]) * X1[k - 1]) % M1, (W2[i + k] + (M2 - W2[i]) * X2[k - 1]) % M2 });
 
            return (S.size() == n - k + 1);
        };
 
        int P = 1, Q = n + 1;
        while (P < Q) {
            auto K = P + (Q - P) / 2;
            if (fi(K))  Q = K;
            else P = K + 1;
        }
 
        cout << P << '\n';
    }
}
