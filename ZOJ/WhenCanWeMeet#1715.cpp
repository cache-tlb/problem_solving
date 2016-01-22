#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, Q;
    while(scanf("%d%d", &N, &Q) != EOF) {
        if(!N && !Q) break;
        map<int,int> mp;
        for(int i = 0; i < N; i++) {
            int m;
            scanf("%d", &m);
            while(m--){
                int day;
                scanf("%d", &day);
                mp[day]++;
            }
        }
        int maxv = -1, pos = -1;;
        for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++){
            if(it->second > maxv){
                pos = it->first;
                maxv = it->second;
            }
        }
        if(maxv < Q) {
            printf("0\n");
        }
        else{
            printf("%d\n", pos);
        }
    }
    return 0;
}
