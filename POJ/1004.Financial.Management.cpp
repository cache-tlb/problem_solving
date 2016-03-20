#include <cstdio>

int main() {
    double s;
    for (int i = 0; i < 12; i++) {
        double x;
        scanf("%lf", &x);
        s += x;
    }
    printf("$%.2lf\n", s/12.);
    return 0;
}
