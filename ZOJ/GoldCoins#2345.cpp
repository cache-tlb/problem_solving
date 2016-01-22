#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		while(cin >> n){
			if(n==0) break;
			cout << n << ' ';
			int sum = 0;
			int m = 1;//m for delta
			int d = 0;
			while(d + m < n){
				sum += m*m;
				d += m;
				m++;
			}
			sum += (n-d)*m;
			cout << sum << endl;
		}
		if(t) cout << endl;
	}
	return 0;
}
