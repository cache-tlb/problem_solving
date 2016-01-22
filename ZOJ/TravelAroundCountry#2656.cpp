#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 10002;
int main()
{
	int n;
	while(cin >> n){
		int O[MAXN] = {};
		int D[MAXN] = {};
		for(int i = 0; i < n; i++)
			scanf("%d %d",&O[i], &D[i]);
		int ans = -1;
		for(int i = 0; i < n; i++){
			int cur = i, oil = O[i];
			int ok = 1;
			for(int j = 0; j < n; j++){
				int plc = (i+j)%n;
				if(oil<D[plc]){
					ok = 0;
					break;
				}
				oil -= D[plc];
				oil += O[(plc+1)%n];
			}
			if(ok){
				ans = i;
				break;
			}
		}
		if(ans==-1)
			cout << "impossible" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
