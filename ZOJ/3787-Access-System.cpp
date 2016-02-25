#include <cstdio>
#include <algorithm>
#include <vector>

inline int hms2s(int h, int m, int s) {
    return (h*60 + m)*60 + s;
}

const int MAXN = 20000 + 3;

struct ST {
    int s, index;
};

bool cmp(const ST &a, const ST &b) {
    return (a.s < b.s) || (a.s == b.s && a.index < b.index);
}

ST st[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, L;
        scanf("%d %d", &n, &L);
        int h, m, s;
        for (int i = 0; i < n; i++) {
            scanf("%d:%d:%d", &h, &m, &s);
            st[i].index = i;
            st[i].s = hms2s(h, m, s);
        }
        std::sort(st, st + n, cmp);
        std::vector<int> candidates;
        int last_time = -L - 1;
        for (int i = 0; i < n; i++) {
            if (last_time + L > st[i].s) continue;
            last_time = st[i].s;
            candidates.push_back(st[i].index);
        }
        std::sort(candidates.begin(), candidates.end());
        printf("%d\n", candidates.size());
        for (int i = 0; i < candidates.size(); i++) {
            printf("%d", candidates[i] + 1);
            if (i != candidates.size() - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
