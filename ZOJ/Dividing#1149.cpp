#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

const int MAXV = 300220;

int n[6];
int obj[MAXV];
int nObj = 0;
int cache[MAXV];

void split(int k, int v) {
    int tmp = 1;
    while(k > 0) {
        obj[nObj++] = min(k, tmp)*v;
        k -= tmp;
        tmp *= 2;
    }
}

bool process(){
    int sum = 0;
    for(int i = 0; i < 6; i++) {
        sum += (i+1)*n[i];
    }
    if(sum % 2) return false;
    memset(cache, 0, sizeof(cache));
    nObj = 0;
    for(int i = 0; i < 6; i++) {
        split(n[i], i + 1);
    }
    for(int i = 0; i < nObj; i++){
        for(int k = sum/2; k >= obj[i]; k--) {
            cache[k] = max(cache[k], cache[k - obj[i]] + obj[i]);
        }
    }
    return cache[sum/2] == sum/2;
}

int main(int argc, char const *argv[])
{
    int t = 0;
    while(scanf("%d%d%d%d%d%d", n, n + 1, n + 2, n + 3, n + 4, n + 5) != EOF){
        if(!n[0] && !n[1] && !n[2] && !n[3] && !n[4] && !n[5]) break;
        printf("Collection #%d:\n", ++t);
        if(process()) printf("Can be divided.\n");
        else printf("Can't be divided.\n");
        printf("\n");
    }
    return 0;
}
