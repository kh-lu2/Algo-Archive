//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <climits>
 
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
              vector <int> t(n), d(n);
              for (int i = 0; i < n; i++)
                      cin >> d[i] >> t[i];
 
              vector <vector <int>>L(n, vector <int>(n)), R(n, vector <int>(n));
              L[0] = R[0] = vector<int>(n, 0);
 
              for (int s = 1; s < n; s++) {
                      for (int i = 0; i < n - s; i++) {
                              L[s][i] = min(L[s - 1][i + 1] + d[i + 1] - d[i], R[s - 1][i + 1] + d[i + s] - d[i]);
                              if (L[s][i] >= t[i]) L[s][i] = 2e8;
 
                              R[s][i] = min(R[s - 1][i] + d[i + s] - d[i + s - 1], L[s - 1][i] + d[i + s] - d[i]);
                              if (R[s][i] >= t[i + s]) R[s][i] = 2e8;
                      }
              }
 
              int res = min(L[n - 1][0], R[n - 1][0]);
              if (res == 2e8)
                      cout << "FAIL\n";
              else
                      cout << res << "\n";
      }
}
