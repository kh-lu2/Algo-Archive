//Code by Katarzyna Ludwa

#include <iostream>
using namespace std;
 
int nwd(int a, int b) {
    if (b != 0)
        return nwd(b, a%b);
    return a;
};
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int z;
    cin >> z;
 
    while (z--) {
        int a, b;
        cin >> a >> b;
        cout << nwd(a, b)<<"\n";
    }
}
