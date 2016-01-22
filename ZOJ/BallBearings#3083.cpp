#include <cstdio>
#include <cmath>

using namespace std;

#define PI 3.14159265358979323

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);
    while(t--) {
        double D, d, s;
        scanf("%lf%lf%lf", &D, &d, &s);
        double R = (D - d) / 2.0;
        double l = (d + s) / 2.0;
        double ang = asin(l / R);
        int n = int(PI / ang);
        printf("%d\n", n);
    }
    return 0;
}
