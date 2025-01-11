//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
struct os {
    ll t, s, p;
    ll tout = LLONG_MAX;
};
 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll n;
    cin >> n;
 
    vector<os> V(n);
    priority_queue<pair<ll, ll>> Q;
    vector<pair<ll, ll>> A(n);
 
    for (ll i = 0; i < n; i++) {
        ll t, s, p;
        cin >> t >> s >> p;
        V[i] = { t, s, p };
        A[i] = { t, i };
    }
    ll T;
    cin >> T;
    ll ta = 0, tt = 20, tj = 0;
    ll it = 0, cnt = 0;
 
    sort(A.begin(), A.end());
 
    while (it < n && ta <= T) {
        while (Q.size() && V[Q.top().second].tout != LLONG_MAX) Q.pop();
 
        if (Q.empty()) {
            if (cnt == n) break;
 
            ta = A[cnt].first;
            if (tt < ta) tt = ta;
            if (tj < ta) tj = ta;
            Q.push({ V[A[cnt].second].p, A[cnt].second });
            cnt++;
        }
        else if (tj <= tt) {
            auto x = Q.top(); Q.pop();
 
            if (V[x.second].tout != LLONG_MAX) continue;
 
            tj = tj + V[x.second].s;
            V[x.second].tout = tj;
        }
        else {
            auto x = A[it];
            it++;
 
            if (V[x.second].tout != LLONG_MAX) continue;
 
            tt = tt + V[x.second].s * 2 + 20;
            V[x.second].tout = tt - 20;
        }
 
        ta = max(ta, min(tt, tj));
 
        while (cnt < n && A[cnt].first <= ta) {
            Q.push({ V[A[cnt].second].p, A[cnt].second });
            cnt++;
        }
    }
 
    for (auto& x : V)
        cout << min(x.tout, T) << "\n";
}
