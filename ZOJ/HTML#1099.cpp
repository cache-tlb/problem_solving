#include<iostream>
#include<string>
using namespace std;
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
	char hr[100];
	for(int i = 0; i < 80; i++)
		hr[i] = '-';
	hr[80] = 0;
	string s;
	int len = 0, first = 1;
	while(cin >> s){
		if(s[0]=='<'){
			if(s[1]=='h'){
				if(!first)
					cout << endl << hr << endl;
				else cout << hr << endl;
				len = 0;
				first = 1;
			}
			else if(s[1]=='b'){
				cout << endl;
				len = 0;
				first = 1;
			}
			continue;
		}
		if(len+s.length()<80){
			if(first){
				first = 0;
				cout << s;
				len += s.length();
			}
			else{
				cout << ' ' << s;
				len += s.length()+1;
			}
		}
		else{
			cout << endl;
			cout << s;
			len = s.length();
		}
	}
	cout << endl;
	return 0;
}
