//Code by Katarzyna Ludwa

#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<complex<double>> VCD;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int z;
    cin >> z;
    while (z--) {
        string a, b;
        cin >> a;
        cin >> b;
 
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
 
        bool minus = false;
        if (a.back() == '-') {a.pop_back(); minus ^= 1;}
        if (b.back() == '-') {b.pop_back(); minus ^=1;}
 
 
 
        int L = 1;
        while (L <= a.size() + b.size()) L *= 2;
 
        function<void(VCD&, const VCD&, bool)> FFT = [&] (VCD& A, const VCD& W, bool invert) {
            int N = A.size();
            if (N == 1) return;
            VCD A0(N/2), A1(N/2), WW(N/2);
 
            for (int i = 0; i< N/2; i++) {
                A0[i] = A[2*i];
                A1[i] = A[2*i + 1];
                WW[i] = W[2*i];
            }
 
            FFT(A0, WW, invert);
            FFT(A1, WW, invert);
 
            for (int j = 0; j <N/2; j++) {
                A[j] = A0[j] + W[j] * A1[j];
                A[j + N/2] = A0[j] - W[j] * A1[j];
 
                if (invert) A[j] /=2, A[j + N/2] /=2;
            }
        };
 
        VCD A(L), B(L);
 
        for (int i = 0; i < a.size(); i++) A[i] = a[i] - '0';
        for (int i = 0; i < b.size(); i++) B[i] = b[i] - '0';
 
        VCD W(L);
        for (int i = 0; i < L; i++)
            W[i] = polar(1.0, 2 * M_PI * i / L);
 
        FFT(A, W, 0);
        FFT(B, W, 0);
 
        VCD C(L);
        for (int i = 0; i < L; i++) C[i] = A[i] * B[i];
 
        for (int i = 0; i < L; i++)
            W[i] = polar(1.0, -2 * M_PI * i / L);
 
        FFT(C, W, 1);
 
        vector<long long> Res(L);
        for (int i = 0; i < L; i++) Res[i] = (long long)(C[i].real() + 0.5);
 
        int over = 0;
        for (int i = 0; i < L; i++) {
            if (Res[i] + over < 10) {
                Res[i] += over;
                over = 0;
            }
            else {
                int temp = (Res[i] + over)/10;
                Res[i] = (Res[i] + over) % 10;
                over = temp;
            }
        }
        while (over) {
            Res.push_back(over % 10);
            over /= 10;
        }
 
        while ((Res.size()) && !Res.back()) Res.pop_back();
 
        if (!Res.size()) {
            cout << 0 << "\n";
            continue;
        }
 
        if (minus) cout << '-';
        reverse(Res.begin(), Res.end());
        for (auto &x: Res) cout << x;
 
        cout << "\n";
 
    }
}
