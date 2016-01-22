#include<iostream>
#include<string>
using namespace std;
const int MAXLEN = 80;
int n = 0;
int a[MAXLEN] = {};
void getpro(int k, int b[])
{
	int c = 0;
	for(int i = 0; i <n; i++){
		int pro = a[i]*k + c;
		b[i] = pro%10;
		c = pro/10;
	}
	b[n] = c;
}
bool test(int k)
{
	int b[MAXLEN] = {};
	getpro(k,b);
	/*for(int i = n-1; i >=0 ;i--)
		cout << b[i];
	cout << endl;*/
	for(int i = n-1; i >= 0; i--){
		if(a[i]!=b[n-1]) continue;
		int ok = 1;
		for(int j = 0; j < n; j++){
			if(a[(i+n-j)%n] != b[n-1-j]){
				ok = 0;
				break;
			}
		}
		if(ok) return true;
	}
	return false;
}
int main()
{
	string s;
	while(cin >> s){
		n = s.length();
		for(int i = 0; i < n; i++){
			a[i] = s[n-i-1] - '0';
		}
		/*for(int i = n-1; i >= 0; i--){
			cout << a[i];
		}*/
		int ok = 1;
		for(int k = 2; k <= n; k++){
			if(!test(k)){
				//cout << "k=" << k << endl;
				ok = 0;
				break;
			}
		}
		cout << s << " is ";
		if(!ok) cout << "not ";
		cout << "cyclic" << endl;
	}
	return 0;
}
