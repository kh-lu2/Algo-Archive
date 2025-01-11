//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    vector <char> znaki{ 'M', 'D', 'C', 'L', 'X', 'V', 'I' };
    vector <int> liczby{ 1000, 500, 100, 50, 10, 5, 1 };
 
    int z;
    cin >> z;
    while (z--) {
        string m;
        cin >> m;
 
        if (m[0] > 60) {
            int M = 0;
 
            for (int i = 0; i < m.size(); i++) {
                for (int j = 0; j < 7; j++) {
                    if (m[i] == znaki[j]) {
                        if (j == 2 || j == 4 || j == 6) {
                            if (m[i + 1] == znaki[j - 1]) {
                                M += (liczby[j - 1] - liczby[j]);
                                i++;
                            }
                            else if (m[i + 1] == znaki[j - 2]) {
                                M += (liczby[j - 2] - liczby[j]);
                                i++;
                            }
                            else {
                                M += liczby[j];
                            }
                        }
                        else {
                            M += liczby[j];
                        }
                    }
                }
            }
            cout << M << "\n";
        }
        else {
            stringstream liczba(m);
            int n = 0;
            liczba >> n;
 
            while (n >= 1000) {
                n -= 1000;
                cout << 'M';
            }
            int i = 2;
            while (n) {
                if (n >= liczby[i]) {
                    if (n >= liczby[i - 2] - liczby[i]) {
                        n -= (liczby[i - 2] - liczby[i]);
                        cout << znaki[i] << znaki[i - 2];
                    }
                    else if (n >= liczby[i - 1]) {
                        //500-800
                        n -= liczby[i - 1];
                        cout << znaki[i - 1];
                        while (n >= liczby[i]) {
                            n -= liczby[i];
                            cout << znaki[i];
                        }
                    }
                    else if (n >= liczby[i - 1] - liczby[i]) {
                        //400
                        n -= (liczby[i - 1] - liczby[i]);
                        cout << znaki[i] << znaki[i - 1];
                    }
                    else {
                        //100-300
                        while (n >= liczby[i]) {
                            n -= liczby[i];
                            cout << znaki[i];
                        }
                    }
                }
                i += 2;
            }
            cout << "\n";
        }
    }
}
