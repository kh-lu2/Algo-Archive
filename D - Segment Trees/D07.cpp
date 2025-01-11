//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
struct Value {
    int v = 0;
};
 
Value operator+ (const Value& lhs, const Value& rhs) {
    return { max(lhs.v, rhs.v) };
};
 
struct Modif {
    int m;
    bool active = 0;
};
 
Modif operator* (const Modif& lhs, const Modif& rhs) {
    if (!rhs.active) return lhs;
    return rhs;
};
 
Value operator* (const Value& val, const Modif& mod) {
    if (mod.active) return { mod.m };
    return val;
}
 
struct Tree {
    struct Node {
        Value val;
        Modif mod;
        operator Value() {
            return val * mod;
        }
    };
 
    vector<Node> T;
    Tree(int n) {
        int L = 1; while (L <= n) L *= 2;
        T.resize(2 * L);
    }
 
private:
    void update(int p, int q, const Modif& mod, int tp, int tq, int v) {
        if (tq <= p || q <= tp) return;
        if (p <= tp && tq <= q) {
            T[v].mod = T[v].mod * mod;
            return;
        }
 
        T[2 * v].mod = T[2 * v].mod * T[v].mod;
        T[2 * v + 1].mod = T[2 * v + 1].mod * T[v].mod;
        T[v].mod = Modif();
 
        update(p, q, mod, tp, (tp + tq) / 2, 2 * v);
        update(p, q, mod, (tp + tq) / 2, tq, 2 * v + 1);
        T[v].val = T[2 * v] + T[2 * v + 1];
    };
 
    Value query(int p, int q, int tp, int tq, int v) {
        if (tq <= p || q <= tp) return Value();
        if (p <= tp && tq <= q) return T[v];
 
        return (query(p, q, tp, (tp + tq) / 2, 2 * v)
            + query(p, q, (tp + tq) / 2, tq, 2 * v + 1))
            * T[v].mod;
    };
 
public:
    void update(int p, int q, const Modif& mod) {
        update(p, q, mod, 0, T.size() / 2, 1);
    };
 
    Value query(int p, int q) {
        return query(p, q, 0, T.size() / 2, 1);
    };
 
};
 
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int d, n;
    cin >> d >> n;
    Tree T(d);
 
    while (n--) {
        int s, x;
        cin >> s >> x;
        T.update(x, x + s, { T.query(x, x + s).v + 1, 1});
    }
 
    cout << T.T[1].val.v << "\n";
}
