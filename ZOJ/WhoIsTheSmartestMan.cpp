#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 502;
int main()
{
	int n;
	int ip;
	while(cin >> n){
		cin >> ip;
		int a[MAXN] = {};
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(&a[0], &a[n]);
		int p = 0;
		int cnt = 0;
		while(p<n){
			while(p<n && a[p]<=ip) p++;
			if(p>=n) break;
			ip += 2;
			cnt++;
			p++;
		}
		ip += (n-cnt);
		cout << ip << endl;
	}
	return 0;
}
