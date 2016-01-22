#include<iostream>
#include<string>
#include<map>
using namespace std;
const int MAXN = 200;
string table[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
	"....", "..", ".---", "-.-", ".-..", "--", "-.",
	"---", ".--.", "--.-", ".-.", "...", "-", "..-",
	"...-", ".--", "-..-", "-.--", "--.."};
string encode(char c)
{
	string ans = "";
	if(c>='A' && c<='Z'){
		ans = table[c-'A'];
		return ans;
	}
	switch(c){
		case '_':
			ans = "..--";
			break;
		case '.':
			ans = "---.";
			break;
		case ',':
			ans = ".-.-";
			break;
		case '?':
			ans = "----";
			break;
	}
	return ans;
}
int main()
{
	int t;
	cin >> t;
	map<string,char> m;
	for(int i = 0; i < 26; i++){
		m[table[i]] = 'A' + i;
	}
	m["..--"] = '_';
	m["---."] = '.';
	m[".-.-"] = ',';
	m["----"] = '?';
	for(int k = 0; k < t; k++){
		string s;
		cin >> s;
		cout << k+1 << ": ";
		string code = "";
		int codelen[MAXN] = {};
		int n = s.length();
		for(int i = 0; i < n; i++){
			string temp = encode(s[i]);
			code += temp;
			codelen[i] = temp.length();
		}
		/*cout << code << endl;
		for(int i = 0; i < n; i++){
			cout << codelen[i];
		}
		cout << endl;
		string rcode = "";
		for(int i = code.length()-1; i>=0; i--){
			rcode.push_back(code[i]);
		}*/
		int rlen[MAXN] = {};
		for(int i = 0; i < n; i++){
			rlen[i] = codelen[n-1-i];
		}
		int j = 0;
		for(int i = 0; i < n; i++){
			string ss = "";
			for(int ii = 0; ii < rlen[i]; ii++){
				ss.push_back(code[j]);
				j++;
			}
			cout << m[ss];
		}
		cout << endl;
	}
	return 0;
}
