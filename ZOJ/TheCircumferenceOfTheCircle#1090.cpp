#include<stdio.h>
#include<iostream>
#include<cmath>
#define pi 3.141592653589793
using namespace std;
int main()
{
    double x1,y1,x2,y2,x3,y3,a,b,c;
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3){
        a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
        c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
        printf("%.2f\n",2*pi*a*b*c/(sqrt((a+b+c)*(a+b-c)*(b+c-a)*(a+c-b))));
    }
    return 0;
}
