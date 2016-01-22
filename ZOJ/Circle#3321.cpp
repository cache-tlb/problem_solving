#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 12;

int n, m;

int main(int argc, char const *argv[])
{
    while(scanf("%d%d", &n, &m) != EOF) {
        std::vector<int> adj[MAXN];
        int degree[MAXN] = {};
        for(int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        if(m != n || m <= 2) {
            printf("NO\n");
            continue;
        }
        bool ok = true;
        for(int i = 1; i <= n; i++) {
            if(degree[i] != 2) {
                ok = false;
                break;
            }
        }
        if(!ok) {
            printf("NO\n");
            continue;
        }
        queue<int> q;
        bool vis[MAXN] = {};
        vis[1] = true;
        q.push(1);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            vis[cur] = 1;
            std::vector<int> &vec = adj[cur];
            for(int i = 0; i < vec.size(); i++) {
                if(vis[vec[i]]) continue;
                vis[vec[i]] = 1;
                q.push(vec[i]);
            }
        }
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) {
                ok = false;
                break;
            }
        }
        if(!ok) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
