/*#include<iostream>
#include<map>
using namespace std;
const int MAXN = 34;
int sum = 0;
int n = 0;
int ntype = 0;
int power[MAXN] = {};
int ans = 0;
int flag = 0;
int counts[MAXN] = {};
void dfs(int start, int s)
{
	if(s*2>sum) return;
	else if(s*2==sum){
		flag = 1;
		ans = 0;
		return;
	}
	if(ans>sum-s*2) ans = sum-s*2;
	int temp = s+power[start];
	for(int i = start; i < ntype; i++){
		if((s+power[i])*2>sum) return;
		if(counts[i]==0) continue;
		counts[i]--;
		dfs(i,temp);
		if(flag) return;
		counts[i]++;
	}
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
             if(z<y){
                 array[y]=array[z];
         }
         }while(z!=y);
         array[z]=k;
         sort1(array,zz,z-1);
         sort1(array,z+1,yy);
     }
}
int main()
{
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		map<int,int> mi;
		sum = 0;
		for(int i = 0; i < n; i++){
			cin >> power[i];
			sum += power[i];
			mi[power[i]]++;
		}
		//sort1(power,0,n-1);
		int pp[MAXN] = {}, cc[MAXN] = {};
		ntype = 0;
		for(map<int,int>::iterator it=mi.begin();it!=mi.end();it++){
			pp[ntype] = it->first;
			cc[ntype] = it->second;
			ntype++;
		}
		//cout << ntype << endl;
		for(int i = 0; i < ntype; i++){
			power[i] = pp[ntype-1-i];
			counts[i] = cc[ntype-1-i];
		}
		flag = 0;
		ans = 20000000;
		//counts[0]--;
		dfs(0,0);
		cout << ans << endl;
	}
	return 0;
}*/
//先将n个数分成n/2和n-n/2两个部分,分别枚举2^(n/2)和2^(n-n/2)种状态,分别为设A,B,假设第一组中有x在A中,
//有y种在B中,则第一组为x+y,第二组为(A-x)+(B-y),差为x+y-(A-x)-(B-y)=2x+2y-(A+B),
//再枚举x，二分查找y,找出最小值
#include<iostream>
#include<cstdio>
using namespace std;
int que1[150000],que2[150000],ans1,ans2;
int a[50],n,m;
void quicksort1(int low,int high)
{
       int t,i,j;
       i=low;
       j=high;
       if(low<high)
       {
              t=que1[low];
              while(i!=j)
              {    
                     while(que1[j]>t&&i<j)j--;
                     if(i<j)
                     {
                            que1[i]=que1[j];
                            i++;
                     }
                     while(que1[i]<t&&i<j)i++;
                     if(i<j)
                     {
                            que1[j]=que1[i];
                            j--;
                     }
              }
              que1[i]=t;
              quicksort1(low,i-1);
              quicksort1(i+1,high);
       }
}
void quicksort2(int low,int high)
{
       int t,i,j;
       i=low;
       j=high;
       if(low<high)
       {
              t=que2[low];
              while(i!=j)
              {
                     while(que2[j]>t&&i<j)j--;
                     if(i<j)
                     {
                            que2[i]=que2[j];
                            i++;
                     }
                     while(que2[i]<t&&i<j)i++;
                     if(i<j)
                     {
                            que2[j]=que2[i];
                            j--;
                     }
              }
              que2[i]=t;
              quicksort2(low,i-1);
              quicksort2(i+1,high);
       }
}
void dfs1(int x,int y)
{
       if(x>n)
       {
              ans1++;
              que1[ans1]=y;
              return;
       }
       dfs1(x+1,y);
       dfs1(x+1,y+a[x]);
}
void dfs2(int x,int y)
{
       if(x>m)
       {
              ans2++;
              que2[ans2]=y;
              return;
       }
       dfs2(x+1,y);
       dfs2(x+1,y+a[x]);
}
int main()
{
       int i,cas,t,sum,p,min;
       scanf("%d",&cas);
       while(cas--)
       {
              sum=0;
              scanf("%d",&m);
              for(i=1;i<=m;i++)
              {
                     scanf("%d",&a[i]);
                     sum+=a[i];
              }
              n=m/2;
              ans1=0;
              dfs1(1,0);
              ans2=0;
              dfs2(n+1,0);
              quicksort1(1,ans1);
              quicksort2(1,ans2);
              t=1;
              for(i=2;i<=ans1;i++)
              {
                     if(que1[i]!=que1[t]){t++;que1[t]=que1[i];}
              }
              ans1=t;
              t=1;
              for(i=2;i<=ans2;i++)
              {
                     if(que2[i]!=que2[t]){t++;que2[t]=que2[i];}
              }
              ans2=t;
              int res;
              int left,right,mid;
              min=100000000;
              for(i=1;i<=ans1;i++)
              {
                     p=sum-2*que1[i];
                     if(p<0)p*=-1;
                     left=1;right=ans2;
                     while(left<=right)
                     {
                            mid=(left+right)/2;
                            res=que1[i]*2+que2[mid]*2-sum;
                            if(res<0)res*=-1;
                            if(res<min)min=res;
                            if(que2[mid]*2<p)left=mid+1;
                            else if(que2[mid]*2>p)right=mid-1;
                            else {min=0;break;}
                     }
                     if(!min)break;
              }
              printf("%d\n",min);
       }
       return 0;
}

