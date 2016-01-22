#include<iostream>
#include<string>
using namespace std;
const int MAXN = 200;
int main()
{
	int t;
	cin >> t;
	while(t--){
		string s[MAXN];
		int top = 1, cur = 0;
		s[0] = "http://www.acm.org/";
		string cmd, URL;
		while(cin >> cmd){
			if(cmd=="QUIT") break;
			if(cmd=="VISIT"){
				cin >> URL;
				cur++;
				s[cur] = URL;
				top = cur + 1;
				cout << URL << endl;
			}
			else if(cmd=="BACK"){
				if(cur > 0){
					cur--;
					cout << s[cur] << endl;
				}
				else
					cout << "Ignored" << endl;
			}
			else if(cmd=="FORWARD"){
				if(cur < top-1){
					cur++;
					cout << s[cur] << endl;
				}
				else
					cout << "Ignored" << endl;
			}
		}
		if(t) cout << endl;
	}
	return 0;
}
