#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int ok = 1;
		int a = 0, b = 0;
		for(int i = 0; i < n; i++){
			int color = 0;
			cin >> color;
			if(color==0){
				if(i%2) a++;
				else b++;
			}
		}
		if(n%2) cout << "YES" << endl;
		else if(a>b && a-b>1){
			cout << "NO" << endl;
		}
		else if(a<b && b-a>1){
			cout << "NO" << endl;
		}
		else cout << "YES" << endl;
	}
	return 0;
}
