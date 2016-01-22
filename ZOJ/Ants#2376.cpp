#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAXV = 1000011;

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    while(T--){
        int n, len;
        scanf("%d%d", &len, &n);
        int max_time = 0, min_time = 0, pos;
        for(int i = 0; i < n; i++) {
            scanf("%d", &pos);
            max_time = max(max_time, max(pos, len - pos));
            min_time = max(min_time, min(pos, len - pos));
        }
        printf("%d %d\n", min_time, max_time);
    }
    return 0;
}

