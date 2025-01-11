//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
struct Partia {
    long long g;      //głosy
    long long s;      //mandaty
    long long id;     //numer
 
    Partia(long long glosy, long long mandaty, long long numer) {
        g = glosy;
        s = mandaty;
        id = numer;
    }
};
 
bool operator< (const Partia &L, const Partia &R) {
    long long lval = L.g * (R.s + 1),
        rval = R.g*(L.s + 1);
    if (lval < rval) return true;
    if (rval < lval) return false;
    if (L.g < R.g) return true;
    if (R.g < L.g) return false;
    if (L.id > R.id) return true;
    return false;
}
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int z;
    cin >> z;
    while (z--) {
        int n, m;
        cin >> n >> m;
        vector<int>mandaty(n);
        priority_queue<Partia> Q;
        for (int i = 0; i < n; i++) {
            long long g;
            cin >> g;
            Q.push({ g, 0, i });
        }
 
        while (m--) {
            auto P = Q.top();
            Q.pop();
            mandaty[P.id]++;
            P.s++;
            Q.push(P);
        }
 
        for (auto& x : mandaty) cout << x << "\n";
    }
}
