//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
 
using namespace std;
 
double area( double a1, double a2, double a3, double b1, double b2, double b3) {
     return (sqrt((a2*b3 - a3*b2)* (a2 * b3 - a3 * b2) + (a3*b1 - a1*b3)* (a3 * b1 - a1 * b3) + (a1*b2 - a2*b1)* (a1 * b2 - a2 * b1)))/2;
}
 
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    vector <vector<double>> v (4, vector<double>(3));
 
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> v[i][j];
        }
    }
    double s = 0;
    s += area(v[1][0]-v[0][0], v[1][1]-v[0][1],v[1][2]-v[0][2], v[2][0] - v[0][0], v[2][1] - v[0][1], v[2][2] - v[0][2]);
    s += area(v[1][0] - v[0][0], v[1][1] - v[0][1], v[1][2] - v[0][2], v[3][0] - v[0][0], v[3][1] - v[0][1], v[3][2] - v[0][2]);
    s += area(v[3][0] - v[2][0], v[3][1] - v[2][1], v[3][2] - v[2][2], v[3][0] - v[0][0], v[3][1] - v[0][1], v[3][2] - v[0][2]);
    s += area(v[3][0] - v[2][0], v[3][1] - v[2][1], v[3][2] - v[2][2], v[2][0] - v[1][0], v[2][1] - v[1][1], v[2][2] - v[1][2]);
 
 
 
 
    cout << fixed << setprecision(6) <<s << "\n";
}
