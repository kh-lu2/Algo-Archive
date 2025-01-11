//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
 
    vector <bool> v(n + 1);
    v[1] = 1;
 
    for (int i = 2; i <= n; i++) {
        if (!v[i]) {
            for (int j = 2*i; j <= n; j += i)
                v[j] = 1;
        }
    }
 
    for (int i = n; i > 2; i--) {
        if (!v[i])
            cout << "BUZZ green bottles standing on the wall.\nBUZZ green bottles standing on the wall.\nand if one green bottle should accidentally fall,\n";
        else
            cout << i << " green bottles standing on the wall.\n" << i << " green bottles standing on the wall.\nand if one green bottle should accidentally fall,\n";
 
        if (!v[i - 1])
            cout << "there'd be BUZZ green bottles standing on the wall.\n\n";
        else
            cout << "there'd be " << i - 1 << " green bottles standing on the wall.\n\n";
 
    }
 
    if (n > 1)
        cout << "BUZZ green bottles standing on the wall.\nBUZZ green bottles standing on the wall.\nand if one green bottle should accidentally fall,\nthere'd be 1 green bottle standing on the wall.\n\n";
 
    cout << "1 green bottle standing on the wall.\n1 green bottle standing on the wall.\nand if one green bottle should accidentally fall,\nthere'd be no green bottles standing on the wall.\n";
}
