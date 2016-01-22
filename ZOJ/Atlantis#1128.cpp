/*这个很多参考了NotOnlySuccess的思路。cnt用的记为精妙啊。
将区间起始端点标记为1，末端点标记为-1.
则进入一个矩形为1，离开一个矩形为-1，cnt不为0表示线段有重叠。
先对纵坐标进行排序，在x轴上求相应区间的最大值，取根节点即可。*/
/*#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#define maxn 2222
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

double sum[maxn<<2];
int cnt[maxn<<2];
double X[maxn];
struct seg {
    double l, r, h;//标记线段的始末
    int s;
    seg() {}
    seg(double a,double b,double c,int d):l(a),r(b),h(c),s(d) {}
    bool operator < (const seg&cmp)const {
        return h<cmp.h;
    }
} ss[maxn<<2];

void pushup(int rt,int l,int r) {
    if(cnt[rt])
    sum[rt]=X[r+1]-X[l];
    else if(l==r) sum[rt]=0;
    else sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void update(int a,int b,int c,int l,int r,int rt) {
    if(a<=l&&b>=r) {
        cnt[rt]+=c;
        pushup(rt,l,r);
        return ;
    }
    int mid=(r+l)>>1;
    if(a<=mid) update(a,b,c,lson);
    if(b>mid) update(a,b,c,rson);
    pushup(rt,l,r);
}

int binary(double key,int n,double X[]) {
    int low=0,high=n-1;
    while(low<=high) {
        int m=(low+high)>>1;
        if(X[m]==key) return m;
        else if(X[m]<key) low=m+1;
        else  high=m-1;
    }
    return -1;
}

using namespace std;
int main() {
    int n;
    double a,b,c,d;
    int cases=1;
    while(scanf("%d",&n)==1&&n) {
        int m=0;
        for(int i=0;i<n;i++) {
            scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
            X[m]=a;
            ss[m++]=seg(a,c,b,1);
            X[m]=c;
            ss[m++]=seg(a,c,d,-1);
        }
        sort(X,X+m);
        sort(ss,ss+m);
        int nn=1;
        for(int i=1;i<m;i++) {
            if(X[i]!=X[i-1])
                X[nn++]=X[i];
        }
        double ret=0;
        memset(cnt,0,sizeof(cnt));
        memset(sum,0,sizeof(sum));
        for(int i=0;i<m;i++) {
            int l=binary(ss[i].l,nn,X);
            int r=binary(ss[i].r,nn,X)-1;
            if(l<=r) {
                update(l,r,ss[i].s,0,nn-1,1);
                ret+=sum[1]*(ss[i+1].h-ss[i].h);
            }
        }
        printf("Test case #%d\n",cases++);
        printf("Total explored area: %.2lf\n",ret);
        printf("\n");
    }
    return 0;
}
*/

/*  My Implement
    Using segment tree
*/
#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

struct Node {
    int l_ind, r_ind;
    int cover;
    Node *lchild, *rchild;
    Node():lchild(NULL),rchild(NULL),cover(0){}
    Node(int _l, int _r, int _c):l_ind(_l),r_ind(_r),cover(_c),lchild(NULL),rchild(NULL){}
};

struct Seg {
    int l_ind, r_ind, is_top;
    double lval, rval;
    double h;
    Seg(){}
    Seg(double _l, double _r, double _h, int _top):lval(_l), rval(_r), h(_h), is_top(_top){}
};

bool cmp (const Seg &a, const Seg &b) {
    return a.h < b.h;
}

const int MAXN = 1024;
double x_coord[MAXN*2];
double y_coord[MAXN*2];
map<double, int> double2int;

Seg segs[MAXN*2];

Node *build_tree(int l_ind, int r_ind) {
    // l_ind and r_ind are index of x_coord;
    if(r_ind <= l_ind) return NULL;
    Node *node = new Node(l_ind, r_ind, 0);
    int mid = (l_ind+r_ind)/2;
    if(r_ind - l_ind <= 1) return node;
    node->lchild = build_tree(l_ind, mid);
    node->rchild = build_tree(mid, r_ind);
    return node;
}

void insertSeg(Node *node, int a, int b) {
    if(a <= node->l_ind && node->r_ind <= b){
        node->cover++;
    }
    else{
        int mid = (node->l_ind + node->r_ind) / 2;
        if(b <= mid) insertSeg(node->lchild, a, b);
        else if(a >= mid) insertSeg(node->rchild, a, b);
        else{
            insertSeg(node->lchild, a, mid);
            insertSeg(node->rchild, mid, b);
        }
    }
}

void deleteSeg(Node *node, int a, int b) {
    if(a <= node->l_ind && node->r_ind <= b) {
        node->cover --;
    }
    else{
        int mid = (node->l_ind + node->r_ind) / 2;
        if(b <= mid) deleteSeg(node->lchild, a, b);
        else if(a >= mid) deleteSeg(node->rchild, a, b);
        else{
            deleteSeg(node->lchild, a, mid);
            deleteSeg(node->rchild, mid, b);
        }
    }
}

double range(Node *node) {
    if(node->cover > 0) return x_coord[node->r_ind] - x_coord[node->l_ind];
    else if(node->r_ind - node->l_ind == 1) return 0.0;
    else return range(node->lchild) + range(node->rchild);
}

void destroyTree(Node *node) {
    if(!node) return;
    destroyTree(node->lchild);
    destroyTree(node->rchild);
    delete node;
}

int N;
int main(int argc, char const *argv[])
{
    int t = 0;
    while(scanf("%d", &N) != EOF) {
        if(!N) break;
        double2int.clear();
        double x1 ,x2, y1, y2;
        for(int i = 0; i < N; i++){
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            double2int[x1] = 1;
            double2int[x2] = 1;
            segs[i*2] = Seg(x1, x2, y1, 0);
            segs[i*2 + 1] = Seg(x1, x2, y2, 1);
        }
        int nx = 0;
        for(map<double, int>::iterator it = double2int.begin(); it != double2int.end(); it++){
            x_coord[nx] = it->first;
            it->second = nx;
            nx ++;
        }
        for(int i = 0; i < N*2; i++) {
            segs[i].l_ind = double2int[segs[i].lval];
            segs[i].r_ind = double2int[segs[i].rval];
        }
        Node *root = build_tree(0, nx - 1);
        sort(segs, segs + N*2, cmp);
        /*for(int i = 0; i < N*2; i++) {
            cout << segs[i].lval << ' ' << segs[i].rval << ' ' << segs[i].h << endl;
        }*/
        double sum = 0.0;
        for(int i = 0; i < N*2; i++) {
            if(segs[i].is_top) deleteSeg(root, segs[i].l_ind, segs[i].r_ind);
            else insertSeg(root, segs[i].l_ind, segs[i].r_ind);
            if(i != 2*N-1 && segs[i+1].h > segs[i].h){
                double len = range(root);
                sum += (segs[i+1].h - segs[i].h) * len;
            }
        }
        printf("Test case #%d\n", ++t);
        printf("Total explored area: %.2lf\n\n", sum);
        destroyTree(root);
    }
    return 0;
}
