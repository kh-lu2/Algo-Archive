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
        string s;
        int base;
        cin >> s;
        if (s == "code") {
            int n;
            cin >> n >> base;
            string res;
 
            if (!n)
                res += "0";
            while (n) {
                if (n % base < 10)
                    res += n % base + '0';
                else
                    res += n % base - 10 + 'A';
                n /= base;
 
            }
            for (int i = res.size() - 1; i >= 0; i--)
                cout << res[i];
            cout << "\n";
 
        }
        else {
            string n;
            cin >> n >> base;
 
            int pow = 1, res=0;
            for (int i = 0; i < n.size(); i++) {
                if (i)
                    pow *= base;
                if (n[n.size()-1 - i] < 58)
                    res += pow * (n[n.size() - 1 -i] - '0');
                else
                    res += pow * (n[n.size() - 1 -i] +10 - 'A');
            }
            cout << res << "\n";
 
 
        }
    }

}