#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int ans = 0;
		int a[4];
		cin >> a[0] >> a[1] >> a[2];
		sort(&a[0],&a[3]);
		ans = a[1];
		cout << "Case " << i + 1 << " : " << ans << endl;
	}
	return 0;
}
