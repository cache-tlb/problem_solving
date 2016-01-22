#include <cstdio>
using namespace std;

// a template -- begin
#define abs(x) ((x)>0?(x):-(x))
struct point {
    int x,y;
};

int gcd(int a,int b) {
    return b?gcd(b,a%b):a;
}

//多边形上的网格点个数
int grid_onedge(int n,point* p) {
    int i,ret=0;
    for (i=0; i<n; i++)
        ret+=gcd(abs(p[i].x-p[(i+1)%n].x),abs(p[i].y-p[(i+1)%n].y));
    return ret;
}

//多边形内的网格点个数
int grid_inside(int n,point* p) {
    int i,ret=0;
    for (i=0; i<n; i++)
        ret+=p[(i+1)%n].y*(p[i].x-p[(i+2)%n].x);
    return (abs(ret)-grid_onedge(n,p))/2+1;
}

// -- end --
const int MAXN = 128;
point p[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; t++){
        int m;
        scanf("%d", &m);
        point cur; cur.x = 0; cur.y = 0;
        for(int i = 0; i < m; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            p[i] = cur;
            cur.x += a;
            cur.y += b;
        }
        int i = grid_inside(m, p);
        int e = grid_onedge(m, p);
        double s = (double)i + (double)e/2.0 - 1.0;
        printf("Scenario #%d:\n", t+1);
        printf("%d %d %.1lf\n\n", i, e, s);
    }
    return 0;
}
