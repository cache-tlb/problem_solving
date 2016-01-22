#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

map<string, int> name2index;

const int MAXN = 10010;
const string erdos_name = "Erdos, P.";
int paper, nquery;
set<int> co_author[MAXN];
int erdos_num[MAXN];

void clean() {
    int N = name2index.size();
    for(int i = 0; i < N; i++){
        co_author[i].clear();
    }
}

void bfs() {
    int N = name2index.size();
    memset(erdos_num, -1, N*sizeof(int));
    queue<int> q;
    if(name2index.count(erdos_name) <= 0) return;
    int index = name2index[erdos_name];
    q.push(index);
    erdos_num[index] = 0;
    while(!q.empty()) {
        index = q.front();
        q.pop();
        int dis = erdos_num[index];
        for(set<int>::iterator it = co_author[index].begin(); it != co_author[index].end(); it++) {
            if(erdos_num[*it] == -1){
                erdos_num[*it] = dis + 1;
                q.push(*it);
            }
        }
    }
}

char buf[1024];

int main(int argc, char const *argv[])
{
    string first_name, last_name;
    string line;
    int t = 0;
    while(scanf("%d%d", &paper, &nquery) != EOF) {
        if(!paper && !nquery) break;
        clean();
        name2index.clear();
        while(paper--){
            vector<int> indices;
            while(1){
                scanf("%s", buf); first_name = buf;
                scanf("%s", buf); last_name = buf;
                int llen = last_name.length();
                string name = first_name + " " + last_name.substr(0, llen - 1);
                if(name2index.count(name) <= 0){
                    int tmp = name2index.size();
                    indices.push_back(tmp);
                    name2index[name] = tmp;
                }
                else{
                    indices.push_back(name2index[name]);
                }
                if(last_name[llen - 1]==':' || last_name[llen - 1] == '.') break;
            }
            gets(buf);
            int n_au = indices.size();
            for(int i = 0; i < n_au; i++) {
                for(int j = i + 1; j < n_au; j++) {
                    int a = indices[i], b = indices[j];
                    co_author[a].insert(b);
                    co_author[b].insert(a);
                }
            }
        }
        bfs();
        printf("Database #%d\n", ++t);
        while(nquery--) {
            gets(buf);
            line = buf;
            printf("%s: ", line.c_str());
            if(name2index.count(line) <= 0){
                printf("infinity\n");
                continue;
            }
            int index = name2index[line];
            if(erdos_num[index] >= 0)
                printf("%d\n", erdos_num[index]);
            else
                printf("infinity\n");
        }
        printf("\n");
    }
    return 0;
}
