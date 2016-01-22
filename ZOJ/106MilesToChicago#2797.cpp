#include <iostream>
#include <cstdio>
#include <list>
#include <cstring>
#include <queue>
#include <cmath>
#include <utility>

// variant dijkstra

const int MAXN = 128;

using namespace std;

list<pair<int,double> > adj[MAXN];
double max_pro[MAXN];
int vis[MAXN];

int m,n;

void dij()
{
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++){
        max_pro[i] = 0;
    }
    max_pro[1] = 1.0;
    while(1){
        double mp = 0.0;
        int index = 0;
        for(int i = 1; i <= n; i++){
            if(!vis[i] && max_pro[i] > mp){
                mp = max_pro[i];
                index = i;
            }
        }
        if(mp==0.0) return;
        vis[index] = 1;
        if(index==n) return;
        for(list<pair<int,double> >::iterator it = adj[index].begin(); it != adj[index].end(); it++){
            int new_index = it->first;
            double new_pro = it->second * mp;
            if(!vis[new_index] && new_pro > max_pro[new_index]){
                max_pro[new_index] = new_pro;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    while(cin >> n){
        if(!n) break;
        cin >> m;
        for(int i = 1; i <= n; i++){
            adj[i].clear();
        }

        for(int i = 0; i < m; i++){
            int a, b, p;
            cin >> a >> b >> p;
            double pro = (double)p/100.0;
            adj[a].push_back(pair<int,double>(b,pro));
            adj[b].push_back(pair<int,double>(a,pro));
        }
        dij();
        double pro = max_pro[n];
        printf("%.6lf percent\n", pro*100.0);
    }
    return 0;
}
