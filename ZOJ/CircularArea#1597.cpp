#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps = 1e-8;
const double pi = 3.1415926535897932;

inline double sqr (double x) {
    return x * x;
}

inline double getSine (double cosX) {
    return sqrt (1.0 - sqr(cosX));
}

int main(int argc, char const *argv[])
{
    double x1, y1, r1, x2, y2, r2;
    while (scanf ("%lf%lf%lf%lf%lf%lf", &x1, &y1, &r1, &x2, &y2, &r2) != EOF) {
        double d2 = sqr (x1 - x2) + sqr (y1 - y2);
        double d = sqrt (d2);
        if (r1 + r2 < d + eps) {
            printf("0.000\n");
            continue;
        }
        if (r1 < r2) swap (r1, r2);
        if (r2 + d < r1 + eps) {
            printf("%.3lf\n", pi * sqr (r2));
            continue;
        }
        double cosA = (sqr (r1) + d2 - sqr (r2)) / (2.0 * d * r1);
        double cosB = (sqr (r2) + d2 - sqr (r1)) / (2.0 * d * r2);
        double sinA = getSine (cosA), sinB = getSine (cosB);
        double A = acos (cosA), B = acos (cosB);
        double st1 = sqr (r1) * cosA * sinA, st2 = sqr (r2) * cosB * sinB;
        double sf1 = sqr (r1) * A, sf2 = sqr (r2) * B;
        printf("%.3lf\n", sf1 + sf2 - st1 - st2);
    }
    return 0;
}
