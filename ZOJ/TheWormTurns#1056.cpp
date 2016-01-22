#include<iostream>
#include<string>
using namespace std;
const int LEN = 20;
const int SIZE = 50;
struct coordinate{
	int x,y;
};
bool operator ==(coordinate p1, coordinate p2)
{
	if(p1.x==p2.x && p1.y==p2.y)
		return true;
	else return false;
}
int main()
{
	int n;
	while(cin >> n){
		if(n==0)break;
		int board[SIZE+1][SIZE+1] = {};
		coordinate pos[LEN] = {};
		for(int i = 11; i <= 30; i++){
			board[25][i] = 1;
		}
		for(int i = 0; i < LEN; i++){
			pos[i].x = 25;
			pos[i].y = 30 - i;
		}
		int status = 0;
		string dir = "";
		cin >> dir;
		int temp = -1;
		for(int k = 0; k < n; k++){
			int x = pos[LEN-1].x, y = pos[LEN-1].y;
			board[x][y] = 0;
			for(int i = LEN-1; i >=1; i--){
				pos[i] = pos[i-1];
			}
			if(dir[k]=='E'){
				pos[0].y++;
				if(pos[0].y>SIZE){
					status = 1;
					temp = k;
					break;
				}
			}
			else if(dir[k]=='W'){
				pos[0].y--;
				if(pos[0].y<1){
					status = 1;
					temp = k;
					break;
				}
			}
			else if(dir[k]=='N'){
				pos[0].x--;
				if(pos[0].x<1){
					status = 1;
					temp = k;
					break;
				}
				
			}
			else if(dir[k]=='S'){
				pos[0].x++;
				if(pos[0].x>SIZE){
					status = 1;
					temp = k;
					break;
				}
			}
			if(board[pos[0].x][pos[0].y]){
				status = 2;
				temp = k;
				break;
			}
			else board[pos[0].x][pos[0].y] = 1;
		}
		if(status==0)
			cout << "The worm successfully made all " << n << " moves." << endl;
		else if(status==2)
			cout << "The worm ran into itself on move " << temp+1 << '.' << endl;
		else
			cout << "The worm ran off the board on move " << temp+1 << '.' << endl;
	}
	return 0;
}
