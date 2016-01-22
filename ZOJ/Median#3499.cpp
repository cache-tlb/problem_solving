#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
const int MAXN = 502;
int main()
{
	int t;
	cin >> t;
	cout << setiosflags(ios::fixed) << setprecision(3);
	while(t--){
		int n;
		cin >> n;
		double a[MAXN] = {};
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(&a[0], &a[n]);
		if(n%2)
			cout << a[(n-1)/2] << endl;
		else
			cout << (a[n/2-1] + a[n/2])/2.0 << endl;
	}
	return 0;
}
