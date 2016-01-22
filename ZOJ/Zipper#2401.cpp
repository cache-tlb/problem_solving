#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
const int MAXN = 300;
bool f[MAXN][MAXN] = {};
string a, b, s;

bool anylise(){
	int m = a.length(), n = b.length();
	if (m + n != s.length()) return false;

	for(int i = 0; i < m + 5; i++){
		for(int j = 0; j < n + 5; j++){
			f[i][j] = false;
		}
	}

	f[0][0] = true;
	for(int i = 1; i <= m; i++){
		if(a[i-1]==s[i-1]){
			f[i][0] |= f[i-1][0];
		}
	}
	for(int j = 1; j <= n; j++){
		if(b[j-1]==s[j-1]){
			f[0][j] |= f[0][j-1];
		}
	}

	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(a[i-1]==s[i+j-1]){
				f[i][j] |= f[i-1][j];
			}
			if(b[j-1]==s[i+j-1]){
				f[i][j] |= f[i][j-1];
			}
		}
	}

	return f[m][n];
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> a >> b >> s;
		bool ok = anylise();
		cout << "Data set " << i << ": ";
		if(ok) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}
