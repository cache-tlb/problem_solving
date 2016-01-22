#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

/* divide and conquer ! */

const int MAXN = 100010;
const double DINF = 1e100;
const double EPS = 1e-8;

struct Point {
    double x, y;
};

bool cmpX(const Point &a, const Point &b) {
    return a.x < b.x;
}

bool cmpY(const Point &a, const Point &b) {
    return a.y < b.y;
}

inline double sqr(double x) {
    return x*x;
}

inline double dist2(const Point &a, const Point &b) {
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

int N;
Point points[MAXN];
Point buffer[MAXN];

double getMinDistPair(int start, int end, bool direction) {
    int n = end - start;
    if(n <= 1) return DINF;
    if(n==2) return dist2(points[start], points[end - 1]);
    if(n==3){
        Point &p1 = points[start];
        Point &p2 = points[start + 1];
        Point &p3 = points[start + 2];
        return min(min(dist2(p1, p2), dist2(p1, p3)), dist2(p2, p3));
    }
    int mid = (start + end)/2;
    if(direction){
        sort(points + start, points + end, cmpX);
        double sep = points[mid].x;
        double mind = min(getMinDistPair(start, mid, !direction), getMinDistPair(mid, end, !direction));
        int nCand = 0;
        for(int i = start; i < end; i++) {
            if(fabs(points[i].x - sep) <= mind + EPS){
                buffer[nCand++] = points[i];
            }
        }
        sort(buffer, buffer + nCand, cmpY);
        for(int i = 0; i < nCand; i++) {
            for(int j = i + 1; j < nCand; j++){
                if(buffer[j].y - buffer[i].y > mind) break;
                double tmp = dist2(buffer[i], buffer[j]);
                if(tmp < mind) mind = tmp;
            }
        }
        return mind;
    }
    else{
        sort(points + start, points + end, cmpY);
        double sep = points[mid].y;
        double mind = min(getMinDistPair(start, mid, !direction), getMinDistPair(mid, end, !direction));
        int nCand = 0;
        for(int i = start; i < end; i++) {
            if(fabs(points[i].y - sep) <= mind + EPS) {
                buffer[nCand++] = points[i];
            }
        }
        sort(buffer, buffer + nCand, cmpX);
        for(int i = 0; i < nCand; i++) {
            for(int j = i + 1; j < nCand; j++) {
                if(buffer[j].x - buffer[i].x > mind) break;
                double tmp = dist2(buffer[i], buffer[j]);
                if(tmp < mind) mind = tmp;
            }
        }
        return mind;
    }
}

int main(int argc, char const *argv[])
{
    while(scanf("%d", &N) != EOF){
        if(!N) break;
        for(int i = 0; i < N; i++) {
            scanf("%lf%lf", &points[i].x, &points[i].y);
        }
        printf("%.2lf\n", sqrt(getMinDistPair(0, N, true))/2.0);
    }
    return 0;
}
