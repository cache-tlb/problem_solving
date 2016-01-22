#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin >> n){
		int cur = 1, ans = 1, mod = 1;
		while(cur%n!=0){
			mod = (mod*10)%n;
			cur = (cur+mod)%n;
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
