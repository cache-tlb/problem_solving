#include <cstdio>
#include <iostream>
#include <list>
#include <queue>
#include <set>
using namespace std;

const int MAXN = 1024;
list<int> adj[MAXN];
set<int> nodes;

int bfs(int center) {
    int visit[MAXN] = {};
    int cnt = 0;
    for(set<int>::iterator it = nodes.begin(); it != nodes.end(); it++) {
        if(*it == center || visit[*it]) continue;
        cnt++;
        queue<int> q;
        q.push(*it);
        while(!q.empty()) {
            int id = q.front();
            visit[id] = 1;
            q.pop();
            for(list<int>::iterator lit = adj[id].begin(); lit != adj[id].end(); lit++) {
                if(*lit == center || visit[*lit]) continue;
                q.push(*lit);
            }
        }
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    int a, b;
    int t = 0;
    while(scanf("%d", &a) != EOF){
        if(!a) break;
        if(t) printf("\n");
        for(int i = 0; i < MAXN; i++) {
            adj[i].clear();
        }
        nodes.clear();
        while(a) {
            scanf("%d", &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
            nodes.insert(a);
            nodes.insert(b);
            scanf("%d", &a);
        }
        printf("Network #%d\n", ++t);
        bool ok = false;
        for(set<int>::iterator it = nodes.begin(); it != nodes.end(); it++){
            int subnum = bfs(*it);
            if(subnum > 1) {
                ok = true;
                printf("  SPF node %d leaves %d subnets\n", *it, subnum);
            }
        }
        if(!ok) printf("  No SPF nodes\n");
    }
    return 0;
}
