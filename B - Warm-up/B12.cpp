//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
 
      int n;
      cin >> n;
 
      vector <long long> v(n);
      long long x;
      cin >> x;
      v[0]=x;
 
      for (int i = 1; i < n; i++) {
              cin >> x;
              v[i] = v[i - 1] + x;
      }
 
      int q;
      cin >> q;
 
      while (q--) {
              int a, b;
              cin >> a >> b;
              a--; b--;
              if (a == 0)
                      cout << v[b]<< "\n";
              else
                      cout << v[b] - v[a-1] << "\n";
      }
}
