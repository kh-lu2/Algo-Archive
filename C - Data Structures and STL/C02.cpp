//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <stack>
 
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
        vector<int>loostra(n);
        vector<int>deg(n);
        stack<int> S;
        for (auto& x : loostra) {
            cin >> x; x--;
            deg[x]++;
        }
 
        for (int i = 0; i < n; i++)
            if (deg[i] == 0) S.push(i);
 
        while (!S.empty()) {
            int v = S.top();
            S.pop();
            deg[loostra[v]]--;
            if (deg[loostra[v]] == 0)
                S.push(loostra[v]);
        }
        int res = 0;
        for (auto& x : deg)
            if (x > 0)
                res++;
 
        cout << res << "\n";
    }
}
