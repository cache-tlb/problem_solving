#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

/* brute force */

struct Rect {
    int xmin, xmax, ymin, ymax;
    Rect(){}
    Rect(int x1, int x2, int y1, int y2):xmin(x1),xmax(x2),ymin(y1),ymax(y2){}
};

bool contains(const Rect &a, const Rect &b) {
    return (a.xmin <= b.xmin) && (a.xmax >= b.xmax) && (a.ymin <= b.ymin) && (a.ymax >= b.ymax);
}

int main(int argc, char const *argv[])
{
    int N;
    while(scanf("%d", &N) != EOF){
        vector<Rect> vr;
        vr.resize(N);
        for(int i = 0; i < N; i++){
            int x1, x2, y1, y2;
            scanf("%d%d%d%d", &x1, &x2, &y1, &y2);
            vr[i] = Rect(x1, x2, y1, y2);
        }
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(j == i) continue;
                if(contains(vr[j], vr[i])) {
                    cnt++;
                    break;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
