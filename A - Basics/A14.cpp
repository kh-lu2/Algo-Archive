//Code by Katarzyna Ludwa

#include <iostream>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
 
    cout << n << "\n";
    while (n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else {
            n *= 3;
            n++;
        }
        cout << n << "\n";
    }
}
