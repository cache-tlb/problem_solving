#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

struct task {
    int id, sum, delta;
    task(){}
    task(int i, int s, int d){id=i;sum=s;delta=d;}
};

bool operator < (const task& a, const task &b){
    return (a.sum > b.sum) || (a.sum == b.sum && a.id > b.id);
}

char line[1024];
char reg[20];

int main(int argc, char const *argv[])
{
    priority_queue<task> pq;
    while(gets(line)){
        if(line[0]=='#') break;
        int delta, id;
        sscanf(line, "%s%d%d", reg, &id, &delta);
        pq.push(task(id, delta, delta));
    }
    int k;
    scanf("%d", &k);
    while(k--){
        task t = pq.top();
        printf("%d\n", t.id);
        pq.pop();
        pq.push(task(t.id, t.sum + t.delta, t.delta));
    }
    return 0;
}
