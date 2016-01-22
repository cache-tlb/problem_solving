#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
    Point(){}
    Point(double _x, double _y){x=_x;y=_y;}
};
struct Segment {
    Point p1, p2;
    Segment(){}
    Segment(const Point &_p1, const Point &_p2){p1=_p1;p2=_p2;}
};

inline double cross_prod(const Point &p1, const Point &p2, const Point &p0){
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

inline bool isIntersect(const Segment &L1, const Segment &L2){
    return( (max(L1.p1.x,   L1.p2.x) >= min(L2.p1.x, L2.p2.x)) &&
            (max(L2.p1.x,   L2.p2.x) >= min(L1.p1.x, L1.p2.x)) &&
            (max(L1.p1.y,   L1.p2.y) >= min(L2.p1.y, L2.p2.y)) &&
            (max(L2.p1.y,   L2.p2.y) >= min(L1.p1.y, L1.p2.y)) &&
            (cross_prod(L2.p1, L1.p2, L1.p1) * cross_prod(L1.p2, L2.p2, L1.p1) >= 0) &&
            (cross_prod(L1.p1, L2.p2, L2.p1) * cross_prod(L2.p2, L1.p2, L2.p1) >= 0)
            );
}

const int MAXN = 1024;
Point points[MAXN];
Segment segments[MAXN];
int N;

double signed_area(const Point &p1, const Point &p2, const Point &p3){
    return (p1.x*(p2.y - p3.y) - p2.x*(p1.y-p3.y) + p3.x*(p1.y-p2.y)) * 0.5;
}

double calcArea() {
    double sum = 0;
    for(int i = 1; i < N - 1; i++){
        sum += signed_area(points[0], points[i], points[i+1]);
    }
    return fabs(sum);
}

int main(int argc, char const *argv[])
{
    int t = 0;
    while(scanf("%d", &N) != EOF){
        if(!N) break;
        for(int i = 0; i < N; i++){
            scanf("%lf%lf", &points[i].x, &points[i].y);
        }
        for(int i = 0; i < N - 1; i++){
            segments[i].p1 = points[i];
            segments[i].p2 = points[i+1];
        }
        segments[N-1].p1 = points[N-1];
        segments[N-1].p2 = points[0];
        bool valid = true;
        for(int i = 0; i < N; i++){
            for(int j = i + 2; j < N; j++){
                // some problems here
                if(isIntersect(segments[i], segments[j]) && !(i==0 && j==N-1)){
                    valid = false;
                    break;
                }
            }
            if(!valid) break;
        }
        if(!valid || N < 3){
            printf("Figure %d: Impossible\n", ++t);
        }
        else{
            printf("Figure %d: %.2lf\n", ++t, calcArea());
        }
    }
    return 0;
}
