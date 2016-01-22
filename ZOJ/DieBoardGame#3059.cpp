#include <iostream>
#include <cstdio>
#include <list>
#include <cstring>
#include <string>
#include <set>
using namespace std;

/*struct point {
	int x, y;
	point(){}
	point(int _x, int _y){x=_x;y=_y;}
};*/

struct state {
	int x, y;
	int top, front, right;
    state(){}
    state(int _x, int _y, int t, int f, int r){x=_x;y=_y;top=t;front=f;right=r;}
};

state move_up(state &s){
    // dx = 0, dy = -1
    return state(s.x, s.y-1, s.front, 7-s.top, s.right);
}

state move_down(state &s){
    // dx = 0, dy = 1
    return state(s.x, s.y+1, 7-s.front, s.top, s.right);
}

state move_left(state &s){
    // dx = -1, dy = 0
    return state(s.x-1, s.y, s.right, s.front, 7-s.top);
}

state move_right(state &s){
    // dx = 1, dy = 0
    return state(s.x+1, s.y, 7-s.right, s.front, s.top);
}

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

state (*move_func[])(state&) = {move_left, move_right, move_up, move_down};

bool operator < (const state &a, const state &b){
	return (a.x<b.x) || (a.x==b.x&&a.y<b.y) || (a.x==b.x&&a.y==b.y&&a.top<b.top) || 
           (a.x==b.x&&a.y==b.y&&a.top==b.top&&a.front<b.front) || 
           (a.x==b.x&&a.y==b.y&&a.top==b.top&&a.front==b.front&&a.right<b.right);
}

bool operator == (const state &a, const state &b){
    return (a.x==b.x&&a.y==b.y&&a.top==b.top&&a.front==b.front&&a.right==b.right);
}

const int MAXN = 128;
int N,M;
int maze[MAXN][MAXN]={};
int ans;
state src, dst;

inline bool in_board(int x, int y){
	return (x>=0 && x<M && y>=0 && y<N);
}

void bfs() {
    ans = -1;
    set<state> vis;
    list<state> q_state;
    list<int> q_moves;
    q_state.push_back(src);
    vis.insert(src);
    q_moves.push_back(0);
    while(!q_state.empty()){
        int moves = q_moves.front();
        state s = q_state.front();
        if(s==dst) {
            ans = moves;
            return;
        }
        q_moves.pop_front();
        q_state.pop_front();
        for(int k = 0; k < 4; k++){
            if(in_board(s.x+dx[k], s.y+dy[k]) && maze[s.y+dy[k]][s.x+dx[k]] != -1){
                state new_state = move_func[k](s);
                if(vis.count(new_state) > 0) continue;
                q_state.push_back(new_state);
                vis.insert(new_state);
                q_moves.push_back(moves + 1);
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    string line;
    while(cin >> N >> M) {
        for(int i = 0; i < N; i++){
            cin >> line;
            for(int j = 0; j < M; j++){
                if(line[j] == '.'){
                    maze[i][j] = 0;
                }
                else if(line[j] == '#'){
                    maze[i][j] = -1;
                }
            }
        }
        int top, bottom, front, back, left, right;
        cin >> src.y >> src.x >> dst.y >> dst.x;
        cin >> top >> bottom >> back >> front >> left >> right;
        src.top = top; src.front = front; src.right = right;
        cin >> top >> bottom >> back >> front >> left >> right;
        dst.top = top; dst.front = front; dst.right = right;
        bfs();
        cout << ans << endl;
    }
	return 0;
}
