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
���⣺���ֱ��������⣬�϶��ᳬʱ��
��Ϊ��DFS��������Ƿ���ͨʱ�临�Ӷ���O(e)������ߺܶ࣬����Ҫ��ʱ��
���Ǳ�����٣�ֻ��500��Ҫ�������Ƿ���ֻͨ�豣�����ͼ�����������ɣ�
�����Ϳ��Կ��Ʊ��������n-1��DFSʱ�临�Ӷȱ����O(n)��
���ڼӱ߲��������a,b����ͨ����ֱ�Ӽ���a,b�����߼��ɣ�
���Ѿ���ͨ�����������߾ͻ��л�·��
��ô�������·�н����类ɾ���ı���ǰɾ���������ǲ���Ӱ�����Ĳ����ģ�
����ɾ�����������Ѿ���ǰɾ���������ˣ�û��ɾ����ɾ�����ɡ�
Ҫ��֪����·�е������߻����类ɾ����ֻ���ȶ������еĲ�������¼һ�¼��ɡ�
��������ÿ�β���ʱ�临�Ӷȶ���O(n)��m�β���������ʱ�临�Ӷȼ�ΪO(nm).
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
/* ��DFS����a,b�Ƿ���ͨ������ͨ��¼��·��������ɾ���ı� */  
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
/* ��a,b֮�����һ���� */  
void add(int a, int b)  
{  
    edge[neg] = b;  
    next[neg] = v[a];  
    v[a] = neg++;  
}  
/* ��a,b֮���б���ɾ��������1 
   ��a,b֮���ޱ��򣬷���0     */  
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
/* DFS����a,b�Ƿ���ͨ */  
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
