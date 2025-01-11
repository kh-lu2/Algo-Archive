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
 
      vector <int>v (n);
 
      for (auto& x : v) {
              cin >> x;
      }
 
      for (int i = v.size() - 1; i >= 0; i--)
              cout << v[i] << " ";
      cout << "\n";
}
