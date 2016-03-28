#include <cstdio>
#include <string>
#include <queue>
#include <cstdlib>
#include <algorithm>

const int DIM = 5;
int maze[DIM][DIM] = {};
struct Pos {
    int x, y;
    Pos(int xx = 0, int yy = 0):x(xx), y(yy) {}
};

typedef std::pair<Pos, std::string> QueueEle;

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};
char buf[128] = {};
int main () {
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    std::queue<QueueEle> q;
    q.push(std::make_pair<>(Pos(0,0), "(0, 0)\n"));
    maze[0][0] = 2;
    while (!q.empty()) {
        QueueEle ele = q.front();
        q.pop();
        int cx = ele.first.x, cy = ele.first.y;
        if (cx == 4 && cy == 4) {
            printf("%s", ele.second.c_str());
            break;
        }
        for (int k = 0; k < 4; k++) {
            int x = cx + dx[k], y = cy + dy[k];
            if (x >= 0 && x < DIM && y >= 0 && y < DIM && maze[y][x] == 0) {
                sprintf(buf, "(%d, %d)\n", y, x);
                q.push(std::make_pair<>(Pos(x, y), ele.second + std::string(buf)));
                maze[y][x] = 2;
            }
        }
    }
    return 0;
}
