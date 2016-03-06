#include <cstdio>

const int MAXN = 1005;

bool is_prime[MAXN];
int primes[MAXN];
int pdf[MAXN];

void init() {
    for (int i = 0; i < MAXN; i++) {
        is_prime[i] = true;
    }
    is_prime[0] = false;
    is_prime[1] = true;
    is_prime[2] = true;
    int cur = 2;
    while (cur < MAXN) {
        if (!is_prime[cur]) {
            cur++;
            continue;
        }
        int acc = cur + cur;
        while (acc < MAXN) {
            is_prime[acc] = false;
            acc += cur;
        }
        cur++;
    }
    int pc = 0;
    for (int i = 0; i < MAXN; i++) {
        if (is_prime[i]) {
            primes[pc] = i;
            pc++;
        }
        pdf[i] = pc;
    }
}

int main() {
    init();
    int N, C;
    while (scanf("%d%d", &N, &C) != EOF) {
        printf("%d %d:", N, C);
        int pivot = pdf[N] / 2;
        int start = pivot - C + 1, end = pivot + C - 1;
        if (pdf[N] % 2 == 0) {
            start = pivot - C;
        }
        if (start < 0) start = 0;
        if (end > pdf[N] - 1) end = pdf[N] - 1;
        for (int i = start; i <= end; i++) {
            printf(" %d", primes[i]);
        }
        printf("\n\n");
    }
    return 0;
}
