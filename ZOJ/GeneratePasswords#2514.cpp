#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int MAXN = 1002;
int main()
{
	int n;
	while(cin >> n){
		if(!n) break;
		string team[MAXN] = {};
		string pw[MAXN] = {};
		vector<int> vi;
		for(int i = 0; i < n; i++){
			cin >> team[i] >> pw[i];
			int len = pw[i].length();
			int ok = 1;
			for(int j = 0; j < len; j++){
				if(pw[i][j]=='1'){
					pw[i][j] = '@';
					ok = 0;
				}
				else if(pw[i][j]=='0'){
					pw[i][j] = '%';
					ok = 0;
				}
				else if(pw[i][j]=='l'){
					pw[i][j] = 'L';
					ok = 0;
				}
				else if(pw[i][j]=='O'){
					pw[i][j] = 'o';
					ok = 0;
				}
			}
			if(ok==0) vi.push_back(i);
		}
		int num = vi.size();
		if(!num)
			cout << "No account is modified." << endl;
		else{
			cout << num << endl;
			for(int i = 0; i < num; i++)
				cout << team[vi[i]] << ' ' << pw[vi[i]] << endl;
		}
	}
	return 0;
}
