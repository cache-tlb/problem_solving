#include<iostream>
using namespace std;
const int MAX = 100 + 10;
int main()
{
	int t;
	cin >> t;
	while(t--){
		int a[MAX] = {}, b[MAX] = {};
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		int s = 1, q = 1;
		for(int i = 0; i < n; i++){
			cin >> b[i];
			if(a[i] != b[i]){
				q = 0;
			}
			if(b[i] != a[n-1-i]){
				s = 0;
			}
		}
		if(s&&q) cout << "both" << endl;
		else if(s) cout << "stack" << endl;
		else if(q) cout << "queue" << endl;
		else cout << "neither" << endl;
	}
	return 0;
}
