#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int MAX = 20 + 10;
int maze[MAX][MAX] = {};
int vis[MAX][MAX] = {};
int ans = 0;
int w, h;
void bfs(int i, int j)
{
	if(i < 0 || i >= h || j < 0 || j >= w) return;
	if(vis[i][j] || maze[i][j] == 1) return;
	ans++;
	vis[i][j] = 1;
	 bfs(i - 1, j);
	 bfs(i + 1, j);
	 bfs(i, j - 1);
	 bfs(i, j + 1);
}
int main()
{
	while(cin >> w >> h){
		if(w==0 && h==0) break;
		string temp;
		memset(maze, 0, sizeof(maze));
		memset(vis, 0, sizeof(vis));
		int x = 0, y = 0;
		ans = 0;
		for(int i = 0; i < h; i++){
			cin >> temp;
			for(int j = 0; j < w; j++){//'.' - a black tile  ;'#' - a red tile  ;'@' - a man on a black tile
				if(temp[j] == '.') maze[i][j] = 0;
				else if(temp[j] == '#') maze[i][j] = 1;
				else if(temp[j] == '@'){
					maze[i][j] = 0;
					x = j;
					y = i;
				}
			}
		}
		//vis[y][x] = 1;
		bfs(y, x);
		cout << ans << endl;
	}
	return 0;
}
