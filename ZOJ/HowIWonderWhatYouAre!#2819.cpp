#include <cstdio>
#include <cmath>

using namespace std;

#define EPS 1e-12

const int MAXN = 512;
const int MAXM = 64;
double x[MAXN], y[MAXN], z[MAXN];
double tx[MAXM], ty[MAXM], tz[MAXM], psi[MAXM];

inline double len2(double a, double b, double c) {
    return a*a + b*b + c*c;
}

bool see(int i, int j) {
    double costheta = (x[i]*tx[j] + y[i]*ty[j] + z[i]*tz[j]) / sqrt(len2(x[i], y[i], z[i])*len2(tx[j], ty[j], tz[j]));
    double theta = acos(costheta);
    return (theta < psi[j] + EPS);
}

int main(int argc, char const *argv[])
{
    int n, m;
    while(scanf("%d", &n) != EOF) {
        if(!n) break;
        for(int i = 0; i < n; i++) {
            scanf("%lf%lf%lf", &x[i], &y[i], &z[i]);
        }
        scanf("%d", &m);
        for(int i = 0; i < m; i++) {
            scanf("%lf%lf%lf%lf", &tx[i], &ty[i], &tz[i], &psi[i]);
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(see(i, j)) {
                    cnt++;
                    break;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
