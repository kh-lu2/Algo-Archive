//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
 
using namespace std;
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;
        vector<long long> left(n+2), right(n+2);
        vector<long long> height(n+2);
        height[0] = -1;
        height[n + 1] = -1;
 
        for (int i = 1; i <= n; i++) cin >> height[i];
        stack<long long>S;
        S.push(0);
        for (int i = 1; i <= n; i++) {
            while (height[S.top()] >= height[i])
                S.pop();
            left[i] = S.top();
            S.push(i);
        }
        while (!S.empty()) S.pop();
        S.push(n + 1);
        for (int i = n; i >0; i--) {
            while (height[S.top()] >= height[i])
                S.pop();
            right[i] = S.top();
            S.push(i);
        }
 
        long long res = 0;
        for (int i = 1; i <= n; i++)
            res = max(height[i] * (right[i] - left[i] - 1), res);
        cout << res << "\n";
    }
}
