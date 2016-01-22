#include<iostream>
using namespace std;
const int col = 6;
const int row = 5;
bool a[row][col] = {}, b[row][col] = {};
bool valid()
{
	int i = row - 1;
	for(int j = 0; j < col; j++){
		bool temp = b[i][j];
		if(j > 0) temp ^= b[i][j-1];
		if(j < col-1) temp ^= b[i][j+1];
		temp ^= b[i-1][j];
		if(temp^a[i][j]) return false;
	}
	return true;
}
void work()
{
	int flag = 0;
	for(int k = 0; k < (1<<col); k++){
		int p = k;
		for(int i = 0; i < col; i++){
			b[0][i] = (bool)(p%2);
			p /= 2;
		}
		//for(int i = 0; i < col; i++) if(b[0][i]) cout<<1;else cout<<0;
		//cout<<endl;
		for(int i = 1; i < row; i++){
			for(int j = 0; j < col; j++){
				bool temp = b[i-1][j];
				if(j < col - 1) temp ^= b[i-1][j+1];
				if(j > 0) temp ^= b[i-1][j-1];
				if(i > 1) temp ^= b[i-2][j];
				temp ^= a[i-1][j];
				b[i][j] = temp;
			}
		}
		if(valid()){
			flag = 1;
			break;
		}
		if(flag) break;
	}
	return;
}
int main()
{
	int t;
	cin >> t;
	int round = 1;
	while(t--){
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				int temp;
				cin >> temp;
				if(temp) a[i][j] = true;
				else a[i][j] = false;
			}
		}
		cout << "PUZZLE #" << round << endl;
		work();
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				if(b[i][j]) cout << 1;
				else cout << 0;
				if(j != col-1)cout << ' ';
				else cout << endl;
			}
		}
		round++;
	}
	return 0;
}
