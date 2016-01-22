#include<string>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
struct state{
    int x,y,steps;
};
    
int flag = 0;
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int vis[8][8];
int MOVE(int sx, int sy, int tx, int ty){
    //cout<<sx<<' '<<sy<<' '<<tx<<' '<<ty<<endl;
    vector<state> vs;
    int cur = 0;
    state s = {sx, sy, 0};
    vs.push_back(s);
    while(cur < vs.size()){
        int x = vs[cur].x, y = vs[cur].y, step = vs[cur].steps;
        if(x==tx && y==ty){
            flag = 1;
            return step;
        }    
        vis[x][y] = 1;
        for(int i = 0; i < 8; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(vis[nx][ny]) continue;
            if(nx<0 || nx >7 || ny<0 || ny>7) continue;
            s.x = nx;
            s.y = ny;
            s.steps = step + 1;
            vs.push_back(s);
        }
        cur++;
    }
    return 0;    
}        
int main()
{
    string s1, s2;
    int sx, sy, tx, ty;
    while(cin >> s1 >> s2){
        flag = 0;
        memset(vis,0,sizeof(vis));
        sx = s1[0] - 'a';
        sy = s1[1] - '1';
        tx = s2[0] - 'a';
        ty = s2[1] - '1';
        //cout << sx << sy << tx << ty << endl;
        int ans = MOVE(sx, sy, tx, ty);
        cout << "To get from " << s1 << " to " << s2 << " takes " << ans << " knight moves." << endl;
    }    
    return 0;
}
