// note: it's possible there is only one stick whose length is the sum of all sticks.

#include <cstdio>
#include <algorithm>
#include <cstring>

const int MAXN = 70;
int a[MAXN] = {};
int visit[MAXN] = {};
int n;
int s = 0;
int unit;
bool search(int cur_len, int remain_stick, int max_index) {
    /*for (int i = 0; i < n; i++) {
        printf("%d ", visit[i]);
    }
    printf("; unit: %d cur_len: %d, remain_stick: %d, max_index: %d\n", unit, cur_len, remain_stick, max_index);*/
    if (cur_len == unit) {
        if (remain_stick == 1) return true;
        return search(0, remain_stick - 1, n - 1);
    }
    for (int i = max_index; i >= 0; i--) {
        if (visit[i]) continue;
        if (a[i] > unit) return false;
        if (cur_len + a[i] > unit) continue;
        visit[i] = 1;
        bool res = search(cur_len + a[i], remain_stick, i - 1);
        if (res) return true;
        visit[i] = 0;
        if (cur_len == 0 && !res) return false;
        int tmp = a[i];
        while (i - 1 >= 0 && a[i-1] == tmp) {
            i--;
        }
    }
    return false;
}

bool is_ok(int f) {
    int k = s / f;
    memset(visit, 0, sizeof(visit));
    unit = f;
    return search(0, k, n - 1);
}

int main() {
    while (scanf("%d", &n) != EOF) {
        if (!n) break;
        s = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            s += a[i];
        }
        std::sort(a, a + n);
        for (int trial = a[n-1]; trial <= s; trial++) {
            if (s % trial != 0) continue;
            if (is_ok(trial)) {
                printf("%d\n", trial);
                break;
            }
        }
    }
    return 0;
}
