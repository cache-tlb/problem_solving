#include <iostream>
#include <cstdio>
#include <set>
#include <cstdlib>
#include <climits>

using namespace std;

// Prim algorithm

typedef pair<int,int> edge;

const int MAXN = 64;

int dis[MAXN][MAXN] = {};

int n;

int process(){
    set<int> S, T;
    S.insert(1);
    for(int i = 2; i <= n; i++){
        T.insert(i);
    }
    int sum = 0;
    while(!T.empty()){
        int min_len = INT_MAX;
        int index = -1;
        for(set<int>::iterator it1 = S.begin(); it1 != S.end(); it1++){
            for(set<int>::iterator it2 = T.begin(); it2 != T.end(); it2++){
                if(dis[*it1][*it2] < min_len){
                    min_len = dis[*it1][*it2];
                    index = *it2;
                }
            }
        }
        S.insert(index);
        T.erase(index);
        sum += min_len;
    }
    return sum;
}

int main()
{
    while(scanf("%d", &n)){
        if(!n) break;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dis[i][j] = INT_MAX;
            }
        }
        int m;
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            int a, b, d;
            scanf("%d%d%d", &a, &b, &d);
            dis[a][b] = min(dis[a][b], d);
            dis[b][a] = min(dis[b][a], d);
        }
        printf("%d\n", process());
    }
    return 0;
}
