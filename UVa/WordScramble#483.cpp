#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	while(getline(cin,s)){
		int len = s.length();
		string out;
		int p = 0, q = 0;
		while(p<len && q<len){
			while(p<len && s[p]==' '){
				out.push_back(' ');
				p++;
			}
			if(p>=len) break;
			q = p;
			while(q<len && s[q]!=' ') q++;
			int temp = q;
			q--;
			for(int i = q; i >= p; i--){
				out.push_back(s[i]);
			}
			p = temp;
		}
		cout << out << endl;
	}
	return 0;
}
