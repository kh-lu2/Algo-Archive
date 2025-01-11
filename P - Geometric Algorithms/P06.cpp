//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <algorithm>
#include <iomanip>
 
using namespace std;
 
struct P { // lol
    double x = 0, y = 0;
 
    P() {}
    P(double x, double y) : x(x), y(y) {}
 
    P operator- (const P& rhs) {
        return P(this->x - rhs.x, this->y - rhs.y);
    }
};//um slucham
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
 
    int z; cin >> z;
    while (z--) {
        int n; cin >> n;
        int px, py;
        cin >> px >> py;
 
        vector<array<double, 3>> L; // a b c
 
        for (double i = 0; i < n; i++) {
            int ax, ay, bx, by;
            cin >> ax >> ay >> bx >> by;
            ax -= px, bx -= px, ay -= py, by -= py;
 
            double a = -(by - ay), b = bx - ax, c = a * ax + b * ay;
            if (c < 0) a *= -1, b *= -1, c *= -1;
 
            L.push_back({ a, b, c});
        }
 
        sort(L.begin(), L.end(), [](auto& lhs, auto& rhs) {return atan2(lhs[1], lhs[0]) < atan2(rhs[1], rhs[0]);});
 
        auto point = [&](array<double, 3> A, array<double, 3> B) -> P {
            double Wx = A[2] * B[1] - B[2] * A[1],
                Wy = A[0] * B[2] - B[0] * A[2],
                Wz = A[0] * B[1] - B[0] * A[1];
 
            return { Wx / Wz, Wy / Wz };
        };
 
        auto ccw = [&](const P& V, const P& W) {
            return V.x * W.y - V.y * W.x;
        };//po co dla zabawy ok a najlepiej to wgl nie lambda ale no juz ok
 
 
        bool del = 1;
        while (del) {
            del = 0;
            n = L.size();
 
            vector<bool> D(n);
 
            for (int i = 0; i < L.size(); i++) {
                auto A = point(L[i], L[(i + 1) % n]);
                auto B = point(L[(i + 1) % n], L[(i + 2) % n]);
 
                if (ccw(A, B) < 0) D[(i + 1) % n] = del = 1;
            }
 
            vector<array<double, 3>> temp;
            for (int i = 0; i < n; i++)
                if (!D[i]) temp.push_back(L[i]);
 
            L = temp;
        }
 
        n = L.size();
 
        bool inf = 0;
        for (int i = 0; i < n; i++)
            if (ccw({ L[i][0], L[i][1] }, {- L[(i + 1) % n][0], -L[(i + 1) % n][1] }) > 0) inf = 1;
 
        if (n < 3 || inf) {
            cout << "INF\n";
            continue;
        }
 
        vector<P> V;
        for (int i = 0; i < n; i++)
            V.push_back(point(L[i], L[(i + 1) % n]));
 
        double res = 0;
        for (int i = 2; i < n; i++)
            res += ccw(V[i - 1] - V[0], V[i] - V[0]);
 
        res /= 2;
 
        cout << setprecision(20) << res << "\n";
    }
}
