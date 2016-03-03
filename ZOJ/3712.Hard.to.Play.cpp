#include <cstdio>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int A, B, C;
        scanf("%d%d%d", &A, &B, &C);
        int high = 0, low = 0;
        for (int i = 0; i < A; i++) {
            low += 300*(i*2 + 1);
        }
        for (int i = A; i < A + B; i++) {
            low += 100*(i*2 + 1);
        }
        for (int i = A + B; i < A + B + C; i++) {
            low += 50*(i*2 + 1);
        }
        for (int i = 0; i < C; i++) {
            high += 50*(i*2 + 1);
        }
        for (int i = C; i < C + B; i++) {
            high += 100*(i*2 + 1);
        }
        for (int i = C + B; i < C + B + A; i++) {
            high += 300*(i*2 + 1);
        }
        printf("%d %d\n", low, high);
    }
    return 0;
}
