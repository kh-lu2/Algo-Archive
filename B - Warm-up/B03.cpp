//Code by Katarzyna Ludwa

#include <iostream>
 
using namespace std;
 
int main() {
      int z;
      cin >> z;
      while (z--) {
              long long a, k, q, res=1;
              cin >> a >> k >> q;
 
              while (k) {
                      if (k % 2 == 1) {
                              res *= a;
                              res %= q;
                      }
                      k /= 2;         //k>>=1;
                      a *= a;
                      a %= q;
              }
              cout << res << "\n";
      }
}
