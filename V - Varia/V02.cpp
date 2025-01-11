//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <functional>
#include <map>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int z; cin >> z;
    while (z--) {
        int n; cin >> n;
        string s1, s2, s3;
        vector<int>V1(n), V2(n), V3(n);
        cin >> s1;
        for (auto& x : V1) cin >> x;
        cin >> s2;
        for (auto& x : V2) cin >> x;
        cin >> s3;
 
        int t = 0;
        map<int, int> M;
        for (auto& x : V1) {
            M[x] = t;
            t++;
        }
 
        if (n == 1) {
            cout << V1[0];
            cout << "\n";
            continue;
        }
        if (s3 == s1) {
            for (auto& x : V1) cout << x << " ";
            cout << "\n";
            continue;
        }
        if (s3 == s2) {
            for (auto& x : V2) cout << x << " ";
            cout << "\n";
            continue;
        }
        if (s1 == s2) {
            if (n == 2 && s1[0] != 'I' && s3[0] != 'I')
                cout << V1[1] << " " << V1[0];
            else
                cout << "ERROR";
            cout << "\n";
            continue;
        }
        if (s2[1] == 'R' && s1[1] == 'N') {
            swap(s1, s2);
            swap(V1, V2);
        }
        if (s1[1] == 'R' && s2[1] == 'N') {
            vector<int>Fn(n);
            for (int i = 0; i < n; i++)
                Fn[M[V2[i]]] = i;
 
            function<void(int, int, int, int)> funRN = [&](int pos, int na, int nb, int oa) {
                if (na >= nb) return;
 
                int find = Fn[M[V1[pos]]];
                V3[oa + nb - na - 1] = V1[pos];
                funRN(pos + 1, na, find, oa);
                funRN(pos + find - na + 1, find + 1, nb, oa + find - na);
 
            };
 
            funRN(0, 0, n, 0);
 
            for (auto& x : V3) cout << x << " ";
            cout << "\n";
            continue;
        }
        if (s2[1] == 'O' && s1[1] == 'N') {
            swap(s1, s2);
            swap(V1, V2);
        }
        if (s1[1] == 'O' && s2[1] == 'N') {
            vector<int>Fn(n);
            for (int i = 0; i < n; i++)
                Fn[M[V2[i]]] = i;
 
            function<void(int, int, int, int)> funON = [&](int pos, int na, int nb, int rb) {
                if (na >= nb) return;
 
                int find = Fn[M[V1[pos]]];
                V3[rb - (nb - na - 1)] = V1[pos];
                funON(pos - 1, find + 1, nb, rb);
                funON(pos - (nb - find), na, find, rb - (nb - find - 1));
            };
 
            funON(n - 1, 0, n, n - 1);
 
            for (auto& x : V3) cout << x << " ";
            cout << "\n";
            continue;
        }
        if (s1[1] == 'O' && s2[1] == 'R') {
            swap(s1, s2);
            swap(V1, V2);
        }
        if (s1[1] == 'R' && s2[1] == 'O') {
            vector<int>Fn(n);
            for (int i = 0; i < n; i++)
                Fn[M[V2[i]]] = i + 1;
 
            vector<int> T1(n + 2, -1), T2(n + 2, -1);
            T1[n + 1] = T2[n + 1] = -2;
            for (int i = 1; i <= n; i++) {
                T1[i] = V1[i - 1];
                T2[i] = V2[i - 1];
            }
            bool b = 0;
            for (int i = 1; i <= n; i++) {
                int find = Fn[M[T1[i]]];
                if (T1[i - 1] == T2[find + 1] || T1[i + 1] == T2[find - 1])
                    b = 1;
            }
            if (b) {
                cout << "ERROR";
                cout << "\n";
                continue;
            }
 
            for (auto &x: Fn) x--;
 
            function<void(int, int, int, int)> funRO = [&](int pos, int oa, int ob, int na) {
                if (oa >= ob || pos >= n) return;
                if (pos + 1 >= n || Fn[M[V1[pos + 1]]] > Fn[M[V1[pos]]]) {
                    V3[na] = V1[pos];
                    return;
                }
 
                int find = Fn[M[V1[pos + 1]]];
 
                V3[na + find - oa + 1] = V1[pos];
 
                funRO(pos + 1, oa, find + 1, na);
                funRO(pos + find - oa + 2, find + 1, ob - 1, na + find - oa + 2);
            };
 
            funRO(0, 0, n, 0);
 
            for (auto& x : V3) cout << x << " ";
            cout << "\n";
            continue;
        }
 
    }
}
