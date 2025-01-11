//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
 
using namespace std;
 
int main() {
      cin.tie(0);
      ios::sync_with_stdio(0);
 
      int z;
      cin >> z;
      while (z--) {
              int n;
              cin >> n;
 
              vector<pair<int, int>> V(n), R(n);
 
              for (int i = 0; i < n; i++) {
                      int m, w; cin >> m >> w;
                      V[i] = { m, w };
                      R[i] = { m + w, i };
              }
 
              sort(R.begin(), R.end(), [](auto& left, auto& right) {return left.first < right.first;});
 
              priority_queue<int> Q;
              Q.push(V[R[0].second].first);
              long long S = V[R[0].second].first;
              for (int i = 1; i < n; i++) {
                      auto& [sum, id] = R[i];
                      auto& [m, w] = V[id];
                      if (w >= S) {
                              Q.push(m);
                              S += (long long)(m);
                      }
                      else {
                              int maxm = Q.top();
                              if (m < maxm && w >= S - maxm) {
                                      Q.pop();
                                      Q.push(m);
                                      S += (long long)(m - maxm);
                              }
                      }
              }
 
              cout << Q.size() << "\n";
      }
}
