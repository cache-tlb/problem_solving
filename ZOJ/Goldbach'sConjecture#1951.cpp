#include<stdio.h>
const int MAX = 1000000 + 10;
const int MAXNPRIME = 100000;
int prime[MAXNPRIME] = {};
int temp[MAX] = {};
void ini()
{
    int d = 2;
    do{
        int k = d;
        if(temp[k]==0){
            k += d;
            while(k <= MAX){
                temp[k] = 1;
                k += d;
            }
        }
        d++;
    }while(d*d<=MAX);
    int n = 0;
    for(int i = 2; i < MAX; i++){
        //if(n%1000==0)printf("%d\n",n);
        if(!temp[i]){
            prime[n] = i;
            n++;
            if(n==MAXNPRIME) break;
        }
    }        
}
int main()
{
    int n;
    ini();
    while(scanf("%d",&n)){
        if(n==0)break;
        for(int i = 0; i < MAXNPRIME; i++){
            int a = prime[i];
            int b = n - a;
            if(!temp[b]){
                printf("%d = %d + %d\n",n,a,b);
                break;
            }    
        }        
    }
    return 0;
}
