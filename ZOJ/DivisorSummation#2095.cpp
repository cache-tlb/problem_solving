#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		scanf("%d", &n);
		if(n==1){
			printf("0\n");
			continue;
		}
		int sum = 1;
		int k = (int)sqrt((double)n);
		for(int i = 2; i <= k; i++){
			if(n%i==0){
				sum += i;
				sum += n/i;
			}
		}
		if(k*k==n)
			sum -= k;
		printf("%d\n", sum);
	}
	return 0;
}
