#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

const int MAXN = 128;
const double G = 9.8;
const double pi = 3.1416;

double h[MAXN], d[MAXN];
double x[MAXN*2], y[MAXN*2];

int main(int argc, char const *argv[])
{
    int N;
    while(scanf("%d", &N) != EOF) {
        for(int i = 0; i < N; i++){
            scanf("%lf%lf", &h[i], &d[i]);
        }
        int npoints = 0;
        double xval = 0;
        for(int i = 0; i < N - 1; i++){
            xval += d[i];
            x[npoints] = xval;
            y[npoints++] = h[i];
            x[npoints] = xval;
            y[npoints++] = h[i + 1];
        }
        xval += d[N - 1];
        double min_k = 0.0;
        for(int i = 0; i < npoints; i++) {
            double k = y[i] / (x[i]*(x[i]-xval));
            if(k < min_k) min_k = k;
        }
        // y = min_k * x * (x - xval);
        double slope = -min_k * xval;
        double theta = atan(slope);
        double max_h = -min_k * xval * xval / 4;
        double vh = sqrt(2.0*G*max_h);
        double v0 = vh * sqrt(1+1/slope/slope);
        printf("%.2lf %.2lf\n", theta*180.0/pi, v0);
    }
    return 0;
}
