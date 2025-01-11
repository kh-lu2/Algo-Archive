//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
struct Tree {
    int L = 1;
    vector <int> T;
 
    Tree(const int &n) {
        while (L <= n)
            L *= 2;
        T.resize(2 * L);
    }
 
    int query(int k) {
        k += L;
        int res = T[k];
        while (k > 1) {
            if (k % 2 == 0)
                res = max(T[k + 1], res);
            k /= 2;
        }
 
        return res;
    }
 
    void update(int k, int v) {
        k += L;
        T[k] = v;
        while (k /= 2) T[k] = max(T[2 * k], T[2 * k + 1]);
    }
};
 
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int z;
    cin >> z;
    while (z--) {
        int n, size=0;
        cin >> n;
 
        vector <tuple<int, int, int>> v(n);
        for (auto& [a, b, c] : v) {
            cin >> a >> b >> c;
            size = max(size, --b);
        }
 
 
        Tree T(size);
        sort(v.rbegin(), v.rend());
        int res = 0;
        for (auto& [a, b, c] : v) {
            if (c > T.query(b)) {
                res++;
                T.update(b, c);
            }
        }
 
        cout << res << "\n";
    }
}
