//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <array>
 
using namespace std;
 
struct Val {
    array<int, 8> v = { 0, 1, 2, 3, 4, 5, 6, 7 };
};
 
Val operator+ (const Val& lhs, const Val& rhs) {
    Val res;
    for (int i = 0; i < 8; i++)
        res.v[i] = lhs.v[rhs.v[i]];
 
    return res;
};
 
istream& operator>> (istream &S, Val& V) {
    for (auto& x : V.v) {
        S >> x; x--;
    }
    return S;
};
 
ostream& operator<< (ostream &S, const Val& V) {
    for (auto& x : V.v) S << x+1 << " ";
    return S;
};
 
struct Tree {
    int L = 1;
    vector <Val> T;
 
    Tree(const int n, const vector <Val> v) {
        while (L <= n)
            L *= 2;
        T.resize(2 * L, Val());
 
        for (int i = 0; i < n; i++) T[i + L] = v[i];
        for (int i = L - 1; i > 0; i--) T[i] = (T[2 * i] + T[2 * i + 1]);
    }
 
    void update(int p, Val x) {         //pos, val
        p += L;
        T[p] = x;
 
        while (p /= 2) T[p] = T[2 * p]+ T[2 * p + 1];
    }
};
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int n;
    cin >> n;
    vector<Val> V(n);
    for (auto& v : V) cin >> v;
 
    Tree T(n, V);
    int k;
    cin >> k;
    while (k--) {
        int p;
        cin >> p;
        p--;
        Val v;
        cin >> v;
        T.update(p, v);
        cout << T.T[1] << "\n";
    }
}
