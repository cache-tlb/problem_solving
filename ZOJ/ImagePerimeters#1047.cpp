#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct Point {
    int r, c;
    Point(){}
    Point(int _r, int _c):r(_r),c(_c){}
};

const int MAXN = 32;
const int dx[] = {-1,1,0,0,-1,-1,1,1};
const int dy[] = {0,0,-1,1,-1,1,-1,1};
int visit[MAXN][MAXN] = {};
int maze[MAXN][MAXN] = {};
char buf[MAXN] = {};
int N, M, mouse_row, mouse_col;


inline bool in_board(int i, int j) {
    return (i >= 0 && i < N && j >= 0 && j < M);
}

int calc_perimeter() {
    if(!maze[mouse_row][mouse_col]) return 0;
    queue<Point> q;
    vector<Point> points;
    q.push(Point(mouse_row, mouse_col));
    visit[mouse_row][mouse_col] = 1;
    while(!q.empty()){
        Point p = q.front();
        q.pop();
        points.push_back(p);
        for(int k = 0; k < 8; k++){
            int newy = p.r + dy[k], newx = p.c + dx[k];
            if(in_board(newy, newx) && !visit[newy][newx] && maze[newy][newx]==1){
                q.push(Point(newy, newx));
                visit[newy][newx] = 1;
            }
        }
    }
    int common_edge = 0;
    for(vector<Point>::iterator it = points.begin(); it != points.end(); it++) {
        int row = it->r, col = it->c;
        for(int k = 0; k < 4; k++){
            if(in_board(row+dy[k], col+dx[k]) && maze[row+dy[k]][col+dx[k]]==1){
                common_edge++;
            }
        }
    }
    return 4*points.size() - common_edge;
}

int main(int argc, char const *argv[])
{
    while(scanf("%d%d%d%d", &N, &M, &mouse_row, &mouse_col) != EOF) {
        if(!N && !M &&!mouse_row &&!mouse_col) break;
        for(int i = 0; i < N; i++){
            scanf("%s", buf);
            for(int j = 0; j < M; j++){
                if(buf[j] == 'X'){
                    maze[i][j] = 1;
                }
                else{
                    maze[i][j] = 0;
                }
                visit[i][j] = 0;
            }
        }
        mouse_row--;
        mouse_col--;
        printf("%d\n", calc_perimeter());
    }
    return 0;
}
