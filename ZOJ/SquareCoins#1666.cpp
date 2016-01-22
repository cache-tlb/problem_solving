#include <cstdio>

using namespace std;

const int coins[] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256, 289};
const int MAXN = 303;
const int MAXK = 17;
int cache[MAXK][MAXN];

int search(int i, int j) {
    if (cache[i][j] >= 0) return cache[i][j];
    if (i == 0 || j == 0) {
        cache[i][j] = 1;
        return 1;
    }
    int tot = 0;
    while (j >= 0) {
        tot += search(i - 1, j);
        j -= coins[i];
    }
    cache[i][j] = tot;
    return tot;
}

int main(int argc, char const *argv[])
{
    int n;
    while (scanf("%d", &n) != EOF && n) {
        for (int i = 0; i < MAXK; i++) {
            for (int j = 0; j < MAXN; j++) {
                cache[i][j] = -1;
            }
        }
        printf ("%d\n", search(MAXK - 1, n));
    }
    return 0;
}
