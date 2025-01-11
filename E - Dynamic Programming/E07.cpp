//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
 
using namespace std;
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;
        vector <int> v(n);
        for (auto& x : v) cin >> x;
 
        vector <int> lis(n + 1, INT_MAX);
        lis[0] = INT_MIN;
        for (auto& x : v)
            *lower_bound(lis.begin(), lis.end(), x) = x;
        int res = n - (distance(lis.begin(), lower_bound(lis.begin(), lis.end(), INT_MAX) - 1));
        cout << res << "\n";
    }
}
