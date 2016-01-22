#include<iostream>
using namespace std;
const int MAX = 100+10;
int cal(int x){
    int cnt = 0;
    while(x){
        if(x%2) cnt++;
        x = x/2;
    }
    return cnt;
}
void sort1(int array[], int zz,int yy)
{
     int z,y,k;
     if(zz<yy)
     {
         z=zz;y=yy;k=array[z];
         do{
           while(z<y&&array[y]>=k)y--;
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
    int T;
    cin >> T;
    while(T--){
        int m,n;//m for |A|,n for |B|
        cin>>m>>n;
        int a[MAX]={},b[MAX]={};
        for(int i=0;i<m;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        sort1(a,0,m-1);
        for(int i=0;i<n;i++){
            int pos = 0;
            int mini = 100;
            for(int j=0;j<m;j++){
                int differ = b[i]^a[j];
                int temp = cal(differ);
                if(temp<mini){
                    mini = temp;
                    pos = j;
                }
            }
            cout<<a[pos]<<endl;
        }
    }
    return 0;
}
