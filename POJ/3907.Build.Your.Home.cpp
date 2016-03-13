#include <cstdio>
#include <vector>

int main() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (!n) break;
        double x, y;
        std::vector<double> xs, ys;
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf", &x, &y);
            xs.push_back(x);
            ys.push_back(y);
        }
        double s = 0;
        for (int i = 1; i < n; i++) {
            s += (ys[i] + ys[i-1])/2.*(xs[i] - xs[i-1]);
        }
        s += (ys[0] + ys[n-1])/2.*(xs[0] - xs[n-1]);
        if (s < 0) s = -s;
        printf("%d\n", int(s + 0.5));
    }
    return 0;
}
