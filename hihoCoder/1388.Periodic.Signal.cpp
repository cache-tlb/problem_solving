#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <complex>

using namespace std;

#define PI 3.14159265358979323
const int MAXN = 60000 + 10;

#define lowbit(x) (((x) ^ (x-1)) & (x))
typedef complex<long double> Complex;

void FFT(vector<Complex> &A, int s){
    int n = A.size();
    int p = __builtin_ctz(n);
    
    vector<Complex> a = A;
    
    for(int i = 0;i<n;++i){
        int rev = 0;
        for(int j = 0;j<p;++j){
            rev <<= 1;
            rev |= ((i >> j) & 1);
        }
        A[i] = a[rev];
    }
    
    Complex w,wn;
    
    for(int i = 1;i<=p;++i){
        int M = (1<<i), K = (M>>1);
        wn = Complex(cos(s*2.0*M_PI/(double)M), sin(s*2.0*M_PI/(double)M));
        
        for(int j = 0;j<n;j += M){
            w = Complex(1.0, 0.0);
            for(int l = j;l<K+j;++l){
                Complex t = w;
                t *= A[l + K];
                Complex u = A[l];
                A[l] += t;
                u -= t;
                A[l + K] = u;
                w *= wn;
            }
        }
    }
    
    if(s==-1){
        for(int i = 0;i<n;++i)
            A[i] /= (double)n;
    }
}

void FFT_Multiply(vector<Complex> &P, vector<Complex> &Q, vector<Complex> &R){
    int n = P.size()+Q.size();
    while(n!=lowbit(n)) n += lowbit(n);
    
    P.resize(n,0);
    Q.resize(n,0);
    
    FFT(P,1);
    FFT(Q,1);
    
    R.clear();
    for(int i=0;i<n;i++) R.push_back(P[i]*Q[i]);
    
    FFT(R,-1);
}

std::vector<Complex> A, B, tmpA, tmpB, C;
int n;

int main() {
    // freopen("input.txt", "r", stdin);
    int T, x;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        A.resize(n);
        B.resize(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            A[i].real(x);
            A[i].imag(0);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            B[n-1-i].real(x);
            B[n-1-i].imag(0);
        }
        tmpA = A;
        tmpB = B;
        FFT_Multiply(tmpA, tmpB, C);
        // Conv(tmpA, tmpB, n);
        double max_val = 0;
        int k = -1;
        for (int i = 0; i < n; i++) {
            // std::cout << C[i].real() << ',' << C[i].imag() << '\n';
            Complex tmp = C[i] + C[i+n];
            double mag = tmp.real()*tmp.real() + tmp.imag()*tmp.imag();
            if (mag > max_val) {
                max_val = mag;
                k = i;
            }
        }
        k = n-k-1;
        long long s = 0;
        for (int i = 0; i < n; i++) {
            long long tmp = (A[i].real() - B[n-1-(i+k)%n].real());
            s += tmp*tmp;
        }
        std::cout << s << std::endl;
    }
    return 0;
}
