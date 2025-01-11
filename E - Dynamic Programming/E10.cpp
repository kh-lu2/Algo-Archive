//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;
 
vector<int> lcs(const string &p, const string &q) {
    vector <int> prev(q.size()+1), next(q.size()+1);
    for (int i = 1; i <= p.size(); i++) {
        for (int j = 1; j <= q.size(); j++) {
            if (p[i - 1] == q[j - 1])
                next[j] = prev[j - 1] + 1;
            else
                next[j] = max(next[j - 1], prev[j]);
        }
        prev = next;
        next = vector<int>(q.size() + 1);
    }
    return prev;
}
 
string hirchberg(const string& p, const string& q) {
    if (p.size() == 1) {
        if (q.find(p) != string::npos)
            return p;
        return "";
    }
    if (q.size() == 1) {
        if (p.find(q) != string::npos)
            return q;
        return "";
    }
 
 
    string str1 = p, str2 = q,
        str1start = str1.substr(0, str1.size()/2),
        str1end =str1.substr(str1.size()/2),
        revstr2, revstr1end;
 
    for (int i = str2.size() - 1; i >= 0; i--)
        revstr2.push_back(str2[i]);
 
    for (int i = str1end.size() - 1; i >= 0; i--)
        revstr1end.push_back(str1end[i]);
 
    vector <int> v1 = lcs(str1start, str2),
        v2 = lcs(revstr1end, revstr2);
    reverse(v2.begin(), v2.end());
 
    vector <int> res(v1.size());
    for (int i = 0; i < res.size(); i++)
        res[i] = v1[i] + v2[i];
 
    int mx = distance(res.begin(), max_element(res.begin(), res.end()));
 
    return hirchberg(str1start, str2.substr(0, mx)) + hirchberg(str1end, str2.substr(mx));
}
 
 
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int z;
    cin >> z;
    while (z--) {
        string p, q;
        cin >> p >> q;
        string res = hirchberg(p, q);
        cout << res.size() << "\n";
        cout << res << "\n";
    }
}
