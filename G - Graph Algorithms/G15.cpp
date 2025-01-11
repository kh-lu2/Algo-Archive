//Code by Katarzyna Ludwa

#include <iostream>
#include <array>
#include <unordered_map>
#include <queue>
#include <string>
#include <climits>
 
using namespace std;
 
typedef array<int, 3> Node;
 
struct Distance {
    long long val;
    Distance(long long val = LLONG_MAX) : val(val) {};
 
    operator long long() {
        return val;
    }
};
 
Distance operator< (const Distance& lhs, const Distance& rhs) {
    return lhs.val < rhs.val;
};
 
namespace std {
    template<>
    struct hash<Node> {
        size_t operator()(const Node& node) const {
            auto [a, b, c] = node;
            const auto p = 1696969LL;
            return ((a * p) ^ b) * p ^ c;
        }
    };
}
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int z;
    cin >> z;
 
    while (z--) {
        int n1, n2, n3, n;
        cin >> n1 >> n2 >> n3 >> n;
 
        unordered_map<Node, Distance> D;
        priority_queue <pair<Distance, Node>, vector<pair<Distance, Node>>, greater<pair<Distance, Node>>> Q;
 
        Q.push({ D[{n1, 0, 0}] = 0, {n1, 0, 0} });
        while (!Q.empty()) {
            auto [du, u] = Q.top(); Q.pop();
            auto [a, b, c] = u;
            if (a == n || b == n || c == n) break;
            if (D[u] != du) continue;
 
            auto fun = [&](int d, Node v) {
                auto& dv = D[v];
                auto [x, y, z] = v;
                if ((long long)dv > du + d) Q.push({ dv = du + d, v });
            };
 
            //1->2
            int d = min(a, n2 - b);
            fun(d, { a - d, b + d, c });
            //1->3
            d = min(a, n3 - c);
            fun(d, {a - d, b, c + d});
            //2->3
            d = min(b, n3 - c);
            fun(d, { a, b - d, c + d });
            //2->1
            d = min(b, n1 - a);
            fun(d, { a + d, b - d, c });
            //3->1
            d = min(c, n1 - a);
            fun(d, { a + d, b, c - d });
            //3->2
            d = min(c, n2 - b);
            fun(d, { a, b + d, c - d });
        }
 
        long long res = LLONG_MAX;
        for (auto [X, y] : D) {
            auto [a, b, c] = X;
            if (a == n || b == n || c == n)
                res = min(res,(long long) y);
        }
 
        cout << ((res == LLONG_MAX) ? "NIE" : to_string(res)) << "\n";
    }
}
