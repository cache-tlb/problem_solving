#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--){
		int y, m, d;
		cin >> y >> m >> d;
		int ans = 0;
		if(m==2 && d==28) ans = 1;
		else if(m==9 && d==30) ans = 1;
		else if(m==11 && d==30) ans = 1;
		else if((m+d)%2 == 0) ans = 1;
		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
