#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const int MAXN = 12;
int main()
{
	int nrow, ncol, entry;
	while(cin >> nrow >> ncol >> entry){
		if(!nrow && !ncol && !entry) break;
		string s;
		char ins[MAXN][MAXN] = {};
		int vis[MAXN][MAXN] = {};
		for(int i = 0; i < nrow; i++){
			cin >> s;
			for(int j = 0; j < ncol; j++){
				ins[i][j] = s[j];
			}
		}
		int row = 0, col = entry - 1;
		int status = 0, step = 1, ans = 0, ans2 = 0;
		while(1){
			vis[row][col] = step;
			if(ins[row][col]=='N'){
				row--;
			}
			else if(ins[row][col]=='S'){
				row++;
			}
			else if(ins[row][col]=='W'){
				col--;
			}
			else if(ins[row][col]=='E'){
				col++;
			}
			if(row<0 || row>=nrow || col <0 || col>=ncol){
				status = 1;	//out
				ans = step;
				break;
			}
			else if(vis[row][col]){
				status = 2;	//circle
				ans2 = step - vis[row][col] + 1;
				ans = vis[row][col] - 1;
				break;
			}
			step++;
		}
		if(status==1)
			cout << ans << " step(s) to exit" << endl;
		else
			cout << ans << " step(s) before a loop of " << ans2 << " step(s)" << endl;
	}
	return 0;
}
