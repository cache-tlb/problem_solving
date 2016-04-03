#include <cstdio>
#include <cmath>

const double pi = 3.14159263858979323;

int main() {
    int t;
    scanf("%d", &t);
    for (int k = 1; k <= t; k++) {
        double x, y;
        scanf("%lf%lf", &x, &y);
        double d2 = x*x + y*y;
        double area = pi*d2/2.;
        int  ans = ceil(area / 50);
        printf("Property %d: This property will begin eroding in year %d.\n", k, ans);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
