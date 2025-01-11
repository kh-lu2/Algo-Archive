//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
 
using namespace std;
 
struct Val {
    int V = 0;
};
 
Val operator+ (const Val& lhs, const Val& rhs) {
    return { max(lhs.V,rhs.V) };
}
 
struct Modif {
    int m = 0;
};
 
Modif operator*(const Modif& lhs, const Modif& rhs) {
    //return {max(lhs.m, rhs.m)};
    return { lhs.m + rhs.m };
};;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
Val operator*(const Val& lhs, const Modif& rhs) {
    return { lhs.V + rhs.m };
};
 
struct Tree {
    struct Node {
        Val val;
        Modif modif;
        operator Val() {
            return val * modif;
        }
    };
    int L = 1;
    vector <Node> T;
    Tree(int n) {
        while (L <= n) L *= 2;
        T.resize(2 * L);
    }
 
    Val query(int p, int q) {
        p += L; q += L;
        if (p >= q) return Val();
        Val LRes = T[p];
        Val RRes;
        while (p / 2 != q / 2) {
            if (p % 2 == 0)
                LRes = LRes + T[p + 1];
            if (q % 2 == 1)
                RRes = T[q - 1] + RRes;
            p /= 2; q /= 2;
 
            LRes = LRes * T[p].modif;
            RRes = RRes * T[q].modif;
        }
        LRes = LRes + RRes;
        while (p /= 2)
            LRes = LRes * T[p].modif;
        return LRes;
    }
 
    void update(int p, int q, const Modif& modif) {
        p += L; q += L;
        if (p >= q) return;
        T[p].modif = T[p].modif * modif;
        while (p / 2 != q / 2) {
            if (p % 2 == 0)
                T[p + 1].modif = T[p + 1].modif * modif;
            if (q % 2 == 1)
                T[q - 1].modif = T[q - 1].modif * modif;
            p /= 2; q /= 2;
 
            T[p].val = T[2 * p] + T[2 * p + 1];
            T[q].val = T[2 * q] + T[2 * q + 1];
        }
        while (p /= 2)
            T[p].val = T[2 * p] + T[2 * p + 1];
    }
 
};
 
 
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int z;
    cin >> z;
    while (z--) {
        int n, m, q;
        cin >> n >> m >> q;
 
        Tree T(n);
        while (q--) {
            int p, k, l;
            cin >> p >> k >> l;
            p--; k--;
 
            if (T.query(p, k).V + l <= m) {
                cout << "T\n";
                T.update(p, k, { l });
            }
            else
                cout << "N\n";
 
        }
    }
}
