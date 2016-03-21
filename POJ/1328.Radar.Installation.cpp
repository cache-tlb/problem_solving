#include <cstdio>
#include <cmath>
#include <algorithm>

struct Range {
    double left, right;
};

bool cmp(const Range &a, const Range &b) {
    return (a.left < b.left);
}

const int MAXN = 3008;
Range r[MAXN];

int main() {
    int n;
    double d;
    int t = 0;
    while (scanf("%d%lf", &n, &d) != EOF) {
        if (n == 0 && d == 0) break;
        t++;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            double x, y;
            scanf("%lf%lf", &x, &y);
            double dx2 = d*d*1. - y*y*1.;
            if (d < y) {
                ok = false;
                dx2 = 0;
            }
            double dx = sqrt(dx2);
            r[i].left = x - dx;
            r[i].right = x + dx;
        }
        if (!ok) {
            printf("Case %d: -1\n", t);
            continue;
        }
        std::sort(r, r + n, cmp);
        int cnt = 0;
        double cursor = -1e10;
        for (int i = 0; i < n; i++) {
            if (cursor < r[i].left) {
                cnt++;
                cursor = r[i].right;
            } else if (cursor > r[i].right) {
                cursor = r[i].right;
            }
        }
        printf("Case %d: %d\n", t, cnt);
    }
    return 0;
}
