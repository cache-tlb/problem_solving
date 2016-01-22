#include <iostream>
#include <cstdio>
#include <list>
#include <string.h>

using namespace std;

struct point {
	int x,y;
	point(){}
	point(int _x, int _y){x=_x;y=_y;}
};

int N,M,T;
const int MAXN = 8;
int maze[MAXN][MAXN];
int min_dis[MAXN][MAXN];
int vis[MAXN][MAXN] = {};
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
point src, dst;
bool ok = false;
int cur_len = 0;

void try_add(int x, int y, int cur_dis, list<point> &q){
	if(x >= 0 && x < M && y >= 0 && y < N && maze[y][x] != -1 && !vis[y][x]){
		q.push_back(point(x,y));
		vis[y][x] = 1;
		min_dis[y][x] = cur_dis + 1;
	}
}

void estimate_min_dis(){
	memset(vis, 0, sizeof(vis));
	list<point> q;
	q.push_back(dst);
	min_dis[dst.y][dst.x] = 0;
	vis[dst.y][dst.x] = 1;
	while(!q.empty()){
		point cur = q.front();
		q.pop_front();
		for (int k = 0; k < 4; k++) {
			try_add(cur.x + dx[k], cur.y + dy[k], min_dis[cur.y][cur.x], q);
		}
	}

	/*cout << "+++++++++++++++" << endl;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(maze[i][j]!=-1) cout << min_dis[i][j] << ' ';
			else cout << "X" << ' ';
		}
		cout << endl;
	}*/
}

void dfs(int x, int y) {
	if(x==dst.x && y==dst.y){
		if(T == cur_len){
			ok = true;
		}
		return;
	}
	if(cur_len+min_dis[y][x]>T) return;
	cur_len++;
	maze[y][x] = -1;
	for(int k = 0; k < 4; k++){
		int newx = x+dx[k], newy = y+dy[k];
		if(newx>=0 && newx<M && newy>=0 && newy<N && maze[newy][newx]!=-1){
			dfs(newx, newy);
			if(ok) return;
		}
	}
	maze[y][x] = 0;
	cur_len--;
}

int main(int argc, char const *argv[])
{
	string line;
	while(cin >> N >> M >> T){
		if(!N && !M && !T) break;
		for (int i = 0; i < N; i++){
			cin >> line;
			for (int j = 0; j < M; j++) {
				if(line[j] == '.'){
					maze[i][j] = 0;
				}
				else if(line[j] == 'X'){
					maze[i][j] = -1;
				}
				else if(line[j] == 'S'){
					maze[i][j] = 0;
					src = point(j,i);
				}
				else if(line[j] == 'D'){
					maze[i][j] == 0;
					dst = point(j,i);
				}
			}
		}
		ok = false;
		cur_len = 0;
		estimate_min_dis();
		dfs(src.x, src.y);
		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
