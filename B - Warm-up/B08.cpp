//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
 
using namespace std;
 
vector<vector<long long>> multip(const vector <vector<long long>> &m1, const vector<vector<long long>> &m2) {
    vector <vector<long long>> res(m1.size(), vector<long long>(m1.size()));
    for (int i = 0; i < m1.size(); i++) {       //wiersz res
        for (int j = 0; j < m1.size(); j++) {       //kolumna res
            for (int k = 0; k < m1.size(); k++) {
                res[i][j] += (m1[i][k] * m2[k][j]) % 1000;
                res[i][j] %= 1000;
            }
        }
    }
    return res;
};
 
vector <vector<long long>> power(vector <vector<long long>> m, int p) {
    vector <vector <long long>> x (m.size(), vector<long long>(m.size()));
    for (int i = 0; i < m.size(); i++)
        x[i][i] = 1;
 
    while (p) {
        if (p % 2 == 1)
            x=multip(x, m);
 
        m= multip(m, m);
        p /= 2;
    }
 
    return x;
};
 
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int z;
    cin >> z;
    while (z--) {
        int k, m;
        cin >> k >> m;
 
        vector <vector<long long>> M(k, vector <long long>(k, 0));
        for (int i = 0; i < k - 1; i++)
            M[i][i + 1] = 1;
        for (int i = k - 1; i >= 0; i--)
            cin >> M[k - 1][i];
 
        vector <long long> F(k);
        for (int i = k - 1; i >= 0; i--)
            cin >> F[i];
 
        if (m <= k) {
            long long x = F[m - 1] % 1000;
            if (x < 100)
                cout << 0;
            if (x < 10)
                cout << 0;
            cout << x << "\n";
        }
        else {
            M = power(M, m-1);
 
            long long s = 0;
 
            for (int i = 0; i < k; i++) {
                s += (M[0][i] * F[i]) % 1000;
            }
            s %= 1000;
 
            if (s < 100)
                cout << 0;
            if (s < 10)
                cout << 0;
            cout << s << "\n";
        }
    }
}
