#include<iostream>
using namespace std;
const int MAXN = 30;
int main()
{
	int f[MAXN] = {};
	f[1] = 1;
	for(int i = 2; i < 30; i++){
		if(i%2)
			f[i] = 2*f[i-1] + 1;
		else
			f[i] = 2*f[i-1];
	}
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << f[n] << endl;
	}
	return 0;
}
