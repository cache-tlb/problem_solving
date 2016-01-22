#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	int s;
	cin >> s;
	for(int k = 1; k <= s; k++){
		int m,n;
		cin >> m >> n;
		printf("Scenario #%d:\n", k);
		double ans = 0.0;
		if(m%2 && n%2)
			ans = m*n + sqrt(2.0) - 1.0;
		else
			ans = m*n;
		printf("%.2f\n", ans);
		//if(k!=s)
			printf("\n");
	}
	return 0;
}
