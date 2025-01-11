//Code by Katarzyna Ludwa

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
      string a, b;
      cin >> a;
      cin >> b;
      int over = 0;
      vector <int> v;
 
      for (int i = 0; i < max(a.size(), b.size()); i++) {
              int A, B, s;
              if (int(a.size() - 1 - i) < 0)
                      A = 0;
              else
                      A = a[a.size() - 1 - i] - '0';
              if (int (b.size() - 1 - i) < 0)
                      B = 0;
              else
                      B = b[b.size() - 1 - i] - '0';
              s = A + B + over;
 
              over = s / 10;
              v.push_back(s - over*10);
              s -= (s - over * 10);
      }
      if (over)
              v.push_back(over);
 
      for (int i = 0; i < v.size(); i++) {
              cout << v[v.size() - 1 - i];
      }
      cout << "\n";
}
