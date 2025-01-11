//Code by Katarzyna Ludwa

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <map>
 
using namespace std;
struct Value {
    int V = 0;
};
 
struct Modif {
    int M = 0;
};
 
Value operator+ (const Value &lhs, const Value& rhs) {
    return { max(lhs.V, rhs.V) };
}
 
Modif operator* (const Modif& lhs, const Modif& rhs) {
    return { lhs.M + rhs.M };
}
 
Value operator* (const Value& lhs, const Modif& rhs) {
    return { lhs.V + rhs.M };
}
 
template<typename Value, typename Modif>
struct Tree {
    struct Node {
        Value val;
        Modif mod;
        operator Value() {
            return val * mod;
        }
    };
    int L = 1;
    vector<Node> T;
 
    Tree(int n) {
        while (L <= n) L *= 2;
        T = vector<Node>(2 * L);
    }
 
    void update(int p, int q, Modif modif) {  //[)
        p += L; q += L;
        T[p].mod = T[p].mod * modif;
        while (p / 2 != q / 2) {
            if (p % 2 == 0)
                T[p + 1].mod = T[p + 1].mod * modif;
            if (q % 2 == 1)
                T[q - 1].mod = T[q - 1].mod * modif;
            p /= 2; q /= 2;
 
            T[p].val = T[2 * p] + T[2 * p + 1];
            T[q].val = T[2 * q] + T[2 * q + 1];
        }
        while (p /= 2)
            T[p].val = T[2 * p] + T[2 * p + 1];
    };
 
    Value query() {
        return T[1];
    };
};
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int z; cin >> z;
    while (z--) {
        int n; cin >> n;
        vector<array<int, 4>> V;
        vector<int> Ys;
        for (int i = 0; i < n; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            V.push_back({ a, 0, b, d });
            V.push_back({ c, 1, b, d });
            Ys.push_back(b);
            Ys.push_back(d);
        }
 
        sort(V.begin(), V.end());
        sort(Ys.begin(), Ys.end());
 
        map<int, int> new_y;
        int cnt = 0;
        for (auto& y : Ys) {
            if (!new_y.count(y)) {
                new_y[y] = cnt;
                cnt++;
            }
        }
 
        Tree<Value, Modif> M(cnt);
        int res = 0;
 
        for (auto& [x, type, start, end] : V) {
            if (type)
                M.update(new_y[start], new_y[end] + 1, { -1 });
            else {
                M.update(new_y[start], new_y[end] + 1, { 1 });
                res = max(res, M.query().V);
            }
        }
 
        cout << res << "\n";
    }
}
