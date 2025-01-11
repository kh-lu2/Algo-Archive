//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <unordered_map>
 
using namespace std;
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
 
 
      int z;
      cin >> z;
      while (z--) {
              int m;
              cin >> m;
              vector <int> A(m);
              for (auto& a : A)
                      cin >> a;
 
              int n;
              cin >> n;
              vector <vector<int>> B(n);
              unordered_map <int, vector<int>> M;
              for (int i = 0; i < n; i++) {
                      int c;
                      cin >> c;
                      while (c--) {
                              int temp;
                              cin >> temp;
                              B[i].push_back( temp);
                      }
                      M[B[i].back()].push_back(i);
              }
 
              for (int i = m - 1; i >= 0; i--) {
                      vector <int> temp;
                      swap(temp, M[A[i]]);
                      if (!temp.empty()) {
                              for (auto& e : temp) {
                                      B[e].pop_back();
                                      if (!B[e].empty())
                                              M[B[e].back()].push_back(e);
                              }
                      }
              }
 
              for (auto& v : B) {
                      if (v.empty())
                              cout << "TAK" << '\n';
                      else
                              cout << "NIE" << "\n";
              }
 
      }
}