// for each island, there is a range of location for radar installation to cover it.
// thus the problem is equivalent to another problem: 
// find the least number of points on the axis so that for any range there is a point in it.
// we can use greedy algorithm to solve it.
// first sort the ranges based on their lower bounds.
// for the first range, we should put a point in it. 
// we also want this point falls in other ranges, as many as possible.
// so we move the position of the point, if the upper bound of the next range is smaller than that point
// the point is moved to that it can fall in both range.
// but if the lower bound of the next range is larger than current point, a new point is needed.

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
