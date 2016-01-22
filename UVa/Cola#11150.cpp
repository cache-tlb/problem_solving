#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin >> n){
		int ans = 0;
		if(n%2){
			ans = (n + 1)/2*3 - 2;
		}
		else{
			ans = n/2*3;
		}
		cout << ans << endl;
	}
	return 0;
}
