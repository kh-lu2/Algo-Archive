//Code by Katarzyna Ludwa

#include <iostream>
#include <queue>
 
using namespace std;
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
 
      int z;
      cin >> z;
      while (z--) {
              queue <int> A, B;
 
              int a;
              cin >> a;
              while (a--) {
                      int x;
                      cin >> x;
                      A.push(x);
              }
              int b;
              cin >> b;
              while (b--) {
                      int x;
                      cin >> x;
                      B.push(x);
              }
 
              int t;
              cin >> t;
              int i = 0;
              while (t--) {
                      i++;
                      if (A.front() > B.front()) {
                              A.push(B.front());
                              A.push(A.front());
                      }
                      else {
                              B.push(A.front());
                              B.push(B.front());
                      }
                      A.pop();
                      B.pop();
                      if (A.empty()) {
                              cout << "B wygrywa w turze " << i << "." << "\n";
                              break;
                      }
                      if (B.empty()) {
                              cout << "A wygrywa w turze " << i << "." << "\n";
                              break;
                      }
              }
 
              if (!A.empty() && !B.empty()) {
                      cout << "A: ";
                      while (!A.empty()) {
                              cout << A.front() << " ";
                              A.pop();
                      }
                      cout << "\n";
                      cout << "B: ";
                      while (!B.empty()) {
                              cout << B.front() << " ";
                              B.pop();
                      }
                      cout << "\n";
              }
 
      }
}
