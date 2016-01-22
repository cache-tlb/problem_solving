#include<stdio.h>
int mod(int a,int b)
{
    return a%b;
}    
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF){
        printf("%d\n",mod(a,b));
    }    
    return 0;
}    
