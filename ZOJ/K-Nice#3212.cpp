#include <cstdio>

using namespace std;

const int MAXN = 16;

int mat[MAXN][MAXN] = {};

void construct (int n, int m, int k) {
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) mat[i][j] = 1;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (!k) return;
            mat[i][j] = 0;
            mat[i - 1][j] = 0;
            mat[i + 1][j] = 0;
            mat[i][j - 1] = 0;
            mat[i][j + 1] = 0;
            k--;
        }
    }
}

int main(int argc, char const *argv[])
{
    int t, m, n, k;
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d%d%d", &n, &m, &k);
        construct(n, m, k);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d", mat[i][j]);
                if (j == m - 1) printf("\n");
                else printf(" ");
            }
        }
    }
    return 0;
}
