#include<iostream>
using namespace std;
const int MAX_N = 20000+10;
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

int main(){
    int m,n;
    cin>>n>>m;
    while(m!=0||n!=0){
       int knights[MAX_N]={},dragon[MAX_N]={};
       bool ok = false;
       int tot = 0;
       for(int i=0;i<n;i++){
           cin>>dragon[i];
       }
       for(int j=0;j<m;j++){
           cin>>knights[j];
       }
       if(m>=n){
           sort1(dragon,0,n-1);
           sort1(knights,0,m-1);
           //cout<<"----dragon-----"<<endl;
           //for(int i=0;i<n;i++){
           //  cout<<dragon[i]<<endl;
           //}
           //cout<<"-----knights-----"<<endl;
           //for(int j=0;j<m;j++){
           //    cout<<knights[j]<<endl;
           //}
           //cout<<"----------"<<endl;
           int i=0, j=0;
           while(i<n&&j<m){
               if(knights[j]>=dragon[i]){
                   tot += knights[j];
                   i++;
                   j++;
               }
               else j++;
           }
           if(i==n) ok=true;
       }
       if(ok) cout<<tot<<endl;
       else cout<<"Loowater is doomed!"<<endl;
       cin>>n>>m;
    }
    return 0;
}
