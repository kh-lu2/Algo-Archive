//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
int main() {
      string a, b;
      cin >> a;
      cin >> b;
 
      if (a == b) {
              cout << 0 << "\n";
              return 0;
      }
 
      if ((a.size() == b.size() && a[0] < b[0]) || b.size()>a.size()) {
              string t=a;
              a = b;
              b = t;
      }
 
      vector <int> v;
 
 
      for (int i = 0; i < a.size(); i++) {
              int A = a[a.size() - 1 - i] - '0';
              int B;
              if (int(b.size() - 1 - i) < 0)
                      B = 0;
              else
                      B = b[b.size() - 1 - i] - '0';
 
 
              if (A >= B)
                      v.push_back(A - B);
              else {
                      int j = i + 1;
                      while (a[a.size() -1-j] == '0')
                              j++;
 
                      while (j > i) {
                              if (a[a.size()-1-j] != '0')
                                      a[a.size()-1-j]--;
                              else
                                      a[a.size()-1-j] = '9';
                              j--;
                      }
 
                      v.push_back(A + 10 - B);
 
              }
      }
      int i = v.size() - 1;
      while (v[i] == 0) {
              v.pop_back();
              i--;
      }
 
 
      for (int i = 0; i < v.size(); i++) {
              cout << v[v.size() - 1 - i];
      }
      cout << "\n";
}
