#include<iostream>
#include<iomanip>
using namespace std;

const int MAX = 1000 + 10;

struct trade{
    double j;
    double f;
    double a;
};
bool operator <=(const trade &x,const trade &y){
    return x.a <= y.a;
}    
void sort1(trade array[], int zz,int yy)
{
     int z,y;
     trade k;
     if(zz<yy)
     {
         z=zz;y=yy;k=array[z];
         do{
           while(z<y&&k<=array[y])y--;
             if(z<y)
             {
                 array[z]=array[y];
                 z++;   
             }       
           while(z<y&&array[z]<=k)z++;
           if(z<y)
             array[y]=array[z];               
         }while(z!=y);
         array[z]=k;
         sort1(array,zz,z-1);
         sort1(array,z+1,yy);    
     }
}

int main()
{
    int m, n;
    cout << setiosflags(ios::fixed) << setprecision(3);
    while(cin >> m >> n){
        trade tr[MAX];
        if((m == -1) && (n == -1)) break;
        double a, b;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            tr[i].j = a;
            tr[i].f = b;
            tr[i].a = a/b;
        }
        sort1(tr, 0, n - 1);
        double tot = 0.0;
        for(int i = n - 1; i >= 0; i--){
            if(m >= tr[i].f){
                tot += tr[i].j;
                m -= tr[i].f;
            }
            else {
                tot += m*tr[i].a;
                break;
            }
        }
        cout << tot <<endl;
    }    
    return 0;
}
