#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 100011;
const int MAXK = 256;
const int mod = 1000000007;
int cache[MAXN];

int s1, s2, s, k;
int vol[MAXK];

int main(int argc, char const *argv[])
{

    while(scanf("%d%d", &s1, &s2) != EOF) {
        scanf("%d", &k);
        for(int i = 0; i < k; i++) {
            scanf("%d", &vol[i]);
        }
        s = min(s1,s2);
        memset(cache, 0, sizeof(cache));
        cache[0] = 1;
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += vol[i];
            if(sum > s) sum = s;
            if(vol[i] % 2) {
                for(int j = sum; j >= vol[i]; j--) {
                    cache[j] += cache[j - vol[i]];
                    if(cache[j] >= mod) cache[j] -= mod;
                }
            }
            else {
                int tmp = vol[i] / 2;
                for(int j = sum; j >= tmp; j--) {
                    if(j >= vol[i]){
                        cache[j] += cache[j - vol[i]];
                        if(cache[j] >= mod) cache[j] -= mod;
                    }
                    cache[j] += cache[j - tmp];
                    if(cache[j] >= mod) cache[j] -= mod;
                }
            }
        }
        int ans = cache[s];
        printf("%d\n", ans);
    }
    return 0;
}
