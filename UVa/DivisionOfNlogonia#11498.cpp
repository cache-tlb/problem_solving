#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin >> n){
		if(n==0) break;
		int x, y;
		cin >> x >> y;
		for(int i = 0; i < n; i++){
			int a,b;
			cin >> a >> b;
			if(a==x||b==y){
				cout << "divisa" << endl;
				continue;
			}
			else{
				if(b>y) cout <<'N';
				else cout << 'S';
				if(a>x) cout << 'E';
				else cout << 'O';
				cout << endl;
			}
		}

	}
	return 0;
}
