//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
 
using namespace std;
 
int main()
{
      cin.tie();
      ios::sync_with_stdio(0);
 
      int z;
      cin >> z;
      while (z--) {
              int n;
              cin >> n;
 
              vector<int>N(n);
              vector<array<int, 3>>A;
 
              for (int i = 0; i < n; i++) {
                      int a, b, c;
                      cin >> a >> b >> c;
                      N[i] = c;
                      A.push_back({ a, 0, i });
                      A.push_back({ b, 1, i });
              }
              sort(A.begin(), A.end());
 
              int cnt = 0;
              for (auto& [c, t, i] : A) {
                      if (!t)
                              N[i] += cnt;
                      else {
                              if (N[i] > cnt)
                                      cnt = N[i];
                      }
              }
              cout << cnt << "\n";
      }
}
