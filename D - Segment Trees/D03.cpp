//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
 
using namespace std;
 
struct Segment {
      long long suma;
      long long maxpref;
      long long maxsuf;
      long long res;
 
    Segment(long long a, long long b, long long c, long long d) {
        suma = a;
        maxpref = b;
        maxsuf = c;
        res = d;
    }
 
    Segment(long long a) {
        suma = a;
        maxpref = max(0LL, a);
        maxsuf = max(0LL, a);
        res = max(0LL, a);
    }
 
    Segment() {
        suma = 0;
        maxpref = 0;
        maxsuf = 0;
        res = 0;
    }
};
 
Segment operator+ (const Segment& lhs, const Segment& rhs) {
    Segment ans(lhs.suma + rhs.suma,
        max(lhs.maxpref, lhs.suma + rhs.maxpref),
        max(lhs.maxsuf + rhs.suma, rhs.maxsuf),
        max(max( lhs.res, rhs.res), lhs.maxsuf + rhs.maxpref ));
    return ans;
};
 
struct Tree {
    int L = 1;
    vector <Segment> T;
 
    Tree(const int n, const vector <int> v) {
        while (L <= n)
            L *= 2;
        T.resize(2 * L);
 
        for (int i = 0; i < n; i++) T[i + L] = Segment(v[i]);
        for (int i = L - 1; i > 0; i--) T[i] = T[2 * i]+ T[2 * i + 1];
    }
 
    void update(int p, int x) {
        p += L;
        auto& [suma, maxpref, maxsuf, res] = T[p];
        suma = x;
        maxpref = max(0, x);
        maxsuf = max(0, x);
        res = max(0, x);
 
        while (p /= 2) T[p] = T[2 * p] + T[2 * p + 1];
    }
 
    long long query(int p, int q) {           //[)
        p += L; q += L;
        if (q <= p) return 0;
        Segment L = T[p], R;
 
        while (p / 2 != q / 2) {
            if (p % 2 == 0) L = L+ T[p + 1];
            if (q % 2 == 1) R = T[q - 1] + R;
            p /= 2; q /= 2;
        }
 
        return (L + R).res;
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
            if (s == "UPDATE") {
                int k, x;
                cin >> k >> x;
                k--;
                T.update(k, x);
            }
            else {
                int p, q;
                cin >> p >> q;
                p--;
                cout << T.query(p, q) << "\n";
            }
        }
    }
}
