#include<iostream>
#include<string>
using namespace std;
int table[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
int main()
{
	string str;
	while(cin >> str){
		int len = str.length();
		for(int j = 0; j < str.length(); j++){
			if(str[j]=='-'|| str[j]=='1' || str[j]=='0')
				cout << str[j];
			else if('A'<=str[j] && str[j]<='Z')
				cout << table[str[j]-'A'];
			else if('a'<=str[j] && str[j]<='z')
				cout << table[str[j]-'a'];
		}
		cout << endl;
	}
	return 0;
}
