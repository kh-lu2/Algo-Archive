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
              vector < long long> v;
              vector <int> v2;
              int n;
              cin >> n;
              for (int i = 0; i < n; i++) {
                      long long x;
                      cin >> x;
                      if (v.size() == 0 || v[v.size() - 1] != x) {
                              //nowy
                              v.push_back(x);
                              v2.push_back(1);
                      }
                      else {
                              //stary
                              v2[v2.size() - 1]++;
                      }
              }
 
              int q;
              cin >> q;
              while (q--) {
                      long long y;
                      cin >> y;
 
                      int i = 0, j =v.size()-1, k=(i+j)/2;
 
                      while (i<=j) {
                              if (v[k] == y)
                                      break;
                              else if (v[k] < y) {
                                      i = k+1;
                                      k = (i + j) / 2;
                              }
                              else {          //v[k] >y
                                      j = k-1;
                                      k = (i + j) / 2;
                              }
                      }
                      if (j < i)
                              cout << 0 << "\n";
                      else
                              cout << v2[k] << '\n';
              }
      }
}
