#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double distance_2d(double a1x,double a1y,double b1x,double b1y) 
{
    return (sqrt((a1x-b1x)*(a1x-b1x)+(a1y-b1y)*(a1y-b1y)));
}
//外公切线交点
void common_tangent_lines_Intersection(double x[3],double y[3],double r[3])
{
    double dis,temp;
    dis = distance_2d(x[0],y[0],x[1],y[1]);
    if(r[0] == r[1]){
        printf("Impossible.\n");
        return ;
    }
    if(fabs(r[0]-r[1])>=dis){
        printf("Impossible.\n");
        return ;
    }
    if(r[0] > r[1]){
        temp = r[0];r[0] = r[1];r[1] = temp;
        temp = x[0];x[0] = x[1];x[1] = temp;
        temp = y[0];y[0] = y[1];y[1] = temp;
    }
    x[2] = (x[0]-x[1])/(r[1]-r[0])*r[0]+x[0];
    y[2] = (y[0]-y[1])/(r[1]-r[0])*r[0]+y[0];
    printf("%.2lf %.2lf\n",x[2],y[2]);
}

int main()
{
    int n,i,j;
    double x[3],y[3],r[3];
    while (scanf("%d",&n)!=EOF){
        for (j=0;j<n;j++){
            for(i=0;i<2;i++){
                scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
            }
            common_tangent_lines_Intersection(x,y,r);
        }
    }
    return 0;
}
