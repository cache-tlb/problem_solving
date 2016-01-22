#include<iostream>
using namespace std;
int dig(int x){
	int ans = 0;
	while(x){
		ans++;
		x /= 10;
	}
	return ans;
}
int main()
{
	cout << "PERFECTION OUTPUT" << endl;
	int n;
	while(cin >> n){
		if(n==0) break;
		int d = dig(n);
		for(int i = 0; i < 5 - d; i++) cout << ' ';
		cout << n;
		int m = 0;
		int sum = 0;
		for(int i = 1; i < n; i++){
			if(n%i==0) sum += i;
		}
		if(sum<n) cout << "  DEFICIENT" << endl;
		else if(sum>n) cout << "  ABUNDANT" << endl;
		else cout << "  PERFECT" << endl;
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}
