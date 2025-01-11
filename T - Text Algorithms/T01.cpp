//Code by Katarzyna Ludwa

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int z;
    cin >> z;
    while (z--) {
        string s, S("#");
        cin >> s;
 
        for (auto &c: s) (S += c) += "#";
        int n = S.size();
 
        vector<int> R(n);
        R[0] = 1;
 
        for (int i=1, j=1, k; i<n; i+=k, j-=k) {
            while (i-j >= 0 && i+j<n && S[i-j]==S[i+j]) j++;
 
            R[i] = j;
 
            for (k =1; k + R[i-k]<j; k++) R[i+k] = R[i-k];
        }
 
        int q;
        cin >> q;
 
        while (q--) {
            int a, b;
            cin >> a >> b;
 
            if (R[a+b-1] > b - a +1)
                cout << "TAK\n";
            else cout <<"NIE\n";
        }
    }
}
