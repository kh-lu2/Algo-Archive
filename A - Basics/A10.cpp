//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
 
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
        cout << n << " = ";
        vector <pair<int, int>> v;
 
        int i = 2;
        while (n != 1) {
            if (i * i > n) {
                v.push_back({ n, 1 });
                break;
            }
            int s = 0;
            while (n % i == 0) {
                s++;
                n /= i;
            }
            if (s)
                v.push_back({ i, s });
            i++;
        }
 
        for (int i = 0; i < v.size(); i++) {
            if (i)
                cout << "*";
            cout << v[i].first;
            if (v[i].second != 1)
                cout << "^" << v[i].second;
        }
        cout << "\n";
    }
}
