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
        string s, t;
        cin >> s >> t;
        string d;
        int j = 0;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == s[j]) {
                d += s[j];
                j++;
            }
        }
        if (d == s)
            cout << "TAK" << "\n";
        else
            cout << "NIE" << "\n";
 
    }
}