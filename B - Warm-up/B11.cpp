//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
long long s = 0;
 
 
void merge(vector <long long>& v2, vector <long long>& v, int start, int middle, int end) {
      int i = start, k = middle;
 
      for (int j = start; j < end; j++) {
              if (i < middle && (k >= end || v[i] >= v[k])) {
                      v2[j] = v[i];
                      i++;
              }
              else {
                      v2[j] = v[k];
                      s += 1LL * middle - i;
                      k++;
              }
      }
};
 
void splitnsort(vector <long long>& v, vector <long long>& v2, int i, int j) {                //i - start(zamkniety), j - koniec(otwarty)
      if (i + 1 == j)
              return;
      int k = (i + j) / 2;
 
      splitnsort(v2, v, i, k);
      splitnsort(v2, v, k, j);
 
      merge(v, v2, i, k, j);
 
};
 
void mergesort(vector <long long>& v, vector <long long>& v2) {
      splitnsort(v, v2, 0, v.size());
};
 
 
long long count_pairs(vector <long long> &x, vector <long long> &y) {
      vector <long long> revx(x.size());
      for (int i = 0; i < x.size(); i++)
              revx[x[i]] = i;
 
      vector <long long> yprim(x.size());
      for (int i = 0; i < x.size(); i++)
              yprim[i] = revx[y[i]];
 
      revx = yprim;
      s = 0;
 
      mergesort(revx, yprim);
      return s;
};
 
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
 
      long long z;
      cin >> z;
 
      while (z--) {
              long long n;
              cin >> n;
 
              vector <long long> a(n), b(n), c(n);
 
              for (auto& x : a) { cin >> x; x--; }
              for (auto& y : b) { cin >> y; y--; }
              for (auto& z : c) { cin >> z; z--; }
 
              long long sum = 0;
              sum += count_pairs(a, b);
              sum += count_pairs(b, c);
              sum += count_pairs(a, c);
              sum -= (n * (n - 1)) / 2;
              sum /= 2;
              cout << sum << "\n";
 
      }
}
