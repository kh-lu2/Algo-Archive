//Code by Katarzyna Ludwa

#include <bits/stdc++.h>
using namespace std;
typedef vector<complex<double>> VCD;
 
VCD FFT(VCD &A, VCD &X) {
    int n = A.size();
    if (n == 1)
      return A;
    VCD A0(n / 2), A1(n / 2);
    VCD X2(n / 2);
    for (int i = 0; i < n / 2; i++) {
      A0[i] = A[i * 2];
      A1[i] = A[i * 2 + 1];
      X2[i] = X[2 * i];
    }
    VCD Y0 = FFT(A0, X2);
    VCD Y1 = FFT(A1, X2);
    VCD Y(n);
    for (int i = 0; i < n / 2; i++) {
      Y[i] = Y0[i] + Y1[i] * X[i];
      Y[i + n / 2] = Y0[i] + Y1[i] * X[i + n / 2];
    }
    return Y;
}
 
VCD FFT3(VCD &A, VCD &X) {
    int n = A.size();
    if (n == 1)
      return A;
    VCD A0(n / 3), A1(n / 3), A2(n / 3);
    VCD X3(n / 3);
    for (int i = 0; i < n / 3; i++) {
      A0[i] = A[i * 3];
      A1[i] = A[i * 3 + 1];
      A2[i] = A[i * 3 + 2];
      X3[i] = X[3 * i];
    }
    VCD Y0 = FFT3(A0, X3);
    VCD Y1 = FFT3(A1, X3);
    VCD Y2 = FFT3(A2, X3);
    VCD Y(n);
    for (int i = 0; i < n / 3; i++) {
      Y[i] = Y0[i] +
        Y1[i] * X[i] +
        Y2[i] * X[i] * X[i];
      Y[i + n / 3] = Y0[i] +
        Y1[i] * X[i + n / 3] +
        Y2[i] * X[i + n / 3] * X[i + n / 3];
      Y[i + 2 * n / 3] = Y0[i] +
        Y1[i] * X[i + 2 * n / 3] +
        Y2[i] * X[i + 2 * n / 3] * X[i + 2 * n / 3];
    }
    return Y;
}
 
VCD SuperFFT (VCD &A, VCD &X) {
    int n = A.size();
    if (n == 1) return A;
    int k = 2;
    while (n % k) k++;
    vector<VCD> Ak(k, VCD(n / k));
    VCD Xk(n / k);
 
    for (int i = 0; i < n / k; i++) {
      for (int j = 0; j < k; j++) {
        Ak[j][i] = A[i * k + j];
      }
      Xk[i] = X[i * k];
    }
 
    vector<VCD> Yk(k);
    for (int i = 0; i < k; i++) {
      Yk[i] = SuperFFT(Ak[i], Xk);
    }
 
    VCD Y(n);
    for (int i = 0; i < n / k; i++) {
      for (int j = 0; j < k; j++) {
        complex<double> x = 1;
        for (int l = 0; l < k; l++) {
          Y[i + j * (n / k)] += Yk[l][i] * x;
          x *= X[i + j * (n / k)];
        }
      }
    }
 
    return Y;
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
 
  int z; cin >> z;
  while (z--) {
    string S1, S2;
    cin >> S1 >> S2;
    reverse(S1.begin(), S1.end());
    reverse(S2.begin(), S2.end());
    bool neg = 0;
    if (S1.back() == '-') {
      S1.pop_back();
      neg = !neg;
    }
    if (S2.back() == '-') {
      S2.pop_back();
      neg = !neg;
    }
    int N = S1.size() + S2.size();
    while (1) {
      int temp = N;
      for (auto x: {2, 3, 5, 7}) {
        while (!(temp % x)) {
          temp /= x;
        }
      }
      if (temp == 1) break;
      N++;
    };
 
    VCD A(N), B(N);
    for (int i = 0; i < S1.size(); i++)
      A[i] = S1[i] - '0';
    for (int i = 0; i < S2.size(); i++)
      B[i] = S2[i] - '0';
 
    VCD X(N);
    for (int i = 0; i < N; i++)
      X[i] = polar(1.0, 2 * M_PI * i / N);
 
    VCD YA = SuperFFT(A, X);
    VCD YB = SuperFFT(B, X);
    VCD Y(N);
    for (int i = 0; i < N; i++) {
      Y[i] = YA[i] * YB[i];
      X[i] = conj(X[i]);
    }
 
    VCD YC = SuperFFT(Y, X);
    for (int i = 0; i < N; i++)
      YC[i] /= N;
 
    vector<int> res;
    for (int i = 0; i < N; i++)
      res.push_back((int)(YC[i].real() + 0.5));
 
    for (int i = 0; i < N - 1; i++) {
      res[i + 1] += res[i] / 10;
      res[i] %= 10;
    }
 
    while (res.size() && res.back() == 0) res.pop_back();
 
    if (!res.size()) cout << 0 << "\n";
    else {
      if (neg) cout << "-";
      for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i];
      cout << "\n";
    }
  }
}
