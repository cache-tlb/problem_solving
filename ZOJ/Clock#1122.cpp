#include <iostream>
#include <cstdio>

using namespace std;

struct Clock {
    int h, m;
};

bool operator < (const Clock &c1, const Clock &c2) {
    return (c1.h < c2.h) || (c1.h == c2.h && c1.m < c2.m);
}

bool operator <= (const Clock &c1, const Clock &c2) {
    return (c1.h < c2.h) || (c1.h == c2.h && c1.m <= c2.m);
}

const Clock overlap[] = {{0,0}, {1,5}, {2,10}, {3,16}, {4,21}, {5,27}, {6,32},
                         {7,38},{8,43},{9,49},{10,54}, {12,0}, {13,5}, {14,10},
                         {15,16},{16,21},{17,27},{18,32},{19,38},{20,43},
                         {21,49},{22,54},{24,0} };

int main(int argc, char const *argv[])
{
    printf("Program 3 by team X\n");
    printf("Initial time  Final time  Passes\n");
    Clock t1, t2;
    while(scanf("%d%d%d%d", &t1.h, &t1.m, &t2.h, &t2.m) != EOF) {
        printf("       %02d:%02d       %02d:%02d      ", t1.h, t1.m, t2.h, t2.m);
        if(t2 < t1) {
            t2.h += 12;
        }
        if(t1.h >= 12){
            t1.h -= 12;
            t2.h -= 12;
        }
        int cnt = 0;
        for(int i = 0; i < 23; i++) {
            if(t1 <= overlap[i] && overlap[i] < t2) cnt++;
        }
        printf("%2d\n",cnt);
    }
    printf("End of program 3 by team X\n");
    return 0;
}
