#include <cstdio>
#include <iostream>
#include <climits>

// using kd tree

using namespace std;

const int MAXN = 512;

struct Node {
    Node *LU, *RU, *LB, *RB;
    int x1, x2, y1, y2;
    int xmid, ymid;
    int min_val;
    Node(){LU=NULL;RU=NULL;LB=NULL;RB=NULL;}
};

int n, m;
int matrix[MAXN][MAXN];

Node* build_tree(int xmin, int xmax, int ymin, int ymax){
    if(xmin > xmax || ymin > ymax) return NULL;
    Node *node = new Node;
    node->x1 = xmin; node->x2 = xmax;
    node->y1 = ymin; node->y2 = ymax;
    int xmid = (xmin+xmax)/2, ymid = (ymin+ymax)/2;
    node->xmid = xmid; node->ymid = ymid;
    if(xmin==xmax && ymin==ymax) return node;
    node->LU = build_tree(xmin, xmid, ymin, ymid);
    node->RU = build_tree(xmid+1, xmax, ymin, ymid);
    node->LB = build_tree(xmin, xmid, ymid+1,ymax);
    node->RB = build_tree(xmid+1, xmax, ymid+1, ymax);
    return node;
}

void calc_min_val(Node *node){
    if(!node) return;
    if(node->x1==node->x2 && node->y1==node->y2) {
        node->min_val = matrix[node->y1][node->x1];
        return;
    }
    int tmp = INT_MAX;
    if(node->LU){
        calc_min_val(node->LU);
        if(tmp > node->LU->min_val) tmp = node->LU->min_val;
    }
    if(node->RU){
        calc_min_val(node->RU);
        if(tmp > node->RU->min_val) tmp = node->RU->min_val;
    }
    if(node->LB){
        calc_min_val(node->LB);
        if(tmp > node->LB->min_val) tmp = node->LB->min_val;
    }
    if(node->RB){
        calc_min_val(node->RB);
        if(tmp > node->RB->min_val) tmp = node->RB->min_val;
    }
    node->min_val = tmp;
}

int search(Node *node, int xmin, int xmax, int ymin, int ymax){
    if(xmin > xmax || ymin > ymax) return INT_MAX;
    if(xmin==node->x1 && xmax==node->x2 && ymin==node->y1 && ymax==node->y2) return node->min_val;
    int xmid = node->xmid, ymid = node->ymid;
    int tmp = INT_MAX;
    if(node->LU) {
        tmp = min(tmp, search(node->LU, xmin, min(xmid,xmax), ymin, min(ymid,ymax)));
    }
    if(node->RU) {
        tmp = min(tmp, search(node->RU, max(xmid+1,xmin), xmax, ymin, min(ymid,ymax)));
    }
    if(node->LB) {
        tmp = min(tmp, search(node->LB, xmin, min(xmid,xmax), max(ymid+1,ymin), ymax));
    }
    if(node->RB) {
        tmp = min(tmp, search(node->RB, max(xmid+1,xmin), xmax, max(ymid+1,ymin), ymax));
    }
    return tmp;
}

void print_tree(Node *node){
    if(!node) return;
    print_tree(node->LU);
    print_tree(node->LB);
    print_tree(node->RU);
    print_tree(node->RB);
    printf("%d %d %d %d %d\n", node->x1, node->x2, node->y1, node->y2, node->min_val);
}

void release_tree(Node *node){
    if(node==NULL) return;
    release_tree(node->LU);
    release_tree(node->RU);
    release_tree(node->LB);
    release_tree(node->RB);
    //printf("%08x\n", node);
    delete node;
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> matrix[i][j];
            }
        }
        Node *node = build_tree(0,n-1,0,n-1);
        calc_min_val(node);
        cin >> m;
        int x1,x2,y1,y2;
        while(m--){
            scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
            printf("%d\n",search(node,x1-1,x2-1,y1-1,y2-1));
        }
        release_tree(node);
        //print_tree(node);
    }
    return 0;
}



/*a template

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

//这个题目是个二维rmq的模板题
//和一维rmq的思路一样
//用dp[row][col][i][j]表示(row,col)到(row+2^i,col+2^j)矩形内的最小值
//查询的时候
//  int kx = log(double(x2 - x1 +1)) / log(2.0);
//  int ky = log(double(y2 - y1 +1)) / log(2.0);
//  int m1 = dp[x1][y1][kx][ky];
//  int m2 = dp[x2-(1<<kx)+1][y1][kx][ky];
//  int m3 = dp[x1][y2-(1<<ky)+1][kx][ky];
//  int m4 = dp[x2-(1<<kx)+1][y2-(1<<ky)+1][kx][ky];
//取4个值里面的最小值(有种二分的思想)
 

const int maxn = 310;

int mat[maxn][maxn];
int dp[maxn][maxn][9][9];
int n , q;

void rmq_2d(void)
{
    for(int row = 1 ; row <= n ; row++)
        for(int col = 1 ; col <= n ; col++)
            dp[row][col][0][0] = mat[row][col];
    int m = log((double)n) / log(2.0);

    for(int i = 0 ; i <= m ; i++)
    {
        for(int j = 0 ; j <= m ; j++)
        {
            if(i == 0 && j == 0)
                continue;
            for(int row = 1 ; row+(1<<i)-1 <= n ; row++)
            {
                for(int col = 1 ; col+(1<<j)-1 <= n ; col++)
                {
                    if(i == 0)
                    {
                        dp[row][col][i][j] = min(dp[row][col][i][j-1] , dp[row][col+(1<<(j-1))][i][j-1]);
                    }
                    else
                    {
                        dp[row][col][i][j] = min(dp[row][col][i-1][j] , dp[row+(1<<(i-1))][col][i-1][j]);
                    }
                }
            }
        }
    }
}

int query_2d(int x1,int x2,int y1,int y2)
{
    int kx = log(double(x2 - x1 +1)) / log(2.0);
    int ky = log(double(y2 - y1 +1)) / log(2.0);
    int m1 = dp[x1][y1][kx][ky];
    int m2 = dp[x2-(1<<kx)+1][y1][kx][ky];
    int m3 = dp[x1][y2-(1<<ky)+1][kx][ky];
    int m4 = dp[x2-(1<<kx)+1][y2-(1<<ky)+1][kx][ky];
    return min( min(m1,m2), min(m3,m4) );
}



int main(int argc, char** argv) {
    int cas;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d",&n);
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
                scanf("%d",&mat[i][j]);
        rmq_2d();
        scanf("%d",&q);
        while(q--){
            int x1 , x2 , y1 , y2 ;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            printf("%d\n",query_2d(x1,x2,y1,y2));
        }
    }
    return 0;
}
*/

/*#include <cstdio>
#include <cstring>

const int MAXN = 300 + 10;
const int INF = 2147483645;

int map[MAXN][MAXN];
int Mat[MAXN][MAXN];
int n;

int min(int a, int b){
    return a < b ? a : b;
}

int Findmin(int x1, int y1, int x2, int y2) {
    if(x1 == 1 && y1 == 1) return Mat[x2][y2];
    if(Mat[x2][y2] != Mat[x1][y2] && Mat[x2][y2] != Mat[x2][y1]) return Mat[x2][y2];

    int mmin = INF;
    for(int i = x1; i <= x2; i++){
        for(int j = y1; j <= y2; j++){
            if(map[i][j] < mmin) mmin = map[i][j];
        }
    }
    return mmin;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                scanf("%d", &map[i][j]);
                if(i==1 && j==1) 
                    Mat[i][j] = map[i][j];
                else if(i != 1 && j == 1)
                    Mat[i][j] = min(map[i][j], Mat[i - 1][j]);
                else if(i == 1 && j != 1)
                    Mat[i][j] = min(map[i][j], Mat[i][j - 1]);
                else 
                    Mat[i][j] = min(map[i][j], min(Mat[i - 1][j], Mat[i][j - 1]));
            }
        }
        int m;
        scanf("%d", &m);
        while(m--) {
            int a, b, c, d;
            scanf("%d%d%d%d", &a, &b, &c, &d);
            printf("%d\n", Findmin(a, b, c, d));
        }
    }
    return 0;
}
*/