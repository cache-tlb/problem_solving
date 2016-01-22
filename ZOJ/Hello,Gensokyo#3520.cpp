#include<cstdio>
const int MAXN = 100003;
int main()
{
	long long n;
	while(scanf("%lld",&n)!=EOF){
		long long ans = 0;
		if(n%2){
			ans = (n*n-1)/4;
		}
		else{
			ans = (n/2)*(n/2);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
