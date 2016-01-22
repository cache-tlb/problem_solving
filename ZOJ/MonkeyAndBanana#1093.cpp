#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <list>
using namespace std;

// a simple topo-sort problem

struct Cube {
    int length, width, height;
    Cube(){}
    Cube(int l, int w, int h){length = max(l,w); width = min(l,w); height = h;}
};

bool operator < (const Cube &a, const Cube &b){
    return (a.length < b.length) || (a.length == b.length && a.width < b.width) || (a.length == b.length && a.width == b.width && a.height < b.height);
}

const int MAXN = 32;
const int MAXNODE = 4*MAXN;

Cube cubes[MAXNODE];
list<int> adj[MAXNODE];
map<Cube,int> visit;

int N;
int res;

bool contains(const Cube &a, const Cube &b){
    return (a.length > b.length) && (a.width > b.width);
}

int dfs(int k){
    map<Cube,int>::iterator it = visit.find(cubes[k]);
    if(it != visit.end()) return it->second;
    int max_child_height = 0;
    for(list<int>::iterator lit = adj[k].begin(); lit != adj[k].end(); lit++){
        int child = *lit;
        int height = dfs(child);
        if(height > max_child_height) max_child_height = height;
    }
    int height = max_child_height + cubes[k].height;
    visit[cubes[k]] = height;
    return height;
}

void process(){
    int nCube = N*3;
    for(int i = 0; i < nCube; i++){
        adj[i].clear();
        for(int j = 0; j < nCube; j++){
            if(contains(cubes[i], cubes[j])){
                adj[i].push_back(j);
            }
        }
    }
    visit.clear();
    res = 0;
    for(int i = 0; i < nCube; i++){
        if(visit.count(cubes[i]) > 0) continue;
        int temp = dfs(i);
        if(res < temp) res = temp;
    }
}

int main(int argc, char const *argv[])
{
    int t = 1;
    while(scanf("%d", &N) != EOF){
        if(!N) break;
        int a, b, c;
        int nCube = 0;
        for(int i = 0; i < N; i++){
            scanf("%d%d%d", &a, &b, &c);
            cubes[nCube++] = Cube(a,b,c);
            cubes[nCube++] = Cube(b,c,a);
            cubes[nCube++] = Cube(c,a,b);
        }
        process();
        printf("Case %d: maximum height = %d\n", t++, res);
    }

    return 0;
}
