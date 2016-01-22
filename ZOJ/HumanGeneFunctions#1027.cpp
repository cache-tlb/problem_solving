#include <cstdio>
#include <cstring>

using namespace std;

/*
    A   C   G   T  SP
A   5  -1  -2  -1  -3
C  -1   5  -3  -2  -4
G  -2  -3   5  -2  -2
T  -1  -2  -2   5  -1
sp -3  -4  -2  -1 -INF
*/

const int INF = 0x3f3f3f3f;
const int MAXN = 128;
char buf[MAXN];
int seq1[MAXN] = {}, seq2[MAXN] = {};
int table[MAXN][MAXN] = {};
int is_set[MAXN][MAXN] = {};
int len1, len2;

const int cost[5][5] = {
    {-INF, -3, -4, -2, -1},
    {-3, 5, -1, -2, -1},
    {-4, -1, 5, -3, -2},
    {-2, -2, -3, 5, -2},
    {-1, -1, -2, -2, 5}
};

int char2int(char c) {
    switch(c){
    case 'A':
        return 1;
    case 'C':
        return 2;
    case 'G':
        return 3;
    case 'T':
        return 4;
    default:
        return 0;
    }
}

inline int my_max(int a, int b) {
    return (a > b ? a : b);
}

int get_val(int s, int t) {
    if(is_set[s][t]) return table[s][t];
    if(s==len1) {
        int ret = 0;
        for(int i = t; i < len2; i++) {
            ret += cost[0][seq2[i]];
        }
        table[s][t] = ret;
        is_set[s][t] = 1;
        return ret;
    }
    else if(t==len2){
        int ret = 0;
        for(int i = s; i < len1; i++) {
            ret += cost[seq1[i]][0];
        }
        table[s][t] = ret;
        is_set[s][t] = 1;
        return ret;
    }
    else{
        int ret = 0;
        ret = my_max(get_val(s+1, t) + cost[seq1[s]][0], get_val(s, t+1) + cost[0][seq2[t]]);
        ret = my_max(ret, get_val(s+1,t+1) + cost[seq1[s]][seq2[t]]);
        table[s][t] = ret;
        is_set[s][t] = 1;
        return ret;
    }
}

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &len1);
        scanf("%s", buf);
        for(int i = 0; i < len1; i++){
            seq1[i] = char2int(buf[i]);
        }
        scanf("%d", &len2);
        scanf("%s", buf);
        for(int i = 0; i < len2; i++){
            seq2[i] = char2int(buf[i]);
        }
        memset(is_set, 0, sizeof(is_set));
        printf("%d\n", get_val(0,0));
    }
    return 0;
}
