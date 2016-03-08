#include <cstdio>
#include <cmath>

int fee(double flag_down, double per, double per10, double wait, double wait_gap, double surcharge, int d, int t) {
    double total = flag_down;
    if (d > 3 && d <= 10) {
        total += per * (d - 3);
    } else if (d > 10) {
        total += per * (10 - 3) + per10 * ceil(d - 10);
    }
    total += wait * (double(t) / wait_gap);
    total += surcharge;
    return int(total + 0.5);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int d, t;
        scanf("%d%d", &d, &t);
        printf("%d\n", - fee(10, 2, 3, 2, 5, 1, d, t) + fee(11, 2.5, 3.75, 2.5, 4, 0, d, t));
    }
    return 0;
}
