#include<iostream>
#include<string>
#include<map>
#include<cstdio>
using namespace std;
int main()
{
	//freopen("in.txt", "r", stdin);
	map<string,int> ms;
	string s;
	string pre, suf;
	while(cin >> s){
		ms[s] = s.length();
	}
	for(map<string,int>::iterator it = ms.begin(); it != ms.end(); it++){
		//cout << it->first << endl;
		int len = it->second;
		int ok = 0;
		for(int j = 1; j < len - 1; j++){
			pre = (it->first).substr(0,j);
			suf = (it->first).substr(j);
			if(ms.find(pre)!=ms.end() && ms.find(suf)!=ms.end()){
				ok = 1;
				break;
			}
		}
		if(ok)
			cout << it->first << endl;
	}
	return 0;
}
