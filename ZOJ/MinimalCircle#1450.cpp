#include <cstdio>
#include <cmath>

using namespace std;

/*
算法  MINIDISC（P）
输入：由平面上n个点组成的一个集合P
输出：P的最小包围圆
1.    令D2为对应于{ p1，p2}的最小包围圆
2.    for  i ← 3 to n
3.      do if  pi ∈ Di-1
4.          then  Di ← Di-1
5.          else  Di ← MINIDISCWITHPOINT{{ p1 ，p2 ，p3 ……pi-1}，pi}
6.    return  Dn
算法  MINIDISCWITHPOINT（P，q）
输入：由平面上n个点构成的一个集合P，以及另外一个点q
输出：在满足“边界穿过q”的前提下，P的最小包围圆
1.    令D1为对应于{ p1，q}的最小包围圆
2.    for  j ← 2 to n
3.      do if  pj ∈ Dj-1
4.          then  Dj ← Dj-1
5.          else  Dj ← MINIDISCWITH2POINT{{ p1 ，p2 ，p3 ……pj-1}，pj，q}
6.    return  Dn
算法  MINIDISCWITH2POINT（P，q1，q2）
输入：由平面上n个点构成的一个集合P，以及另外两个点q1，q2
输出：在满足“边界穿过q1，q2”的前提下，P的最小包围圆
1.    令D0为对应于{ q1，q2}的最小包围圆
2.    for  k ← 1 to n
3.      do if  pk∈ Dk-1
4.          then  Dk ← Dk-1
5.          else  Dk ← q1，q2和pk确定的圆
6.    return  Dn
*/

struct Point {
    double x, y;
    Point(){}
    Point(double xx, double yy) : x(xx), y(yy){}
};

struct Circle {
    Point center;
    double radius;
    Circle(){}
    Circle(double x, double y, double r) : center(x, y), radius(r){}
    Circle(Point &p, double r) : center(p), radius(r){}
};

const int MAXN = 128;
const double EPS = 1e-8;
Point points[MAXN];
int N;

inline double dist(Point &p1, Point &p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

Circle get_circle(Point &p1, Point &p2) {
    return Circle((p1.x + p2.x)/2.0, (p1.y + p2.y)/2.0, dist(p1, p2) / 2.0);
}

Circle get_circle(Point &p1, Point &p2, Point &p3) {
    double x1 = p1.x, y1 = p1.y;
    double x2 = p2.x, y2 = p2.y;
    double x3 = p3.x, y3 = p3.y;
    double x = ((y2-y1)*(y3*y3-y1*y1+x3*x3-x1*x1)-(y3-y1)*(y2*y2-y1*y1+x2*x2-x1*x1))/(2*(x3-x1)*(y2-y1)-2*((x2-x1)*(y3-y1)));
    double y = ((x2-x1)*(x3*x3-x1*x1+y3*y3-y1*y1)-(x3-x1)*(x2*x2-x1*x1+y2*y2-y1*y1))/(2*(y3-y1)*(x2-x1)-2*((y2-y1)*(x3-x1)));
    Point center = Point(x, y);
    return Circle(x, y, dist(center, p1));
}

bool point_in_circle(Point &p, Circle &c) {
    double d = dist(p, c.center);
    return (c.radius - d > EPS);
}

Circle MINIDISCWITH2POINT(int k, Point &q1, Point &q2) {
    Circle di = get_circle(q1, q2);
    Circle di_1 = di;
    for(int i = 1; i <= k; i++) {
        if(point_in_circle(points[i], di_1)) di = di_1;
        else di = get_circle(q1, q2, points[i]);
        di_1 = di;
    }
    return di;
}

Circle MINIDISCWITHPOINT(int k, Point &q) {
    Circle di = get_circle(points[1], q);
    Circle di_1 = di;
    for(int j = 2; j <= k; j++) {
        if(point_in_circle(points[j], di_1)) di = di_1;
        else di = MINIDISCWITH2POINT(j - 1, points[j], q);
        di_1 = di;
    }
    return di;
}

Circle MINIDISC() {
    Circle di_1 = get_circle(points[1], points[2]);
    Circle di = di_1;
    for(int i = 3; i <= N; i++) {
        if(point_in_circle(points[i], di_1)) di = di_1;
        else di = MINIDISCWITHPOINT(i - 1, points[i]);
        di_1 = di;
    }
    return di;
}

int main(int argc, char const *argv[])
{
    while(scanf("%d", &N) != EOF) {
        if(!N) break;
        for(int i = 1; i <= N; i++) {
            scanf("%lf%lf", &points[i].x, &points[i].y);
        }
        Circle cir = MINIDISC();
        printf("%.2lf %.2lf %.2lf\n", cir.center.x, cir.center.y, cir.radius);
    }
    return 0;
}
