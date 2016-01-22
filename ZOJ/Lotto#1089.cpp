#include<iostream>
using namespace std;
const int MAXN = 15;
int n = 0;
int a[MAXN] = {};
int flag[MAXN] = {};
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
             if(z<y){
                 array[y]=array[z];
         }
         }while(z!=y);
         array[z]=k;
         sort1(array,zz,z-1);
         sort1(array,z+1,yy);
     }
}
void work(int start, int depth)
{
	if(depth==6){
		int first = 1;
		for(int i = 0; i < n; i++){
			if(flag[i]){
				if(first) first = 0;
				else cout << ' ';
				cout << a[i];
			}
		}
		cout << endl;
		return;
	}
	for(int i = start+1; i < n; i++){
		flag[i] = 1;
		work(i,depth+1);
		flag[i] = 0;
	}
}
int main()
{
	int first = 1;
	while(cin >> n){
		if(n==0) break;
		if(first) first = 0;
		else cout << endl;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			flag[i] = 0;
		}
		sort1(a,0,n-1);
		for(int i = 0; i < n; i++){
			flag[i] = 1;
			work(i,1);
			flag[i] = 0;
		}
	}
	return 0;
}
