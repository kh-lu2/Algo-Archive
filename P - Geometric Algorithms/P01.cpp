//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
 
using namespace std;
 
typedef long long LL;
 
struct P {
      LL x = 0, y = 0;
 
      P() {}
      P(LL x, LL y) : x(x), y(y) {}
 
      P operator- (const P& rhs) {
              return P(this->x - rhs.x, this->y - rhs.y);
      }
};
 
int main() {
      cin.tie(0);
      ios::sync_with_stdio(0);
 
      int z;
      cin >> z;
      while (z--) {
              int n; cin >> n;
 
              vector<P>V(n);
              for (auto& p : V) cin >> p.x >> p.y;
 
              sort(V.begin(), V.end(), [](P a, P b) {return (a.x < b.x || (a.x == b.x && a.y < b.y)) ? 1 : 0; });
 
              stack<P> S1;
              P s = V[1];
              S1.push(V[0]);
 
              auto ccw = [&](P V, P W) {
                      return V.x * W.y - V.y * W.x;
              };
 
 
              for (auto& p : V) {
                      while (S1.size() && ccw(s - S1.top(), p - s) >= 0)
                              s = S1.top(), S1.pop();
                      S1.push(s);
                      s = p;
              }
              S1.push(s);
 
              reverse(V.begin(), V.end());
              stack<P>S2;
              S2.push(V[0]);
              s = V[1];
              for (auto& p : V) {
                      while (S2.size() && ccw(s - S2.top(), p - s) >= 0)
                              s = S2.top(), S2.pop();
                      S2.push(s);
                      s = p;
              }
 
              LL res = 0;
              P prev = S2.top(); S2.pop();
              while (S2.size()) {
                      P next = S2.top(); S2.pop();
                      res += ccw(prev - s, next - s);
                      prev = next;
              }
              while (S1.size()) {
                      P next = S1.top(); S1.pop();
                      res += ccw(prev - s, next - s);
                      prev = next;
              }
              cout << res << "\n";
      }
}
