#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 128;
char line[MAXN];
int res[MAXN];

int main(int argc, char const *argv[]) {
    int t;
    scanf("%d", &t);
    while(t--){
        memset(res, 0, sizeof(res));
        while(scanf("%s", line) != EOF){
            int n = strlen(line);
            if(n==1 && line[0]=='0') break;
            for(int i = 0; i < n; i++){
                int num = line[n-1-i] - '0';
                res[i] += num;
            }
        }
        for(int i = 0; i < MAXN-1; i++){
            res[i+1] += res[i]/10;
            res[i] %= 10;
        }
        for(int i = MAXN-1; i >= 0; i--){
            if(res[i] != 0){
                for(; i >= 0; i--){
                    printf("%d", res[i]);
                }
            }
        }
        printf("\n");
        if(t) printf("\n");
    }
    return 0;
}
