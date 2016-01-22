/*#include<iostream>
using namespace std;
const int MAXN = 10;
int shift[] = {1,2,4,8,16,32,64,128,256,512,1024};
int howmany1(int x)
{
	int ans = 0;
	for(int i = 0; i <= MAXN; i++){
		if(x&shift[i]) ans++;
	}
	return ans;
}
int pos1(int x)
{
	for(int i = 0; i < MAXN; i++){
		if(x&shift[i]) return i;
	}
}
int main()
{
	int n;
	while(cin >> n){
		if(n==0) break;
		int a[MAXN+1][MAXN+1] = {};
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}
		int power[1<<MAXN] = {};
		for(int k = n - 1; k >= 1; k--){
			for(int i = 0; i < (1<<n); i++){
				int ni1 = howmany1(i);
				if(ni1!=k) continue;
				//cout << "i = " << i << endl;
				int maxpower = 0;
				for(int j = 0; j <= n; j++){
					//cout << "j=" << j << ',' << "shith[j]&i=";
					//if(shift[j]&i) cout << 1 << endl;
					//else cout << 0 << endl;
					if(!(shift[j]&i)){
						//cout << "j = " << endl;
						int p = i + shift[j];
						int tempmax = 0;
						for(int x = 0; x <= n; x++){
							if(i&shift[x]){
								if(tempmax<a[x][j]) tempmax = a[x][j];
							}
						}
						if(maxpower < power[p] + tempmax)
							maxpower = power[p] + tempmax;
					}
				}
				power[i] = maxpower;
			}
		}
		int ans = 0;
		for(int i = 0; i <= n-1; i++){
			if(power[shift[i]] > ans) ans = power[shift[i]];
		}
		cout << ans << endl;
	}
	return 0;
}*/
#include <stdio.h>  
int map[15][15];  
int cst[11]={1,2,4,8,16,32,64,128,256,512,1024};  
int dp[1200];  
int Max(int x,int y)  
{  
    return x>y?x:y;  
}  
int main()  
{  
    int n,i,j,k,ans;  
    while(1){  
        scanf("%d",&n);  
        if (n==0) break;  
        for (i=0;i<n;i++){
            for (j=0;j<n;j++){  
                scanf("%d",&map[i][j]);  
            }  
        }  
        for (i=0;i<cst[n];i++){  
            dp[i]=0;  
        }  
        for (i=0;i<cst[n];i++){	//对于每个状态进行拓展
            for (j=0;j<n;j++){	//枚举每一位，也就是说枚举每个原子将其和谐掉
                if ((i & cst[j])!=0) continue;//如果在状态i下该原子已经被和谐了，那么跳过看下一个原子  
                for (k=0;k<n;k++){	//否则找一个没有被和谐的原子和谐掉原子j
                    if ((i & cst[k])==0 && j!=k){	//这里有个小陷阱，没有加j!=k会WA，估计是测试数据i=j处的值有的不是0
                        dp[i|cst[j]]=Max(dp[i|cst[j]],dp[i]+map[k][j]);  
                    }    
                }  
            }  
        }  
        ans=0;  
        for (i=0;i<cst[n];i++){
            if (dp[i]>ans) ans=dp[i];  
        }  
        printf("%d\n",ans);  
    }  
    return 0;  
}  

