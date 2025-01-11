//Code by Katarzyna Ludwa

#include <iostream>
 
using namespace std;
 
void quicksort(int* t, int l, int r) {
      if (r <= l) return;
 
      int i = l-1, j = r+1, p = t[(l + r) / 2];
 
      while (1) {
              while (p > t[++i]);
              while (p < t[--j]);
 
              /*while (p > t[i])
                      i++;
              while (p < t[j])
                      j--;*/
 
              if (i <= j) {
                      int temp = t[i];
                      t[i] = t[j];
                      t[j] = temp;
              }
              else
                      break;
      }
 
      if (j > l)
              quicksort(t, l, j);
      if (i < r)
              quicksort(t, i, r);
}
 
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
 
      int z;
      cin >> z;
      while (z--) {
              int n=0;
              cin >> n;
              int* t = new int[n];
 
              for (int i = 0; i < n; i++)
                      cin >> t[i];
              quicksort(t, 0, n - 1);
 
              for (int i = 0; i < n; i++)
                      cout << t[i] << " ";
              cout << '\n';
 
              delete[] t;
      }
}
