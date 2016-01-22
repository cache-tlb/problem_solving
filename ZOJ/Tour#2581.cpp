#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;
/*  dp[i][j] 两条路分别到达i 和 j, 最右边点为j的最小花费, i != j,
    因为两条路线是对称的, 我们只要考虑 i < j 就可以了.
*/

const int MAXN = 128;
const double DINF = 1e100;
struct Point {
    double x, y;
};

double cache[MAXN][MAXN];
bool is_set[MAXN][MAXN];
int N;
Point points[MAXN];

bool cmp(const Point &a, const Point &b) {
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

inline double dist(const Point &a, const Point &b){
    return hypot(a.x - b.x, a.y - b.y);
}

double search(int i, int j) {
    if(is_set[i][j]) return cache[i][j];
    if(i==0 && j==1){
        is_set[i][j] = true;
        cache[i][j] = dist(points[0], points[1]);
        return cache[i][j];
    }
    if(i==0 && j > 1){
        is_set[i][j] = true;
        cache[i][j] = search(i, j - 1) + dist(points[j - 1], points[j]);
        return cache[i][j];
    }
    double min_val = DINF;
    if(i == j - 1){
        for(int k = 0; k < i; k++){
            double tmp = search(k, i) + dist(points[k], points[j]);
            if(tmp < min_val) min_val = tmp;
        }
    }
    else {
        min_val = search(i, j - 1) + dist(points[j - 1], points[j]);
    }
    cache[i][j] = min_val;
    is_set[i][j] = true;
    return min_val;
}

double process() {
    memset(is_set, 0, sizeof(is_set));
    sort(points, points + N, cmp);
    double ans = DINF;
    for(int i = 0; i < N - 1; i++) {
        ans = min(ans, search(i, N - 1) + dist(points[i], points[N - 1]));
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    while(scanf("%d", &N) != EOF) {
        for(int i = 0; i < N; i++) {
            scanf("%lf%lf", &points[i].x, &points[i].y);
        }
        printf("%.2lf\n", process());
    }
    return 0;
}
