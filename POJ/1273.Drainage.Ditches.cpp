#include <cstdio>
#include <queue>
#include <cstring>

const int MAXM = 205;
int a[MAXM][MAXM] = {};
int N, M;
int path[MAXM];
int flow[MAXM];

int bfs() {
    std::queue<int >q;
    memset(path, -1, sizeof(path));
    path[1] = 0;
    flow[1] = 10000000;
    q.push(1);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        if (t == M) break;
        for (int i = 1; i <= M; i++) {
            if (path[i] == -1 && a[t][i]) {
                flow[i] = flow[t] < a[t][i] ? flow[t] : a[t][i];  
                q.push(i);
                path[i] = t;
            }
        }
    }
    if (path[M] == -1) return 0;
    else return flow[M];
}

int E_P() {
    int ans = 0;
    int bfs_res = 0;
    while (true) {
        bfs_res = bfs();
        if (bfs_res <= 0) break;
        ans += bfs_res;
        int cur = M;
        while (cur != 1) {
            int pre = path[cur];
            a[pre][cur] -= bfs_res;
            a[cur][pre] += bfs_res;
            cur = pre;
        }
    }
    return ans;
}

int main() {
    while (scanf("%d%d", &N, &M) != EOF) {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < N; i++) {
            int s, t, v;
            scanf("%d%d%d", &s, &t, &v);
            a[s][t] += v;
        }
        printf("%d\n", E_P());
    }
    return 0;
}
