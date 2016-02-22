#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 52;
const int MAXM = 52;
const int MAXK = MAXM * MAXN;

double cache[MAXM][MAXN][MAXK];
int m, n;



int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &m, &n);
        memset(cache, 0, sizeof (cache));
        cache[1][1][1] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= i*j; k++) {
                    /*if (k == i*j) {
                        cache[i][j][k] = 1;
                        continue;
                    }*/
                    if (i == 1 && j == 1 && k == 1) continue;
                    double denorm = (m*n - (k-1));
                    double s1 = cache[i-1][j-1][k-1] * (m - (i-1)) * (n - (j-1)) / denorm;
                    double s2 = cache[i][j][k-1] * (i*j - (k-1)) / denorm;
                    double s3 = cache[i-1][j][k-1] * j * (m - (i-1)) / denorm;
                    double s4 = cache[i][j-1][k-1] * i * (n - (j-1)) / denorm;
                    cache[i][j][k] = s1 + s2 + s3 + s4;
                }
            }
        }
        /*for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= i*j; k++) {
                    printf("%lf ", cache[i][j][k]);
                }
                printf("\n");
            }
            printf("\n");
        }*/
        double s = 0;
        for (int k = 1; k <= m*n; k++) {
            s += k*(cache[m][n][k] - cache[m][n][k-1]);
        }
        printf("%.12lf\n", s);

    }
    return 0;
}
