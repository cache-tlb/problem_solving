/*#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>
using namespace std;
const int MAXN = 500 + 5;
const int MAXM = 50000 + 5;
int n, m;
int bridge[MAXN][MAXN] = {};
int visit[MAXN] = {};
bool isconnect(int u,int v)
{
    memset(visit,0,sizeof(visit));
    vector<int> vi;
    vi.push_back(u);
    visit[u] = 1;
    int cur = 0;
    while(cur<vi.size()){
        int i = vi[cur];
        if(i==v) return true;
        for(int j = 1; j <= n; j++){
            if(bridge[i][j] && !visit[j] && j!=i){
                vi.push_back(j);
                visit[j] = 1;
            }
        }
        cur++;
    }
    return false;
}
int main()
{
    int round = 1;
    while(cin >> n>> m){
        memset(bridge,0,sizeof(bridge));
        char op;
        int u, v;
        printf("Case %d:\n", round);
        //cout << "m=" << m << " n=" << n << endl;
        while(m--){
            cin >> op >> u >> v;
            //cout << op <<  ' ' << u << ' ' << v << endl;
            if(op=='I'){
                bridge[u][v] = 1;
                bridge[v][u] = 1;
            }
            else if(op=='D'){
                bridge[u][v] = 0;
                bridge[v][u] = 0;
            }    
            else{
                if(isconnect(u,v)) printf("YES\n");
                else printf("NO\n");
            }
        }
        printf("\n");
        round++;
    }
    return 0;
}
*/
/*
解题：如果直接做这个题，肯定会超时，
因为用DFS检测两点是否连通时间复杂度是O(e)，本题边很多，所以要超时。
但是本题点少，只有500，要求两点是否连通只需保留这幅图的生成树即可，
这样就可以控制边数最多是n-1，DFS时间复杂度变成了O(n)；
对于加边操作，如果a,b不连通，就直接加上a,b这条边即可，
若已经连通，加上这条边就会有回路，
那么把这个回路中将最早被删除的边提前删除，这样是不会影响后面的操作的；
对于删除操作，若已经提前删除，就算了，没有删除就删除即可。
要想知道回路中的哪条边会最早被删掉，只需先读入所有的操作，记录一下即可。
这样对于每次操作时间复杂度都是O(n)，m次操作，本题时间复杂度即为O(nm).
*/
#include <stdio.h>  
#include <string.h>  
#define MAXV 505  
#define MAXE 100005  
struct  
{  
    int  a, b;  
    char c;  
} Q[MAXE];  
int  n, neg;  
int  delTime[MAXV][MAXV];  
int  v[MAXV], next[MAXE], edge[MAXE];  
char vst[MAXV];  
int  aa, bb, min;  
/* 用DFS检验a,b是否连通，若连通记录下路径中最早删除的边 */  
int isconct(int a, int b)  
{  
    int i;  
    if (a == b)  
        return 1;  
    vst[a] = 1;  
    for (i=v[a]; i!=-1; i=next[i])  
        if (!vst[edge[i]] && isconct(edge[i], b))  
        {  
            if (delTime[a][edge[i]] < min)  
            {  
                aa = a;  
                bb = edge[i];  
                min = delTime[aa][bb];  
            }  
            return 1;  
        }  
    return 0;  
}  
/* 在a,b之间添加一条边 */  
void add(int a, int b)  
{  
    edge[neg] = b;  
    next[neg] = v[a];  
    v[a] = neg++;  
}  
/* 若a,b之间有边则删除，返回1 
   若a,b之间无边则，返回0     */  
int delet(int a, int b)  
{  
    int i;  
    if (v[a] == -1) return 0;  
    i = v[a];  
    if (edge[i] == b)  
    {  
        v[a] = next[i];  
        return 1;  
    }  
    for (; next[i]!=-1; i=next[i])  
        if (edge[next[i]] == b)  
        {  
            next[i] = next[next[i]];  
            return 1;  
        }  
    return 0;  
}  
/* DFS检验a,b是否连通 */  
int DFS(int a, int b)  
{  
    int i;  
    if (a == b)  
        return 1;  
    vst[a] = 1;  
    for (i=v[a]; i!=-1; i=next[i])  
        if (!vst[edge[i]] && DFS(edge[i], b))  
            return 1;  
    return 0;  
}  
void ins(int a, int b)  
{  
    memset(vst, 0, sizeof(vst));  
    min = MAXE;  
    if (isconct(a, b))  
    {  
        if (delTime[a][b] < min || min == MAXE)  
            return ;  
        delet(aa, bb);  
        delet(bb, aa);  
    }  
    add(a, b);  
    add(b, a);  
}  
void del(int a, int b)  
{  
    if (delet(a, b))  
        delet(b, a);  
}  
void quy(int a, int b)  
{  
    memset(vst, 0, sizeof(vst));  
    printf("%s\n", DFS(a, b) ? "YES" : "NO");  
}  
int main()  
{  
    int  m, i, j, ncase;  
    int  a, b;  
    char c;  
    ncase = 0;  
    while (scanf("%d %d", &n, &m) != EOF)  
    {  
        neg = 0;  
        memset(v, -1, sizeof(v));  
        memset(delTime, 0x7f, sizeof(delTime));  
        for (i=0; i<m; i++)  
        {  
            scanf("%*c %c %d %d", &Q[i].c, &Q[i].a, &Q[i].b);  
            if (Q[i].c == 'D')  
                delTime[Q[i].a][Q[i].b] = delTime[Q[i].b][Q[i].a] = i;  
        }  
        if (ncase) printf("\n");  
        printf("Case %d:\n", ++ncase);  
        for (i=0; i<m; i++)  
        {  
            switch (Q[i].c)  
            {  
                case 'I': ins(Q[i].a, Q[i].b); break;  
                case 'D': del(Q[i].a, Q[i].b); break;  
                case 'Q': quy(Q[i].a, Q[i].b); break;  
            }  
        }  
    }  
    return 0;  
} 
