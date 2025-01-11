//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <climits>
 
using namespace std;
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int z; cin >> z;
    while (z--) {
        int n, m;
        cin >> n >> m;
 
        vector <vector <pair<int, int>>> G(n), revG(n);;
        while (m--) {
            int a, b, w;
            cin >> a >> b >> w;
            a--; b--;
            G[a].push_back({ b, w });
            revG[b].push_back({ a, w });
        }
        vector <int> inCnt(n),      //liczba roznych sciezek od 1 do v
            outCnt(n),              //liczba roznych sciezek od v do n
            maxInDist(n),           //maksymalna frajda sciezki dojazdowej
            minOutDist(n, INT_MAX), //minimalna frajda sciezki od v do n
            maxPref(n),             //optymalny poprzednik
            minNext(n);             //optymalny nastepnik
 
        inCnt[0] = 1;
        outCnt[n-1] = 1;
 
        for (int u = 0; u < n; u++) {
            for (auto [v, w] : G[u]) {
                inCnt[v] += inCnt[u]; inCnt[v] %= 1000;
            }
        }
 
 
        for (int u = 0; u < n; u++) {
            for (auto [v, w] : G[u]) {
                if (maxInDist[u] + w >= maxInDist[v]) {
                    maxPref[v] = u;
                    maxInDist[v] = maxInDist[u] + w;
                }
                //maxInDist[v] = max(maxInDist[v], maxInDist[u] + w);
            }
        }
 
 
        //======================================
        for (int u = n - 1; u >= 0; u--) {
            for (auto [v, w] : revG[u]) {
                outCnt[v] += outCnt[u]; outCnt[v] %= 1000;
            }
        }
 
        minOutDist[n - 1] = 0;
        for (int u = n - 1; u >= 0; u--) {
            for (auto [v, w] : revG[u]) {
                if (minOutDist[u] + w <= minOutDist[v]) {
                    minNext[v] = u;
                    minOutDist[v] = minOutDist[u] + w;
                }
                //minOutDist[u] = min(minOutDist[u], minOutDist[v] + w);
            }
        }
 
 
        int q;
        cin >> q;
        while (q--) {
            int p;
            cin >> p;
            p--;
            cout << inCnt[p] * outCnt[p] % 1000 << "\n";
            vector <int> /*fir*/st, /*seco*/nd;
            st.push_back(p+1);
            int u = p;
            while (u != 0) {
                u = maxPref[u];
                st.push_back(u+1);
            }
            u = p;
            while (u != n - 1) {
                u = minNext[u];
                nd.push_back(u + 1);
            }
 
            cout << st.size() + nd.size() << " ";
            for (int i = st.size() - 1; i >= 0; i--)
                cout << st[i] << " ";
            for (int i = 0; i < nd.size(); i++)
                cout << nd[i] << " ";
            cout << "\n";
        }
    }
}
