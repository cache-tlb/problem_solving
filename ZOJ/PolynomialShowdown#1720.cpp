#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

void print_x(int pos) {
    if(pos==1){
        printf("x");
    }
    else if(pos >= 2){
        printf("x^%d", pos);
    }
}

void print_coe(int pos, int val, int first) {
    if(first){
        if(val != 1 && val != -1) printf("%d", val);
        else if(val==-1) printf("-");
        print_x(pos);
    }
    else{
        if(val==0) return;
        if(val==1 && pos != 0) printf(" + ");
        else if(val==-1 && pos != 0) printf(" - ");
        else if(val < 0) printf(" - %d", -val);
        else printf(" + %d", val);
        print_x(pos);
    }
}

int main(int argc, char const *argv[])
{
    int a[9];
    while(scanf("%d%d%d%d%d%d%d%d%d", a+8, a+7, a+6, a+5, a+4, a+3, a+2, a+1, a) != EOF) {
        int start = -1;
        for(int i = 8; i >= 0; i--){
            if(a[i]){
                start = i;
                break;
            }
        }
        if(start == -1){
            printf("0\n");
            continue;
        }
        if(start == 0){
            printf("%d\n", a[0]);
            continue;
        }
        print_coe(start, a[start], 1);
        for(int i = start - 1; i >= 0; i--){
            print_coe(i, a[i], 0);
        }
        printf("\n");
    }
    return 0;
}

