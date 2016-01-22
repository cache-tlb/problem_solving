#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--){
		unsigned int n;
		cin >> n;
		unsigned int x = 1;
		int ans = 0;
		while(x<=n){
			x *= 2;
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
