//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
      cin.tie(0);
      ios::sync_with_stdio(0);
 
      int z;
      cin >> z;
 
      while (z--) {
              int n; cin >> n;
              vector<long long> V(n);
              for (auto& x : V) cin >> x;
              sort(V.rbegin(), V.rend());
 
              long long sum = V[0], away = 0;
 
              for (long long i = 1; i < n; i++) {
                      if (V[i] > i) {
                              sum += V[i];
                              away++;
                      }
              }
 
              cout << sum - ((away) * (away + 1)) / 2 << "\n";
      }
}
