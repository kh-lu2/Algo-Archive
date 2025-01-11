//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
 
const double pi = 3.14159265358979323846;
 
struct Point {
      long long x = 0;
      long long y = 0;
      int index = 0;
 
      Point(const long long xtemp, const long long ytemp, const int i) {
              index = i;
              x = xtemp;
              y = ytemp;
      }
};
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
 
      int z;
      cin >> z;
      while (z--) {
              int n;
              cin >> n;
              vector <Point> v;
 
              for (int i = 0; i < n; i++) {
                      long long x, y;
                      cin >> x >> y;
                      v.push_back(Point(x, y, i+1));
              }
 
              auto my_comp = [](const Point& p1, const Point& p2) {
                      long long z = p1.x * p2.y - p1.y * p2.x;
 
                      return z ? p1.x * p2.y < p1.y* p2.x : p1.y < p2.y;
              };
 
              sort(v.begin(), v.end(), my_comp);
 
              for (auto& [a, d, i] : v)
                      cout << i << "\n";
      }
}
