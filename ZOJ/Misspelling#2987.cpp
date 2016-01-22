#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for(int k = 0; k < t; k++){
		int n;
		string s;
		cin >> n >> s;
		cout << k+1 << ' ';
		for(int i = 0; i < s.length(); i++){
			if(i!=n-1) cout << s[i];
		}
		cout << endl;
	}
	return 0;
}
