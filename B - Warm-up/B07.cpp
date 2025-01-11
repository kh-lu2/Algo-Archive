//Code by Katarzyna Ludwa

#include <iostream>
#include <cmath>
#include <iomanip>
 
using namespace std;
 
double f(double& v, double& x, double& y, double& c) {
      return v * v * v * v - 2 * c * v * v * v - (x * x - y * y) * v * v + 2 * c * (x * x - y * y) * v - (x * x - y * y) * c * c;
}
 
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
 
      int z;
      cin >> z;
 
      while (z--) {
              double x, y, c;
              cin >> x >> y >> c;
 
              if (y > x) {
                      double temp = y;
                      y = x;
                      x = temp;
              }
 
              double i = 0.000001, j = x,k,  e=0.000001;              //e=dokladnosc
 
              while (abs(i - j) > e) {
                      k = (i + j) / 2;
                      double F = f(k, x, y, c);
 
                      if (abs(F) <= e)
                              break;
                      else if (F * f(i, x, y, c) < 0)
                              j = k;
                      else
                              i = k;
              }
              k = (i + j) / 2;
              cout << fixed << setprecision(3) << sqrt(x * x - k * k)<< "\n";
      }
}
