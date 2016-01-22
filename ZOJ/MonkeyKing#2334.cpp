#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 131072;

struct node {
    int strength, id;
    node(){}
    node(int s, int i){strength=s;id=i;}
};

bool operator < (const node &a, const node &b){
    return (a.strength < b.strength) || (a.strength == b.strength && a.id < b.id);
}

priority_queue<node> pq[MAXN];
int group[MAXN];

int main(int argc, char const *argv[])
{
    int N;
    while(scanf("%d", &N) != EOF){
        for(int i = 0; i < N; i++) {
            while(!pq[i].empty())
                pq[i].pop();
        }
        for(int i = 0; i < N; i++){
            int strength;
            scanf("%d", &strength);
            group[i] = i;
            pq[i].push(node(strength, i));
        }
        int M;
        scanf("%d",&M);
        while(M--){
            int a, b;
            scanf("%d%d", &a, &b);
            a--; b--;
            int ga = group[a], gb = group[b];
            if(ga==gb) printf("-1\n");
            else{
                node sa = pq[ga].top(), sb = pq[gb].top();
                pq[ga].pop();pq[gb].pop();
                sa.strength /= 2;
                sb.strength /= 2;
                int ans = 0;
                if(pq[ga].size() > pq[gb].size()){
                    while(!pq[gb].empty()){
                        node n = pq[gb].top();
                        pq[gb].pop();
                        pq[ga].push(n);
                        group[n.id] = ga;
                    }
                    pq[ga].push(sa);
                    group[sb.id] = ga;
                    pq[ga].push(sb);
                    ans = pq[ga].top().strength;
                }
                else{
                    while(!pq[ga].empty()){
                        node n = pq[ga].top();
                        pq[ga].pop();
                        pq[gb].push(n);
                        group[n.id] = gb;
                    }
                    pq[gb].push(sb);
                    group[sa.id] = gb;
                    pq[gb].push(sa);
                    ans = pq[gb].top().strength;
                }
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
