//Code by Katarzyna Ludwa

#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int z;
    cin >> z;
    while (z--) {
        string H;
        cin >> H;
        int n = H.size();
        vector<int>pi(n + 1);
        auto t = pi[0] = -1;
        for (int i = 0; i < n; i++) {
                while (t != -1 && H[t] != H[i]) t = pi[t];
            pi[i + 1] = ++t;
        }
 
        t = pi[n];
        auto s = n - t;
        while (t != -1) {
            s = n - t;
            if (n % s == 0) break;
            t = pi[t];
        }
        cout << n/s << "\n";
    }
 
}
