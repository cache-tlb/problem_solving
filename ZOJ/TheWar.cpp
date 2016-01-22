#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
const int MAXN = 2500 + 10;
const int MAXM = 40000 + 10;
const int MAXW = 1000 + 10;
struct person{
	int minw;
	int maxw;
};
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
void sort2(person array[], int zz,int yy)
{
     int z,y;
	 person k;
     if(zz<yy)
     {
         z=zz;y=yy;k=array[z];
         do{
           while(z<y&&array[y].maxw>=k.maxw)y--;
             if(z<y)
             {
                 array[z]=array[y];
                 z++;   
             }       
           while(z<y&&array[z].maxw<=k.maxw)z++;
           if(z<y)
             array[y]=array[z];               
         }while(z!=y);
         array[z]=k;
         sort2(array,zz,z-1);
         sort2(array,z+1,yy);    
     }
}

int main()
{
	int n,m;
	while(cin >> n >> m){
		person a[MAXN] = {};
		int w[MAXM] = {};
		for(int i = 0; i < n; i++){
			scanf("%d%d", &a[i].minw, &a[i].maxw);
		}
		for(int i = 0; i < m; i++){
			scanf("%d", &w[i]);
		}
		sort1(w, 0, m - 1);
		sort2(a, 0, n - 1);
		int p = m - 1, q = n - 1;
		int visit[MAXN] = {};
		int ans = 0;
		while(p>=0 && q>=0){
			while(q>=0 && visit[q]) q--;
			while(p>=0 && w[p]>a[q].maxw) p--;
			if(p<0 || q<0) break;
			int curw = w[p];
			int rear = q, front = q;	//rear inclusive
			while(front>=0 && a[front].maxw>=curw) front--;
			int maxstart = 0, pos = rear, find = 0;
			for(int i = rear; i > front; i--){
				if(a[i].minw>=maxstart && a[i].minw<=curw && !visit[i]){
					find = 1;
					pos = i;
					maxstart = a[i].minw;
				}
			}
			if(find){
				visit[pos] = 1;
				ans++;
			}
			p--;
		}
		cout << ans << endl;
	}
	return 0;
}
