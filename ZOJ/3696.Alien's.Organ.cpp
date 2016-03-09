// poisson distribution

#include <cstdio>
#include <cmath>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        double lambda;
        scanf("%d%lf", &N, &lambda);
        double sp = exp(-lambda);
        for (int n = 1; n <= N; n++) {
            double p = exp(-lambda);
            for (int i = 1; i <= n; i++) {
                p *= lambda;
                p /= i;
            }
            sp += p;
        }
        printf("%.3lf\n", sp);
    }
    return 0;
}
