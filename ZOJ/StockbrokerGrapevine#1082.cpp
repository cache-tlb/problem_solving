#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

const int MAXN = 128;
const int INF = 0x3f3f3f3f;

typedef pair<int,int> pii;

bool operator < (const pii &a, const pii &b){
    return (a.first > b.first) || (a.first == b.first && a.second > b.second);
}

pii adj[MAXN][MAXN] = {};
int nNeighbor[MAXN] = {};
int dis[MAXN] = {};
int N;

void BFS(int index){
    for(int i = 0; i < N; i++){
        dis[i] = INF;
    }
    dis[index] = 0;
    priority_queue<pii> pq; // (id, dist)
    pq.push(pii(index, 0));
    while(!pq.empty()) {
        int id = pq.top().first, cur_dist = pq.top().second;
        pq.pop();
        if(cur_dist > dis[id]) continue;
        for(int i = 0; i < nNeighbor[id]; i++){
            int next = adj[id][i].first, len = adj[id][i].second;
            int new_dis = len + cur_dist;
            if(new_dis < dis[next]){
                pq.push(pii(next, new_dis));
                dis[next] = new_dis;
            }
        }
    }
}

void process() {
    int min_dia = INF;
    int pos = -1;
    for(int k = 0; k < N; k++){
        BFS(k);
        int max_dis = 0;
        for(int i = 0; i < N; i++){
            if(dis[i] > max_dis) max_dis = dis[i];
        }
        if(max_dis < min_dia){
            min_dia = max_dis;
            pos = k;
        }
    }
    if(pos != -1){
        printf("%d %d\n", pos + 1, min_dia);
    }
    else{
        printf("disjoint\n");
    }
}

int main(int argc, char const *argv[])
{
    while(scanf("%d", &N) != EOF) {
        if(!N) break;
        for(int i = 0; i < N; i++){
            int m;
            scanf("%d", &m);
            nNeighbor[i] = m;
            for (int j = 0; j < m; j++) {
                int x, d;
                scanf("%d%d", &x, &d);
                adj[i][j] = pii(x - 1, d);
            }
        }
        process();
    }
    return 0;
}
