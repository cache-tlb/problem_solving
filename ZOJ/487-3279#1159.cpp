#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;

const int MAXN = 100001;

const char maps[26] = {
	'2','2','2',
	'3','3','3',
	'4','4','4',
	'5','5','5',
	'6','6','6',
	'7','7','7','7',
	'8','8','8',
	'9','9','9','9'
};

string convert(string &s)
{
	int n = s.length();
	string res(7,'0');

	int pos = 0;
	for (int j = 0; j < n; j++){
		if('0' <= s[j] && s[j] <= '9'){
			res[pos] = s[j];
			pos++;
		} else if('A' <= s[j] && s[j] <= 'Z' && s[j] != 'Q' && s[j] != 'Z'){
			int index = s[j]-'A';
			res[pos] = maps[index];
			pos++;
		}
	}
	return res;
}

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		map<string,int> nums;
		for (int i = 0; i < n; i++){
			cin >> s;
			nums[convert(s)]++;
		}

		bool dup = false;
		for (map<string,int>::iterator it = nums.begin(); it != nums.end(); it++){
			const string &str = it->first;
			if(it->second <= 1) continue;
			for(int i = 0; i < 3; i++){
				cout << str[i];
			}
			cout << '-';
			for(int i = 3; i < 7; i++){
				cout << str[i];
			}
			cout << ' ' << it->second << endl;
			dup = true;
		}
		if(!dup) cout << "No duplicates." << endl;
		if(t!=0) cout << endl;
	}

	return 0;
}
