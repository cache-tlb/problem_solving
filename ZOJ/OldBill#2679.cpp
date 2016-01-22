#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int p = 0;
		int a, b, c;
		cin >> a >> b >> c;
		p = 1000*a + 100*b + 10*c;
		int flag = 0, ans1 = 0, ans2 = 0, ans3;
		for(int i = 9; i > 0; i--){
			for(int j = 9; j >= 0; j--){
				int newp = 10000*i + j + p;
				if(newp%n == 0){
					flag = 1;
					ans1 = i;
					ans2 = j;
					ans3 = newp;
					break;
				}
			}
			if(flag) break;
		}
		if(flag) cout << ans1 << ' ' << ans2 << ' ' << ans3/n << endl;
		else cout << 0 << endl;
	}
	return 0;
}
