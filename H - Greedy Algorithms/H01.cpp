//Code by Katarzyna Ludwa

#include <iostream>
#include <deque>
#include <algorithm>
 
using namespace std;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
 
    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;
        deque<int> Or(n), El(n);
 
        for (auto& x : Or) cin >> x;
        for (auto& x : El) cin >> x;
 
        sort(Or.begin(), Or.end());
        sort(El.begin(), El.end());
 
        long long res = 0;
        while (Or.size()) {
            if (Or[0] < El[0]) {
                res--;
                Or.pop_front();
                El.pop_back();
            }
            else if (Or[0] > El[0]) {
                res++;
                Or.pop_front();
                El.pop_front();
            }
            else if (Or.back() < El.back()) {
                res--;
                Or.pop_front();
                El.pop_back();
            }
            else if (Or.back() > El.back()) {
                res++;
                Or.pop_back();
                El.pop_back();
            }
            else {
                if (Or[0] < El.back()) res--;
                else if (Or[0] > El.back()) res++;
                Or.pop_front();
                El.pop_back();
            }
        }
        res *= 200;
        cout << res << "\n";
    }
}
