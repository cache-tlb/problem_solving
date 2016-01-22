#include<iostream>
using namespace std;
int line[32767] = {};
void init()
{
	line[2] = 1;
	for(int i = 3; i < 32768; i++){
		line[i] = line[i-1] + i - 1;
	}
}
int main()
{
	init();
	int t;
/*	for(int i = 0; i < 10; i++){
		cout << line[i] << endl;
	}*/
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int ans = 0;
		if(n%2==0){
			ans = line[n/2]*2;
		} else{
			ans = line[n/2] + line[n/2 + 1];
		}
		cout << ans << endl;
	}
	return 0;
}
