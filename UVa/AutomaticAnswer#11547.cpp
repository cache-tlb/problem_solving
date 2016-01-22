#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		n *= 63;
		n += 7492;
		n *= 5;
		n -= 498;
		n %= 100;
		n /= 10;
		if(n >=0) cout << n << endl;
		else cout << -n << endl;
	}
	return 0;
}
