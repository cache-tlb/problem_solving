/*#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

const int MAXN = 310;

int a[MAXN];
int vis[MAXN];
std::vector<double> log_fact;
double c[MAXN][MAXN];
std::vector<double> cache1, cache2;

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    cache1.resize(MAXN);
    cache2.resize(MAXN);
    log_fact.resize(MAXN, 0.0);
    double tmp = 0.0;
    for (int i = 2; i < MAXN; i++) {
        tmp += log(double(i));
        log_fact[i] = tmp;
    }
    for (int i = 0; i < MAXN; i++) {
        c[i][0] = 1;
        c[i][i] = 1;
        for (int j = 1; j <= i - 1; j++) {
            c[i][j] = c[i-1][j] + c[i-1][j-1];
        }
    }
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        memset(vis, 0, (n+1)*sizeof(int));
        std::vector<int> ns;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            int count = 1;
            int cur = a[i];
            vis[i] = 1;
            while (cur != i) {
                vis[cur] = 1;
                cur = a[cur];
                count++;
            }
            ns.push_back(count);
        }
        if (k < ns.size()) {
            printf("0.000000000\n");
            continue;
        }
        for (int kk = 1; kk <= k; kk++) {
            if (kk > ns[0]) cache1[kk] = 0;
            else cache1[kk] = c[ns[0]][kk];
        }
        for (int i = 1; i <= k; i++) {
            // printf("%llf ", cache1[i]);
        }
        // printf("\n");
        int cur_n = ns[0];
        for (int m = 2; m <= ns.size(); m++) {
            int last_n = cur_n;
            cur_n += ns[m-1];
            int n1 = last_n, n2 = ns[m-1];
            for (int kk = 1; kk < m; kk++) {
                cache2[kk] = 0;
            }
            for (int kk = m; kk <= k; kk++) {
                if (kk > cur_n) {
                    cache2[kk] = 0;
                    continue;
                }
                double s = 0;
                int lo = std::max(1, kk - n2);
                lo = std::max(lo, m-1);
                int hi = std::min(kk-1, n1);
                for (int i = lo; i <= hi; i++) {
                    if (cache1[i] < 0.000001) continue;
                    // s += exp((log_fact[n1]-log_fact[i]-log_fact[n1-i])+(log_fact[n2]-log_fact[kk-i]-log_fact[n2-kk+i])-(log_fact[n1+n2]-log_fact[kk]-log_fact[n1+n2-kk])) * cache1[kk-i];
                    // s +=  c[n1][i]*c[n2][kk-i]/c[n1+n2][kk] * cache1[i];
                    s += cache1[i]*c[n2][kk-i];
                }
                cache2[kk] = s;
            }
            cache1.swap(cache2);
            for (int i = 1; i <= k; i++) {
                // printf("%llf ", cache1[i]);
            }
            // printf("\n");
        }
        printf("%.9llf\n", cache1[k]/c[n][k]);
    }
    return 0;
}
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include "string.h"
using namespace std;

int main()
{
    int t;
    cin >> t;

    vector<vector<double>>c(301, vector<double>(301));
    for (int i = 0; i <= 300; i++)
    {
        c[i][0] = c[i][i] = 1.0;
        for (int j = 1; j < i; j++)
            c[i][j] = c[i - 1][j - 1] + c[i-1][j];
    }
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int *box;
        int *visit;
        box = new int[n + 1];
        visit = new int[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> box[i];
            visit[i] = 0;
        }
        vector<int> count;
        for (int i = 1; i <= n; i++)
        {
            int sum = 0;
            int tmp = i;
            while (visit[tmp] == 0)
            {
                visit[tmp] = 1;
                tmp = box[tmp];
                sum++;
            }
            if (sum!=0)
                count.push_back(sum);
        }
        int ring_num = count.size();
        if (ring_num > k)
        {
            cout << "0.000000000" << endl;
            continue;
        }
        vector<vector<double>>dp(301, vector<double>(301));
        dp[0][0] = 1.0;

        for (int i = 0; i < ring_num; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (fabs(dp[i][j]) > 0.000001)
                {
                    for (int l = 1; l <= count[i]&&j+l<=k; l++)
                        dp[i + 1][j + l] += dp[i][j] * c[count[i]][l];
                }
            }
        }
        printf("%.9f\n", dp[ring_num][k] / c[n][k]);
        //cout << setprecision(9) << dp[ring_num][k] / c[n][k] << endl;

    }
    system("pause");
    return 0;
}

