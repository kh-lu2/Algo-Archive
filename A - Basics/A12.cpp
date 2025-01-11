//Code by Katarzyna Ludwa

#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int s = 0;
 
    for (int i = 0; i < 3; i++) {
        int a, b, c;
        cin >> a >> b >> c;
 
        if (a+b+c>2*(max((max(a, b)), c)))
            s++;
 
    }
    cout << s << "\n";
}
