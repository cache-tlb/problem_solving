#include <iostream>
#include <cstdio>
using namespace std;

/*
Position        Slow.Speed      Min.Weight      Min.Strength
Wide Receiver       4.5         150                 200
Lineman             6.0         300                 500
Quarterback         5.0         200                 300
*/
double a[3][3] = {{4.5,150,200},{6.0,300,500},{5.0,200,300}};

double speed, weight, strength;

bool check_WR(){
    return speed <= a[0][0] && weight >= a[0][1] && strength >= a[0][2];
}

bool check_L(){
    return speed <= a[1][0] && weight >= a[1][1] && strength >= a[1][2];
}

bool check_Q(){
    return speed <= a[2][0] && weight >= a[2][1] && strength >= a[2][2];
}

int main(int argc, char const *argv[])
{
    while(scanf("%lf%lf%lf", &speed, &weight, &strength) != EOF){
        if(speed==0 && weight==0 && strength==0) break;
        int tot = 0;
        if(check_WR()){
            printf("Wide Receiver");tot++;
        }
        if(check_L()){
            if(tot++) printf(" ");
            printf("Lineman");
        }
        if(check_Q()){
            if(tot++) printf(" ");
            printf("Quarterback");
        }
        if(!tot) printf("No positions\n");
        else printf("\n");
    }
    return 0;
}
