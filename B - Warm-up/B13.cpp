//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
 
      int z;
      cin >> z;
      while (z--) {
              int n;
              long long k;
              cin >> n >> k;
              vector <long long> v(n + 1);
              int a=0, b=0;
              for (int i = 1; i <= n; i++) {
                      cin >> v[i];
                      v[i] += v[i - 1];
                      if (v[i] <= k)
                              b = i;
              }
              int s = 0;
 
              while (b<=n && a>=0) {
                      if (v[b] - v[a] == k) {
                              s++;
                              b++;
                      }
                      else if (v[b] - v[a] > k)
                              a++;
                      else
                              b++;
              }
 
              cout << s << "\n";
 
      }
}