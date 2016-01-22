#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--){
		int c = 1;
		int m, n;
		while(cin >> n >> m){
			if(m==0 && n==0) break;
			int cnt = 0;
			for(int a = 1; a < n - 1; a++){
				for(int b = a + 1; b < n; b++){
					if((a*a + b*b + m)%(a*b) == 0) cnt++;
				}
			}
			cout << "Case " << c << ": " << cnt << endl;
			c++;
		}
		if(t) cout << endl;
	}
	return 0;
}
