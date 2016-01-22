#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 10000002;
bool uf[MAXN] = {};
int main()
{
	int L, n1, n2;
	int x, y;
	while(scanf("%d%d%d", &L, &n1, &n2)!=EOF){
		memset(uf, 0, sizeof(uf));
		int temp = n1 + n2;
		while(temp--){
			scanf("%d%d", &x, &y);
			for(int i = x; i <= y; i++){
				uf[i] = !uf[i];
			}
		}
		int ans = 0, tmp = 0;
		for(int i = 0; i <= L; i++){
			if(uf[i]) tmp++;
			if(!uf[i] || i==L){
				if(tmp>ans) ans = tmp;
				tmp = 0;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
