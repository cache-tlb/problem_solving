#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
const int MAXVAL = 536870912;
int a[MAXN] = {};
int N;
bool ok;
int process() {
    for(int i = N - 1; i >= 0; i--) {
        for(int j = N - 1; j >= 0; j--) {
            if(j == i) continue;
            for(int k = N - 1; k >= 0; k--){
                if(k == j || k == i) continue;
                int val = a[i] - a[j] - a[k];
                if(val == a[i] || val == a[j] || val == a[k]) continue;
                if(binary_search(a, a + N, a[i] - a[j] - a[k])){
                    ok = true;
                    return a[i];
                }
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    while(scanf("%d", &N)) {
        if(!N) break;
        for(int i = 0; i < N; i++) {
            scanf("%d", &a[i]);
        }
        if(N < 4){
            printf("no solution\n");
            continue;
        }
        sort(a, a + N);
        ok = false;
        int ans = process();
        if(ok){
            printf("%d\n", ans);
        }
        else{
            printf("no solution\n");
        }
    }
    return 0;
}
