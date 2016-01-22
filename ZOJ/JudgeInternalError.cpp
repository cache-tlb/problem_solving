#include<iostream>
using namespace std;
const int MAXP = 10000;
const int MAXN = 1000 + 10;
int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >>n;
		int a[MAXP] = {};
		for(int i = 0; i < n; i++){
			int temp;
			cin >> temp;
			a[temp]++;
		}
		int ans = 0, maxerr = 0;
		for(int i = 0; i < MAXP; i++){
			if(maxerr<=a[i]){
				maxerr = a[i];
				ans = i;
			}
		}
		cout << ans  << endl;
	}
	return 0;
}
