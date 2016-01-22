/*#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <queue>

using namespace std;

// 1<=N<=10 1<=M<=20
// using bfs
const int MAXN = 12;
const int MAXM = 22;
const int MAXMASk = 102;
int mask[MAXMASk];
map<int,int> dis;
int n_mask;
int n, m;

void build_mask(string &str){
    set<int> s_mask;
    int trim1 = -1;
    int trim2 = -1;
    for(int i = 0; i < n; i++){
        if(str[i]=='*'){
            trim1 &= ~(1<<i);
            trim2 &= ~(1<<(n-1-i));
        }
    }
    //printf("trim1: %x\n", trim1);
    //printf("trim2: %x\n", trim2);
    int nail_high_mask = (-1) << m;
    for(int i = 0; i < n; i++){
        int tmp1 = -1;
        int tmp2 = -1;
        int shift_r = i;
        int trim_high_mask = (-1) << (n - shift_r);
        tmp1 &= (trim1 >> shift_r)|trim_high_mask;
        tmp1 |= nail_high_mask;
        tmp2 &= (trim2 >> shift_r)|trim_high_mask;
        tmp2 |= nail_high_mask;
        s_mask.insert(tmp1);
        s_mask.insert(tmp2);
    }
    for(int i = 0; i < m; i++){
        int tmp1 = -1, tmp2 = -1;
        int shift_l = i;
        int trim_low_mask = (1<<shift_l) - 1;
        tmp1 &= (trim1 << shift_l)|trim_low_mask;
        tmp1 |= nail_high_mask;
        tmp2 &= (trim2 << shift_l)|trim_low_mask;
        tmp2 |= nail_high_mask;
        s_mask.insert(tmp1);
        s_mask.insert(tmp2);
    }
    n_mask = 0;
    for(set<int>::iterator it = s_mask.begin(); it != s_mask.end(); it++){
        //printf("%x\n", *it);
        mask[n_mask++] = *it;
    }
}

void bfs(){
    queue<int> q;
    dis.clear();
    int src = -1;
    int dst = (-1) << m;
    q.push(src);
    dis[src] = 0;
    while(!q.empty()){
        int state = q.front();
        q.pop();
        int cur_dis = dis[state];
        for(int i = 0; i < n_mask; i++){
            int new_state = state & mask[i];
            //printf("%x\n", new_state);
            if(dis.count(new_state) == 0){
                dis[new_state] = cur_dis + 1;
                if(new_state == dst) return;
                q.push(new_state);
            }
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    string str;
    while(cin >> n >> str >> m){
        bool has_good = false;
        for(int i = 0; i < n; i++){
            if(str[i] == '*'){
                has_good = true;
                break;
            }
        }
        if(!has_good){
            cout << -1 << endl;
        }
        else{
            build_mask(str);
            bfs();
            int dst = (-1)<<m;
            cout << dis[dst] << endl;
        }
    }
    return 0;
}
*/

#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct node
{
    int nail;//指甲的状态（1表示没剪过的，0表示剪过的）
    int cnt;
}now,tmp;

bool vis[1050000];
int n,m,op1,op2;

int bfs()
{
    queue <struct node> q;
    now.nail=1;
    now.nail=(now.nail<<m)-1;//初值全为1//指甲没被剪的为1，被剪掉的为0
    now.cnt=0;
    q.push(now);
    vis[now.nail]=true;
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if(!now.nail)//等0时退出
            return now.cnt;
        //正着剪
        tmp=now;
        tmp.nail&=op1;//剪指甲
        while(tmp.nail&&((tmp.nail&1)==0))
            tmp.nail>>=1;//将末尾的已被剪掉的部分去掉(即将指甲移动到最右面是没剪的为止)
        if(!vis[tmp.nail])
        {
            tmp.cnt++;
            q.push(tmp);
            vis[tmp.nail]=true;
        }
        //反着剪
        tmp=now;
        tmp.nail&=op2;//剪指甲
        while(tmp.nail&&(tmp.nail&1)==0)//将末尾的已被剪掉的部分去掉(即将指甲移动到最右面是没剪的为止)
            tmp.nail>>=1;
        if(!vis[tmp.nail])
        {
            tmp.cnt++;
            q.push(tmp);
            vis[tmp.nail]=true;
        }
    }
    return -1;
}

int main()
{
    while(scanf("%d",&n)==1)
    {
        char ip[50];
        int i;
        scanf("%s",ip);
        op1=op2=(1<<21)-1;
        for(i=0;i<n;i++)
        {
            if(ip[i]=='*')
            {
                op1&=~(1<<i);
                op2&=~(1<<(n-i-1));
            }
        }//指甲刀（完好的部分为0，豁口为1）
        if(op1==(1<<21)-1)
        {
            scanf("%d",&m);
            printf("-1\n");
            continue;
        }
        while(op1&1)//将末尾的1去掉，保证指甲刀的最右面不是豁口
            op1=op1/2+1048576;
        while(op2&1)//将末尾的1去掉，保证指甲刀的最右面不是豁口
            op2=op2/2+1048576;
        scanf("%d",&m);
        memset(vis,false,sizeof(vis));
        printf("%d\n",bfs());
    }
    return 0;
}
