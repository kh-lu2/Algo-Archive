//Code by Katarzyna Ludwa

#include <iostream>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int z;
    cin >> z;
 
    while (z--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
 
        bool b=1;
        for (int i = 0; i < (n / 2); i++) {
            if (s[i] != s[n - i -1])
                b = 0;
        }
        if (b)
            cout << "TAK" << "\n";
        else
            cout << "NIE" << "\n";
 
    }
}
