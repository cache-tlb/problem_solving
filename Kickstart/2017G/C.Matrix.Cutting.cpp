#include <iostream>
#include <cstdio>

using namespace std;

bool vis[128];
int red[128], blue[128];
long long dist[128][128];
long long len[128];


int main()
{
    freopen ("B-large.in", "r", stdin);
    freopen ("B-large.out", "w", stdout);
    int n, times;
    long long ans;
    int cur;
    scanf("%d", &times);
    for(int iter = 1; iter <= times; ++iter)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &red[i]);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &blue[i]);
        for(int i = 1; i <= n; ++i)
            for(int j = i; j <= n; ++j)
            {
                if (i == j)
                {
                    dist[i][j] = 0;
                    continue;
                }
                long long s1 = blue[i] ^ red[j];
                long long s2 = blue[j] ^ red[i];
                if (s1 < s2)
                    dist[i][j] = dist[j][i] = s1;
                else
                    dist[i][j] = dist[j][i] = s2;
            }
        /*for(int i = 1; i <= n; ++i)
        {
            for(int j = i; j <= n; ++j)
                cout << dist[i][j] << " ";
            cout << endl;
        }*/
        for(int i = 1; i <= n; ++i)
            len[i] = 1000000000000;
        for(int i = 1; i <= n; ++i)
            vis[i] = false;
        len[1] = 0;
        cur = 1;
        vis[1] = true;
        ans = 0;
        for(int k = 1; k < n; ++k)
        {
            for(int i = 1; i <= n; ++i)
                if (len[i] > dist[cur][i])
                    len[i] = dist[cur][i];
            long long max_len = 10000000000000;
            for(int i = 1; i <= n; ++i)
            {
                if (!vis[i] && len[i] < max_len)
                {
                    max_len = len[i];
                    cur = i;
                }
            }
            vis[cur] = true;
            ans += len[cur];
        }
        printf("Case #%d: %lld\n", iter, ans);
    }
    return 0;
}
