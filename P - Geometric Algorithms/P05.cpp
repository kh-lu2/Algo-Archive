//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <array>
#define int long long
 
using namespace std;
 
struct Value {
    int H = 0;
    int R = 0;
};
 
struct Modif {
    int C = 0;
};
 
Value operator+ (const Value& lhs, const Value& rhs) {
    return { lhs.H + rhs.H, lhs.R + rhs.R};
}
 
Modif operator* (const Modif& lhs, const Modif& rhs) {
    return { lhs.C + rhs.C };
}
 
Value operator* (const Value& lhs, const Modif& rhs) {
    return { lhs.H, rhs.C ? lhs.H : lhs.R};
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
 
    Tree(const vector<Value>& V) {
        while (L <= V.size()) L *= 2;
        T = vector<Node>(2 * L);
        for (int i = 0; i < V.size(); i++)
            T[i + L].val = V[i];
        for (int i = L - 1; i > 0; i--)
            T[i].val = T[2 * i] + T[2 * i + 1];
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
 
int32_t main() {
      ios::sync_with_stdio(0);
      cin.tie(0);
 
    int z; cin >> z;
    while (z--) {
        int n; cin >> n;
        vector<array<int, 4>> A;
        vector<int> Y;
        while (n--) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
 
            Y.push_back(y1);
            Y.push_back(y2);
 
            A.push_back({ x1, 1, y1, y2 });
            A.push_back({ x2, -1, y1, y2 });
        }
        sort(A.begin(), A.end());
 
        sort(Y.begin(), Y.end());
        auto e = unique(Y.begin(), Y.end());
        Y.resize(e - Y.begin());
 
        vector<Value> diff((int)Y.size() - 1);
        for (int i = 0; i < Y.size() - 1; i++) diff[i] = { Y[i + 1] - Y[i], 0 };
 
        unordered_map<int, int> newY;
        for (int i = 0; i < Y.size(); i++)
            newY[Y[i]] = i;
 
        long long res = 0;
 
        int lastx = 0;
        Tree<Value, Modif> T(diff);
        for (auto [x, t, y1, y2] : A) {
            res += (x - lastx) * T.query().R;
            lastx = x;
            T.update(newY[y1], newY[y2], { t });
        }
 
        cout << res << "\n";
    }
}
