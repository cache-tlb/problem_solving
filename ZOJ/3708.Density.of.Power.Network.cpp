#include <cstdio>
#include <set>
#include <algorithm>

const int MAXN = 502;
int start[MAXN], end[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, M;
        scanf("%d%d", &N, &M);
        for (int i = 0; i < M; i++) {
            scanf("%d", &start[i]);
        }
        for (int i = 0; i < M; i++) {
            scanf("%d", &end[i]);
        }
        std::set<int> trans;
        for (int i = 0; i < M; i++) {
            int a = std::max(start[i], end[i]);
            int b = std::min(start[i], end[i]);
            if (a == b) continue;
            trans.insert((a<<10) + b);
        }
        printf("%.3lf\n", double(trans.size()) / double(N));
    }
}
