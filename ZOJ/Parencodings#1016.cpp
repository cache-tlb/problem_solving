#include<iostream>
#include<string>
using namespace std;
const int MAXN = 100;
int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int p[MAXN] = {};
		for(int i = 0; i < n; i++)
			cin >> p[i];
		string s = "";
		int pre = 0, cur = 0;
		for(int i = 0; i < n; i++){
			cur = p[i];
			for(int j = 0; j < cur - pre; j++)
				s.push_back('(');
			s.push_back(')');
			pre = cur;
		}
		//cout << s << endl;
		int len = s.length();
		int w[MAXN] = {};
		int ptr = 0;
		int nw = 0;
		while(ptr < len){
			if(s[ptr]=='('){
				ptr++;
				continue;
			}
			int cnt = 1, q = ptr - 1, flag = 1;
			while(flag){
				if(s[q]=='(')
					flag--;
				else if(s[q]==')'){
					flag++;
					cnt++;
				}
				q--;
			}
			w[nw++] = cnt;
			ptr++;
		}
		for(int i = 0; i < nw; i++){
			cout << w[i];
			if(i==nw-1)
				cout << endl;
			else cout << ' ';
		}
	}
	return 0;
}
