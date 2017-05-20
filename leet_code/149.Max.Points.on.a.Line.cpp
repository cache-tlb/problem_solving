#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

// struct Point {
//     int x;
//     int y;
//     Point() : x(0), y(0) {}
//     Point(int a, int b) : x(a), y(b) {}
// };
 

int gcd(int u, int v) {
    while ( v != 0) {
        int r = u % v;
        u = v;
        v = r;
    }
    return u;
}

struct tup {
    int a,b,c;
    tup(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
    tup() {}
};

struct cmp {
    bool operator() (const Point &a, const Point &b) const{
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
    bool operator() (const tup &x, const tup &y) const {
        return x.a < y.a || (x.a == y.a && x.b < y.b) || (x.a == y.a && x.b == y.b && x.c < y.c);
    }
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if (n == 0) return 0;
        std::map<Point,int,cmp> uni_points;
        std::map<tup,std::set<int>,cmp> lines;
        for (int i = 0; i < n; i++) {
            uni_points[points[i]] += 1;
        }
        std::vector<Point> point_array;
        for (std::map<Point,int,cmp>::iterator it = uni_points.begin(); it != uni_points.end(); it++) {
            point_array.push_back(it->first);
        }
        if (point_array.size() == 1) return n;
        for (int i = 0; i < point_array.size(); i++) {
            // printf("i=%d\n", i);
            int xi = point_array[i].x, yi = point_array[i].y;
            for (int j = i + 1; j < point_array.size(); j++) {
                int xj = point_array[j].x, yj = point_array[j].y;
                int dx = xj - xi, dy = yj - yi;
                tup t;
                int c = dy*xi - dx*yi;
                if (dx == 0) {
                    t = tup(1,0,xi);
                }
                else if (dy == 0) {
                    t = tup(0,1,yi);
                } else {
                    if (dy < 0) {
                        dx *= -1;
                        dy *= -1;
                        c *= -1;
                    }
                    int g = gcd(abs(dx), abs(dy));
                    g = gcd(g, abs(c));
                    dx /= g;
                    dy /= g;
                    c /= g;
                    t = tup(dy,-dx,c);
                }
                lines[t].insert(i);
                lines[t].insert(j);
            }
        }
        int res = 0;
        for (std::map<tup,std::set<int>,cmp>::iterator it = lines.begin(); it != lines.end(); it++) {
            std::set<int> &s = it->second;
            int cnt = 0;
            for (std::set<int>::iterator it2 = s.begin(); it2 != s.end(); it2++) {
                cnt += uni_points[point_array[*it2]];
            }
            res = std::max(cnt, res);
        }
        return res;
    }
};


