#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int dp[N],pow[N]={1};

int main()
{
    int n,m;
    for(int i=1;i<N;i++)
        pow[i] = pow[i-1] * 2 % mod;
    while(~scanf("%d%d",&n,&m))
    {
        memset(dp,0,sizeof(int)*m);
        dp[m] = 1;
        for(int i=m+1;i<=n;i++)
            dp[i] = ((dp[i-1] * 2 % mod + pow[i-m-1] - dp[i-m-1]) % mod + mod) % mod;
        printf("%d\n",dp[n]);
    }
    return 0;
}
