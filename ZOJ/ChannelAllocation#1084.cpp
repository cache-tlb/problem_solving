#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 27;
int adj[MAXN][MAXN] = {};
int visit[MAXN] = {};   //record color
int N;

bool dfs(int index, int color){
    if(index==N) return true;
    for(int i = 0; i < color; i++) {
        visit[index] = i;
        bool ok = true;
        for(int j = 0; j < index; j++){
            if(adj[j][index] && visit[j]==visit[index]){
                ok = false;
                break;
            }
        }
        if(ok && dfs(index+1,color)) return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    string line;
    while(cin >> N){
        if(!N) break;
        memset(adj, 0, sizeof(adj));
        bool one = true;
        for(int i = 0; i < N; i++){
            cin >> line;
            int index = line[0] - 'A';
            for(int j = 2; j < line.length(); j++){
                int nb = line[j] - 'A';
                adj[index][nb] = 1;
                adj[nb][index] = 1;
                one = false;
            }
        }
        visit[0] = 0;
        if(one){
            printf("1 channel needed.\n");
        }
        else if(dfs(1, 2)){
            printf("2 channels needed.\n");
        }
        else if(dfs(1, 3)){
            printf("3 channels needed.\n");
        }
        else{
            printf("4 channels needed.\n");
        }
    }
    return 0;
}
