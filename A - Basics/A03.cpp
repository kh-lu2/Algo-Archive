//Code by Katarzyna Ludwa

#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
 
      int n, m;
      cin >> n >> m;
 
      string a(m, 'X'), b{'X'};
 
      for (int i = 0; i < m - 2; i++)
              b += ' ';
      b += 'X';
 
 
      for (int i = 0; i < n; i++) {
              if (i == 0 || i == n - 1)
                      cout << a << "\n";
              else
                      cout << b << "\n";
      }
}
