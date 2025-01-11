//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <climits>
 
using namespace std;
typedef long long LL;
 
LL mind = LLONG_MAX;
 
LL dist(pair<int, int> P1, pair<int, int> P2) {
    return 1LL*(P1.first - P2.first) *(P1.first - P2.first) + 1LL*(P1.second - P2.second) * (P1.second - P2.second);
}
 
LL merge(vector <pair<int, int>>& sorted, vector<pair<int, int>>& v, int start, int middle, int end) {
    long long i = start, k = middle;
 
    for (int j = start; j < end; j++) {
        if (i < middle && (k >= end || v[i] < v[k])){
            sorted[j] = v[i];
            i++;
        }
        else {
            sorted[j] = v[k];
            k++;
        }
    }
 
    return (start + 2 == end ? dist(sorted[start], sorted[start + 1]) : LLONG_MAX);
};
 
void splitnsort(vector<pair<int, int>>& v, vector<pair<int, int>>& sorted, int i, int j) {                //i - start(zamkniety), j - koniec(otwarty)
    if (i + 1 == j)
        return;
    int X, k = (i + j) / 2;
    X = v[k].second;
 
    splitnsort(sorted, v, i, k);
    splitnsort(sorted, v, k, j);
 
    LL d = merge(v, sorted, i, k, j);
    mind = min(mind, d);
 
    vector<int> TC;
    for (int ii = i; ii < j; ii++)
        if (dist(v[ii], {v[ii].first, X}) < d) TC.push_back(ii);
 
    for (int ii = 0; ii < TC.size(); ii++) {
        for (int jj = ii + 1; jj < TC.size() && jj < ii + 7; jj++) {
            LL nd = dist(v[TC[ii]], v[TC[jj]]);
            d = min(nd, d);
        }
    }
    mind = min(mind, d);
};
 
void mergesort(vector<pair<int, int>>& v, vector<pair<int, int>>& sorted) {
    splitnsort(v, sorted, 0, v.size());
};
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
 
    int z; cin >> z;
    while (z--) {
        mind = LLONG_MAX;
        int n; cin >> n;
        vector<pair<int, int>> V1(n), V2(n);
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            V2[i] = V1[i] = { b, a };
        }
 
        mergesort(V1, V2);
        cout << mind << "\n";
    }
}
