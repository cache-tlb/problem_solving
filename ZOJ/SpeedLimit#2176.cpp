#include<iostream>
using namespace std;
const int MAXN = 100;
int main(){
	int n;
	while(cin >> n){
		if(n==-1) break;
		int v[MAXN] = {}, t[MAXN] = {};
		for(int i = 0; i < n; i++){
			cin >> v[i] >> t[i];
		}
		int s = v[0]*t[0];
		for(int i = 1; i < n; i++){
			s += v[i]*(t[i]-t[i-1]);
		}
		cout << s << " miles" << endl;
	}
	return 0;
}
