//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
 
    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;
        string U; string W;
        cin >> U >> W;
        string UU = U + U, WW = W + W;
 
        auto fun = [&]() ->bool {
            int i = 0, j = 0;
            while (i < n && j < n) {
                int k = 0;
                while (k < n && UU[i + k] == WW[j + k]) k++;
                if (k == n) return 1;
 
                if (UU[i + k] < WW[j + k]) i += k + 1;
                else j += k + 1;
            }
            return 0;
        };
        if (fun()) cout << "IDENTYCZNE\n";
        else {
            reverse(WW.begin(), WW.end());
 
            if (fun()) cout << "IDENTYCZNE\n";
            else cout << "ROZNE\n";
        }
    }
}
