#include <cstdio>
#include <cmath>

using namespace std;

inline int cubic (int x) { return x * x * x; }
inline int tetrahedral (int x) { return x * (x + 1) * (x + 2) / 6; }

int process (int n) {
    int k = 0, x = 0, maxv = 0;
    while(x <= n) {
        int root = (int)pow((double)(n - x), 1.0/3.0);
        int tmp = cubic (root);
        if (tmp > n - x) {
            root--;
            tmp = cubic (root);
        }
        else if (cubic (root + 1) <= n - x) {
            root++;
            tmp = cubic (root);
        }
        maxv = maxv > tmp + x ? maxv : tmp + x;
        k++;
        x = tetrahedral (k);
    }
    return maxv;
}

int main (int argc, char const *argv[])
{
    int n;
    while (scanf ("%d", &n) != EOF && n) {
        printf ("%d\n", process (n));
    }
    return 0;
}
