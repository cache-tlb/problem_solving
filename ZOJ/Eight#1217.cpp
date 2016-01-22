/*#include<iostream>
#include<deque>
#include<string>
#include<cstring>
#include<map>
using namespace std;
const int MAX = 181440 + 10;
const int HASHMAXSIZE = 200003;
//int vis[HASHMAXSIZE] = {};
struct state{
    int a[9];
    int num;
    int zpos;
    int hashc;
    string cmd;
};
state ss;
int flag = 0;
int pow10(int x)
{
    int ans = 0;
    switch(x){
        case 0:
            ans = 1;break;
        case 1:
            ans = 10;break;
        case 2:
            ans = 100;break;
        case 3:
            ans = 1000;break;
        case 4:
            ans = 10000;break;
        case 5:
            ans = 100000;break;
        case 6:
            ans = 1000000;break;
        case 7:
            ans = 10000000;break;
        case 8:
            ans = 100000000;break;
        case 9:
            ans = 1000000000;break;
    }
    return ans;    
}
bool OK(state& s)
{
    if(s.zpos != 8) return false;
    for(int i = 0; i < 8; i++){
        if(s.a[i] != i + 1) return false;
    }
    return true;
}
state r(state s)
{
    //cout << "r_s.num= " <<s.num<<endl;
    int pos = s.zpos;
    if(pos%3 == 2) return s;
    s.a[pos] = s.a[pos + 1];
    s.a[pos + 1] = 0;
    s.zpos = pos + 1;
    s.num -= s.a[pos]*9*pow10(pos);
    s.hashc = s.num % HASHMAXSIZE;
    //cout << "r_s.num= "<< s.num <<endl;
    s.cmd += "r";
    return s;
}
state l(state s)
{
    int pos = s.zpos;
    if(pos%3 == 0) return s;
    s.a[pos] = s.a[pos - 1];
    s.a[pos - 1] = 0;
    s.zpos = pos - 1;
    s.num += s.a[pos]*9*pow10(pos - 1);
    s.hashc = s.num % HASHMAXSIZE;
    s.cmd += "l";
    return s;
}
state u(state s)
{
    int pos = s.zpos;
    if(pos/3 ==0 ) return s;
    s.a[pos] = s.a[pos - 3];
    s.a[pos - 3] = 0;
    s.zpos = pos - 3;
    s.num += s.a[pos]*999*pow10(pos - 3);
    s.hashc = s.num % HASHMAXSIZE;
    s.cmd += "u";
    return s;
}
state d(state s)
{
    int pos = s.zpos;
    if(pos/3 == 2)return s;
    s.a[pos] = s.a[pos + 3];
    s.a[pos + 3] = 0;
    s.zpos = pos + 3;
    s.num -= s.a[pos]*999*pow10(pos);
    s.hashc = s.num % HASHMAXSIZE;
    s.cmd += "d";
    return s;
}
void bfs()
{
    deque<state> qs;
    map<int,int> vis;
    qs.push_back(ss);
    while(!qs.empty()){
        state s = qs[0];
        //cout << "s.num= " << s.num <<endl;
        
        state temp[4];
        if(OK(s)){
            cout << s.cmd << endl;
            flag = 1;
            break;
        }
        vis[s.hashc] = 1;
        //cout <<"check1"<<endl;
        temp[0] = u(s);
        temp[1] = l(s);
        temp[2] = d(s);
        temp[3] = r(s);
        //cout <<"check2"<<endl;
        for(int i = 0; i < 4; i++){
            //cout << temp[i].num << ' ' << temp[i].hashc <<endl;
            if(vis[temp[i].hashc]) continue;
            qs.push_back(temp[i]);
        }
        qs.pop_front();
    }            
    if(!flag) cout << "unsolvable" << endl;
}
int main()
{
    char x;
    while(cin >> x){
        //memset(vis,0,sizeof(vis));
        if(x == 'x'){
            ss.a[0] = 0;
            ss.zpos = 0;
        }
        
        else ss.a[0] = x - '0';
        int temp = 1;
        ss.num += temp*ss.a[0];
        for(int i = 1; i < 9; i++){
            cin >> x;
            temp *= 10;
            int xx;
            if(x == 'x'){
                xx = 0;
                ss.zpos = i;
            }
            else xx = x - '0';
            //cout << xx ;
            ss.a[i] = xx;
            ss.num += temp*xx;
        }
        //cout <<ss.num<<endl;
        ss.hashc = ss.num % HASHMAXSIZE;
        //cout <<ss.hashc <<endl;
        flag = 0;
        //cout << ss.num << ' ' << ss.zpos << endl; 
        bfs();
    }
    return 0;
}*/
/*
//Name:Eight_Puzzle

// author:lrj  

// function:calculate the distance between two Eight_Puzzle states
#include<iostream>
#include<cstring>
#include<map>
using namespace std;
typedef int state[9];
const int MAXSTATE=200000;
state st[MAXSTATE],goal;
int dist[MAXSTATE];
char step[MAXSTATE];
int father[MAXSTATE];

const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
const char cmd[]={'u','d','l','r'};
const int MAXHASHSIZE=200003;
int head[MAXHASHSIZE],next[MAXSTATE];
void init_lookup_table()
{
    memset(head,0,sizeof(head)); 
}
int hash(state& s)
{
    int v=0;
    for(int i=0;i<9;i++)
        v=v*10+s[i];
        
    return v%MAXHASHSIZE;
}
int try_to_insert(int s)
{
    int h=hash(st[s]);
    int u=head[h];
    while(u)
    {
        if(memcmp(st[u],st[s],sizeof(st[s]))==0) return 0;
        u=next[u];    
    }
    next[s]=head[h];
    head[h]=s;
    return 1;
}
int bfs()
{
    //init_lookup_table();
    map<state,int> smap;
    map<state,int>::iterator it;
    int front =1,rear=2;
    while(front<rear)
    {
        state& s=st[front];
        if(memcmp(goal,s,sizeof(s))==0){
            char go[100]={};
            int cur = front,k = 0;
            while(cur != 1){
                go[k] = step[cur];
                k++;
                cur = father[cur];
            }
            for(int i = k - 1; i>=0; i--){
                cout << go[i];
            }
            cout << endl;    
            return front;
        }    
        int z;
        for(z=0;z<9;z++) if(!s[z]) break;
        int x=z/3,y=z%3;
        for(int d=0;d<4;d++)
        {
            int newx=x+dx[d];
            int newy=y+dy[d];
            int newz=newx*3+newy;
            if(newx>=0&&newx<3&&newy>=0&&newy<3)
            {
                state& t=st[rear];
                memcpy(&t,&s,sizeof(s));
                t[newz]=s[z];
                t[z]=s[newz];
                dist[rear]=dist[front]+1;
                if(try_to_insert(rear)){
                    //smap.insert(pair<state,int>(t,1));
                    father[rear] = front;
                    step[rear] = cmd[d];
                    rear++;
                }    
            }    
        }
        front++;
    }
    return 0;
}
int main()
{
    for(int i=0;i<9;i++)  goal[i] = i + 1;
    goal[8] = 0;
    char x;
    while(cin >> x){
        memset(st,0,sizeof(st));
        if(x == 'x') st[1][0] = 0;
        else st[1][0] = x - '0';
        for(int i=1;i<9;i++){
            cin>>x;
            if(x == 'x') st[1][i] = 0;
            else st[1][i] = x - '0';
        }    
        memset(father,0,sizeof(father));
        memset(step,0,sizeof(step));
        int ans=bfs();
        if(ans>0) {
            //cout<<dist[ans];
        }
        else cout<<"unsolvable"<<endl;
    }    
   // system("pause");
    return 0;
}

*/
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<stdio.h>
using namespace std;

struct{
    string node;     //数据
    long    front;     //前驱
    short   space;   //'0'的位置
    short   opreat; //操作
}queu1[ 362881 ]
,queu2[ 362881 ];

int   hash[ 362881 ];
char oout[ 5 ] = "ulrd";
char cina[ 10 ];
string data = "123456780";
string midm = "123456780";
string over = "123456780";

/* 位置变化的数组 */
short dxdy[ 10 ][ 4 ] = {
    {-1,-1, 1, 3}, // 0号位的变化 
    {-1, 0, 2, 4}, // 1号位的变化
    {-1, 1,-1, 5}, // 2号位的变化
    { 0,-1, 4, 6}, // 3号位的变化
    { 1, 3, 5, 7}, // 4号位的变化
    { 2, 4,-1, 8}, // 5号位的变化
    { 3,-1, 7,-1}, // 6号位的变化
    { 4, 6, 8,-1}, // 7号位的变化
    { 5, 7,-1,-1}}; // 8号位的变化

/* 偷懒半的康托展开 */                       
static int add[ 8 ] = {1,2,6,24,120,720,5040,40320};
int Cabtor( string a )
{
    int value = 0;
    for ( int i = 0 ; i < 8 ; ++ i )
    {
        int count = 0;
        for ( int j = i+1 ; j < 9 ; ++ j )
        if ( a[ j ] > a[ i ] )
            count ++;
        value += add[ 7-i ]*count;
    }
    return value;
}

/* 输出函数 */ 
void Cout( int t , int k )
{
    int count = 0,opreat[ 10000 ];
    for ( int i = t ; i >= 0 ; i = queu1[ i ].front )
        opreat[ count ++ ] = queu1[ i ].opreat;
    for ( int i = count-2 ; i >= 0 ; -- i )
        printf( "%c" , oout[ opreat[ i ] ]);
    for ( int i = k ; i > 0 ; i = queu2[ i ].front )
        printf( "%c" , oout[ 3 - queu2[ i ].opreat ] );
}

void bfs( int s1 , int s2 )
{
    if ( data == over ) return;
    memset( hash , false , sizeof( hash ) );
    queu1[ 0 ].front = queu2[ 0 ].front = -1;
    queu1[ 0 ].opreat = queu2[ 0 ].opreat = -1;
    queu1[ 0 ].space = s1;
    queu2[ 0 ].space = s2;
    
    hash[ Cabtor( data ) ] = 1;
    queu1[ 0 ].node = data;
    
    hash[ Cabtor( over ) ] = 2;
    queu2[ 0 ].node = over;
    
    int move1 = 0,move2 = 0;
    int save1 = 1,save2 = 1;
    while ( save1 + save2 < 181441 )
    {
        /* 反向搜索 */ 
        if ( move1 < save1 )
        {
            short space1 = queu1[ move1 ].space;
            for ( int k = 0 ; k < 4 ; ++ k )
            {
                if ( dxdy[ space1 ][ k ] < 0 ) continue;
                short state1 = dxdy[ space1 ][ k ];
                
                midm = queu1[ move1 ].node;
                midm[ space1 ] = midm[ state1 ];
                midm[ state1 ] = '0';
                
                queu1[ save1 ].space = state1;
                queu1[ save1 ].front = move1;
                queu1[ save1 ].opreat = k;
                
                int flag1 = Cabtor( midm );
                int valu1 = hash[ flag1 ]%10;
                if ( valu1 == 1 ) continue;
                else if ( valu1 ) 
                {   Cout( save1 , hash[ flag1 ]/10 );return;    }
                hash[ flag1 ] = 10*save1+1;
                queu1[ save1 ++ ].node = midm;           
            }
            ++ move1;
        }
        if ( move2 < save2 )
        {
            /* 正向搜索 */ 
            short space2 = queu2[ move2 ].space;      
            for ( int k = 0 ; k < 4 ; ++ k )
            {
                if ( dxdy[ space2 ][ k ] < 0 ) continue;
                short state2 = dxdy[ space2 ][ k ];
                
                midm = queu2[ move2 ].node;
                midm[ space2 ] = midm[ state2 ];
                midm[ state2 ] = '0';
                
                queu2[ save2 ].space = state2;
                queu2[ save2 ].front = move2;
                queu2[ save2 ].opreat = k;
                
                int flag2 = Cabtor( midm );
                int valu2 = hash[ flag2 ]%10;
                if ( valu2 == 2 ) continue;
                else if ( valu2 )
                {   Cout( hash[ flag2 ]/10 , save2 );return;    }
                hash[ flag2 ] = 10*save2+2;
                queu2[ save2 ++ ].node = midm;
            }
            ++ move2;
        }
    }
}

/* 根据逆序数判断是否有解 */ 
bool judge( string a )
{
    int count = 0;
    for ( int i = 0 ; i < 9 ; ++ i )
    {
        if ( a[ i ] == '0' ) continue;
        for ( int j = 0 ; j < i ; ++ j )
        if ( a[ j ] > a[ i ] )
            count ++;
    }
    if ( count % 2 ) return true;
    else return false;
}

int main()
{
    int t = 0;
    while ( cin >> data[0] ) {
        cin >> data[1] >> data[2] >> data[3] >> data[4];
        cin >> data[5] >> data[6] >> data[7] >> data[8];
        int i;
        for ( i = 0 ; i < 9 ; ++ i )
        if ( data[i] == 'x' || data[i] == '0' )
        {   data[i] = '0';break; }
        if ( judge( data ) ) printf( "unsolvable" );
        else bfs( i , 8 );cout << "\n";
    }
}
