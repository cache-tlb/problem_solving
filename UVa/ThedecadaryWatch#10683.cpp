#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	const int total = 24*60*60*100;
	int n;
	while((scanf("%d",&n))!=EOF){
		int h = n/1000000;
		n%=1000000;
		int min = n/10000;
		n%=10000;
		int sec = n/100;
		n%=100;
		int cc = n;
		int time = h;
		time = time*60 + min;
		time = time*60 + sec;
		time = time*100 + cc;
		double d = (double)time/(double)total*10000000.0;
		int ans = (int)d;
		printf("%07d\n",ans);
	}
	return 0;
}
