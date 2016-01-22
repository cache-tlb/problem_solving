#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

struct Node {
    int remaind;
    string num;
    Node(){
        remaind = 0;
        num = "";
    }
};

const int MAXN = 5005;
int visit[MAXN] = {};
int valid_digit[128] = {};
int N, M;

void DFS() {
    memset(visit, 0, sizeof(visit));
    queue<Node> q;
    for(int i = 0; i < M; i++){
        if(valid_digit[i]){
            Node node;
            node.remaind = valid_digit[i] % N;
            if(!visit[node.remaind]) {
                node.num.push_back('0' + valid_digit[i]);
                visit[node.remaind] = 1;
                q.push(node);
            }
        }
    }
    while(!q.empty()){
        Node node = q.front();
        q.pop();
        if(node.remaind == 0){
            printf("%s\n", node.num.c_str());
            return;
        }
        for(int i = 0; i < M; i++){
            Node new_node;
            new_node.remaind = (node.remaind*10 + valid_digit[i]) % N;
            if(!visit[new_node.remaind]) {
                visit[new_node.remaind] = 1;
                new_node.num = node.num;
                new_node.num.push_back('0' + valid_digit[i]);
                q.push(new_node);
            }
        }
    }
    printf("0\n");
}

int main(int argc, char const *argv[])
{
    while(scanf("%d", &N) != EOF) {
        scanf("%d", &M);
        for(int i = 0; i < M; i++) {
            scanf("%d", &valid_digit[i]);
        }
        if(N==0) {
            printf("0\n");
            continue;
        }
        sort(valid_digit, valid_digit + M);
        DFS();
    }
    return 0;
}
