#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;
const int MAXN = 11;
int n = 0;
double m = 0.0;
bool lamp[MAXN] = {};	//all 1 is ok
double f[MAXN] = {};
vector<int> re[MAXN];
bool getit()
{
	for(int i = 0; i < n; i++)
		if(!lamp[i]) return false;
	return true;
}
int main()
{
	while(cin >> n >> m){
		if(!n && !m) break;
		memset(lamp, 0, sizeof(lamp));
		for(int i = 0; i < n; i++){
			re[i].clear();
		}
		for(int i = 0; i < n; i++){
			int t;
			cin >> t;
			while(t--){
				int temp;
				cin >> temp;
				re[i].push_back(temp - 1);
			}
			cin >> f[i];
			f[i] /= 100.0;
		}
		int bound = 1<<n;
		double ans = 0.0;
		for(int i = 0; i < bound; i++){
			int full = bound - 1;
			double left = m;
			for(int j = 0; j < n; j++){
				if((i>>j)&1){
					left *= 1 - f[j];
					full ^= 1<<j;
					for(int k = 0; k < re[j].size(); k++)
						full ^= 1<<re[j][k];
				}
			}
			if(!full && left>ans)
				ans = left;
		}
		if(ans >0.0)
			printf("%.2f\n", ans);
		else printf("-1\n");
	}
	return 0;
}
