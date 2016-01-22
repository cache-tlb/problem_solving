#include <cstdio>
#include <cstring>
using namespace std;

const int limit = 10000000;

inline int sqr(int x) { return x*x; }

int digitSqrSum (int x) {
    int sum = 0;
    while (x) {
        sum += sqr(x%10);
        x /= 10;
    }
    return sum;
}

int cache[limit + 10];

int chain (int x) {
    if (cache[x] >= 0) return cache[x];
    cache[x] = chain(digitSqrSum(x));
    return cache[x];
}

int main(int argc, char const *argv[])
{
    int cnt = 0;
    memset(cache, -1, sizeof cache);
    cache[1] = 1;
    cache[89] = 89;
    for (int i = 1; i <= limit; i++) {
        if (chain(i)==89) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
