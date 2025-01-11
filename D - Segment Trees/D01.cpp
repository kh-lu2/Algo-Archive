//Code by Katarzyna Ludwa

#include <iostream>
#include <climits>
#include <vector>
 
using namespace std;
 
struct Tree {
    int L = 1;
    vector <int> T;
 
    Tree(const int n, const vector <int> v) {
        while (L <= n)
            L *= 2;
        T.resize(2 * L, INT_MIN);
 
        for (int i = 0; i < n; i++) T[i + L] = v[i];
        for (int i = L - 1; i > 0; i--) T[i] = max(T[2 * i], T[2 * i + 1]);
    }
 
    void update(int p, int x) {         //pos, val
        p += L;
        T[p] = x;
 
        while (p /= 2) T[p] = max(T[2 * p], T[2 * p + 1]);
    }
 
    int query(int p, int q) {           //[)
        p += L; q += L;
        if (q <= p) return 0;
        int maxl = T[p], maxr = INT_MIN;
 
        while (p / 2 != q / 2) {
            if (p % 2 == 0) maxl = max(maxl, T[p + 1]);
            if (q % 2 == 1) maxr = max(T[q - 1], maxr);
            p /= 2; q /= 2;
        }
 
        return max(maxl, maxr);
    }
 
};
 
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int z;
    cin >> z;
    while (z--) {
        int n, m;
        cin >> n >> m;
 
        vector <int> v(n);
        for (auto& x : v) cin >> x;
 
        Tree T(n, v);
 
        while (m--) {
            string s;
            cin >> s;
            int a, b;
            cin >> a >> b;
 
            if (s == "MAX")
                cout << T.query(a-1, b)<< "\n";
            else
                T.update(a-1, b);
        }
    }
}
