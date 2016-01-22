#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 512;

int sum[MAXN] = {};
int cnt[MAXN] = {};

int main(int argc, char const *argv[])
{
    int n;
    for(int i = 1; i < MAXN; i++){
        sum[i] = i + sum[i-1];
    }
    while(scanf("%d",&n) != EOF){
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans += sum[n-i+1];
            if(n-2*i+1>0){
                ans += sum[n-2*i+1];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
