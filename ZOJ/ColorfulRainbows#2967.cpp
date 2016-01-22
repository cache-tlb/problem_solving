#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

// using stack
// first, sort the lines accroding to their k, for lines with same k we only consider the one that has the max b.
// maintain a stack containing rays(a ray is one line with one point p)
// put the first line and a very small value in the stack
// then consider the other lines, when a new line comes, compare it with the top of stack
// find the intersection of the two lines, 
// if the intersaction has a smaller or equal x value compared to stack.top.point, or stack size is 1
// we add the new line with the intersection as a new ray to the stack
// otherwise we pop the stack, and continue comparing the new line with the new stack top
// finally, the stack contains the lines that can be seen.

const double DOUBLE_MAX = 1.79769e+308;

struct ray {
    double px, k, b;
    ray(){}
    ray(double x,double kk,double bb){px=x;k=kk;b=bb;}
};

struct line {
    double k, b;
    line(){}
    line(double kk,double bb){k=kk;b=bb;}
};

double get_intersection_x(double k1, double b1, double k2, double b2){
    if(k1==k2) return 0.0;
    else return (b2-b1)/(k1-k2);
}

bool cmp(const line &a, const line &b){
    return (a.k < b.k) || (a.k == b.k && a.b > b.b);
}

vector<line> v;
int n;

int process(){
    sort(v.begin(), v.end(), cmp);
    stack<ray> s;
    s.push(ray(-DOUBLE_MAX, v[0].k, v[0].b));
    for(int i = 1; i < n; i++){
        ray top = s.top();
        if(v[i].k==top.k) continue;
        double inter_x = get_intersection_x(v[i].k,v[i].b,top.k,top.b);
        while(inter_x <= top.px && s.size() > 1){
            s.pop();
            top = s.top();
            inter_x = get_intersection_x(v[i].k,v[i].b,top.k,top.b);
        }
        s.push(ray(inter_x, v[i].k, v[i].b));
    }
    return s.size();
}

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        v.clear();
        for(int i = 0; i < n; i++){
            double k, b;
            scanf("%lf%lf", &k, &b);
            v.push_back(line(k, b));
        }
        printf("%d\n", process());
    }
    return 0;
}
