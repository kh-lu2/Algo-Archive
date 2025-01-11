//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
 
using namespace std;
 
struct Tree {
    int L = 1;
    vector <int> T;
 
    Tree(const int n) {
        while (L <= n)
            L *= 2;
        T.resize(2 * L);
    }
 
    void update(int p, int q, int x) {          //[)
        p += L; q += L;
        if (q <= p) return;
 
        T[p] += x;
        while (p / 2 != q / 2) {
            if (p % 2 == 0) T[p + 1] += x;
            if (q % 2 == 1) T[q - 1] += x;
            p /= 2; q /= 2;
        }
    }
 
    int query(int k) {
        k += L;
        int res = T[k];
        while (k /= 2) res += T[k];
        return res;
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
        Tree T(n);
 
        while (m--) {
            char c;
            cin >> c;
            if (c == 'P') {
                int a;
                cin >> a;
                cout << T.query(a - 1) << "\n";
            }
            else {
                int p, q, x;
                cin >> p >> q >> x;
                T.update(p - 1, q, x);
            }
        }
    }
}
