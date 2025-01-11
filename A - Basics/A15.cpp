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
        int h, w;
        cin >> h >> w;
        int s = 0;
 
        vector <vector <bool>> v (h+ 200, vector<bool> (w+200));
 
        for (int i = 100; i < 100 + h; i++) {
            for (int j = 100; j < 100 + w; j++) {
                char c;
                cin >> c;
                if (c == 'o') {
                    v[i][j] = 1;
                    s++;
                }
            }
        }
 
        int t;
        cin >> t;
        while (t--) {
            vector <vector<bool>> cpy(v.begin(), v.end());
            for (int i = 1; i < 199 + h; i++) {
                for (int j = 1; j < 199 + w; j++) {
                    int cnt = 0;
                    for (int k = i - 1; k < i + 2; k++) {
                        for (int l = j - 1; l < j + 2; l++) {
                            if (k != i || l != j) {
                                if (cpy[k][l])
                                    cnt++;
                            }
                        }
                    }
 
                    if (cpy[i][j]) {
                        if (cnt <= 1 || cnt >= 4) {
                            v[i][j] = 0;
                            s--;
                        }
                    }
                    else {
                        if (cnt == 3) {
                            v[i][j] = 1;
                            s++;
                        }
                    }
                }
            }
            cout << s << "\n";
        }
    }
}
