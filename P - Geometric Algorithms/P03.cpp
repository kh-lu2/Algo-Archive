//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <algorithm>
#include <array>
 
using namespace std;
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
 
    int z;
    cin >> z;
    while (z--) {
        int n; cin >> n;
        vector<array<int, 3>> A;  // x, y, id
        vector<int> DtoW(n);
        long long ans = 0;
        for (int i = 0; i < 2 * n; i++) {
            int x, y;
            cin >> x >> y;
            A.push_back({ x, i, y });   // W.id < n, D.id >= n
            ans += x * ((i < n) ? -1 : 1);
            ans += y * ((i < n) ? 1 : -1);
        }
 
        set<pair<int, int>> M;   // y, id
 
        sort(A.begin(), A.end());
        for (auto& [x, id, y] : A) {
            if (id < n) /*W*/ M.insert({ y, id });
            else {  //D
                auto it = M.lower_bound({ y, -1 });
                DtoW[id - n] = it->second;
                M.erase(it);
            }
        }
 
        cout << ans << "\n";
        for (int i = 0; i < n; i++)
            cout << DtoW[i] + 1 << " " << i + 1 << "\n";
    }
}
