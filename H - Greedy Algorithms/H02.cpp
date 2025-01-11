//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
      cin.tie(0);
      ios::sync_with_stdio(0);
 
      int z; cin >> z;
      while (z--) {
              int m, n; cin >> m >> n;
              m--; n--;
              vector<pair<int, bool>> V;
              while (m--) {
                      int x;
                      cin >> x;
                      V.push_back({ x, 1 });
              }
              while (n--) {
                      int y;
                      cin >> y;
                      V.push_back({ y, 0 });
              }
 
              int xcnt = 1, ycnt = 1;
              long long res = 0;
              sort(V.rbegin(), V.rend());
 
              for (auto& [x, b] : V) {
                      if (b) {
                              res += (ycnt * x);
                              xcnt++;
                      }
                      else {
                              res += (xcnt * x);
                              ycnt++;
                      }
              }
              cout << res << "\n";
      }
}
