#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <queue>

using namespace std;

struct point {
    int x, y, dis;
    point(){}
    point(int _x, int _y, int _d){x=_x;y=_y;dis=_d;}
};

bool operator < (const point &a, const point &b){
    return (a.dis > b.dis) || (a.dis == b.dis && a.x < b.x) || (a.dis == b.dis && a.x == b.x && a.y < b.y);
}

const int MAXN = 256;
int N, M;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int maze[MAXN][MAXN] = {};
int dis[MAXN][MAXN] = {};
point src;
int ans;

bool in_board(int x, int y){
    return (x >= 0 && x < M && y >= 0 && y < N);
}

void bfs(){
    ans = -1;
    priority_queue<point> q;
    q.push(src);
    while(!q.empty()){
        point p = q.top();
        q.pop();
        if(p.dis > dis[p.y][p.x]) continue;
        if(maze[p.y][p.x]==2){
            ans = p.dis;
            return;
        }
        dis[p.y][p.x] = p.dis;
        for(int k = 0; k < 4; k++){
            int newx = p.x+dx[k], newy = p.y+dy[k];
            if(in_board(newx, newy) && maze[newy][newx] != -1){
                int d = p.dis;
                if(maze[p.y][p.x] == 1){
                    d += 2;
                }
                else{
                    d += 1;
                }
                if(d < dis[newy][newx]){
                    dis[newy][newx] = d;
                    q.push(point(newx, newy, d));
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    string line;
    src.dis = 0;
    while(cin >> N >> M){
        if(!N && !M) break;
        for(int i = 0; i < N; i++){
            cin >> line;
            for(int j = 0; j < M; j++){
                if(line[j]=='.'){
                    maze[i][j] = 0;
                }
                else if(line[j]=='#'){
                    maze[i][j] = -1;
                }
                else if(line[j]=='r'){
                    maze[i][j] = 2;
                }
                else if(line[j]=='a'){
                    src.x = j;
                    src.y = i;
                    maze[i][j] = 0;
                }
                else if(line[j]=='x'){
                    maze[i][j] = 1;
                }
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                dis[i][j] = 10000000;
            }
        }
        bfs();
        /*for(int i = 0; i < N; i++){
            for (int j = 0; j < M; j++) {
                if(dis[i][j] <= 1000000)
                    cout << dis[i][j] << '\t';
                else if(maze[i][j]==-1)cout << '#' << '\t';
                else cout << -1 << '\t';
            }
            cout << endl;
        }*/
        if(ans != -1) cout << ans << endl;
        else cout << "Poor ANGEL has to stay in the prison all his life." << endl;
    }
    return 0;
}
