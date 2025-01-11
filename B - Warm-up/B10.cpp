//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
void quicksort(vector<pair<long long, string>> &v, int l, int r) {
      if (r <= l) return;
 
      int i = l - 1, j = r + 1, p = v[(l + r) / 2].first;
 
      while (1) {
              if (i + 1 > v.size() - 1)
                      i++;
              else {
                      while (p > v[++i].first)
                              if (i > v.size() - 1)
                                      break;
              }
 
              if (j - 1 < 0)
                      j--;
              else {
                      while (p < v[--j].first)
                              if (j < 0)
                                      break;
              }
 
              if (i <= j) {
                      pair<long long, string> temp = v[i];
                      v[i] = v[j];
                      v[j] = temp;
              }
              else
                      break;
      }
 
      if (j > l)
              quicksort(v, l, j);
      if (i < r)
              quicksort(v, i, r);
}
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
 
      int z;
      cin >> z;
      while (z--) {
              long long n, s;
              cin >> n>>s;
 
              vector <pair<long long, string>> v(n);
              for (int i = 0; i < n; i++) {
                      string s;
                      long long l;
                      cin >> s >> l;
                      v[i] = { l, s };
              }
 
              quicksort(v, 0, v.size() - 1);
 
              int i = 0, j = v.size()-1;
              while (i <= v.size() - 1 && j>=0) {
                      if (v[i].first + v[j].first == s)
                              break;
 
                      if (v[i].first + v[j].first < s)
                              i++;
                      else
                              j--;
              }
 
              if (i > v.size() - 1 || j<0)
                      cout << "NIE" << "\n";
              else
                      cout << v[i].second << " " << v[j].second << "\n";
      }
}
