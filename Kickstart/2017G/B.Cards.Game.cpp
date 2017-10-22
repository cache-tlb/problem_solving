#include <iostream>
#include <cstdio>

using namespace std;

int f[45][45][45][45], s[45][45][45][45];
int p[45][45];

int main()
{
    // freopen ("C-small-attempt0.in", "r", stdin);
    // freopen ("C-small-attempt0.out", "w", stdout);
    freopen ("C-large.in", "r", stdin);
    freopen ("C-large.out", "w", stdout);
    int n, m;
    int times;
    scanf("%d", &times);
    for(int iter = 1; iter <= times; ++iter)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
            {
                scanf("%d", &p[i][j]);
            }
        for(int x1 = 1; x1 <= n; ++x1)
            for(int y1 = 1; y1 <= m; ++y1)
                for(int x2 = x1; x2 <= n; ++x2)
                    for(int y2 = y1; y2 <= m; ++y2)
                        f[x1][y1][x2][y2] = 0;
        for(int dx = 0; dx < n; ++dx)
            for(int dy = 0; dy < m; ++dy)
            {
                for(int x = 1; x + dx <= n; ++x)
                    for(int y = 1; y + dy <= m; ++y)
                    {
                        f[x][y][x][y] = 0;
                        if (dx == 0 && dy == 0)
                        {
                            s[x][y][x][y] = p[x][y];
                            continue;
                        }
                        if (dx > 0)
                        {
                            int s1 = s[x][y][x][y+dy];
                            int s2 = s[x+1][y][x+dx][y+dy];
                            if (s1 < s2)
                                s[x][y][x+dx][y+dy] = s1;
                            else
                                s[x][y][x+dx][y+dy] = s2;
                            for(int i = 0; i < dx; ++i)
                            {
                                int tmp = f[x][y][x+i][y+dy] + f[x+i+1][y][x+dx][y+dy] + s[x][y][x+dx][y+dy];
                                if (tmp > f[x][y][x+dx][y+dy])
                                    f[x][y][x+dx][y+dy] = tmp;
                            }
                        }
                        if (dy > 0)
                        {
                            int s1 = s[x][y][x+dx][y];
                            int s2 = s[x][y+1][x+dx][y+dy];
                            if (s1 < s2)
                                s[x][y][x+dx][y+dy] = s1;
                            else
                                s[x][y][x+dx][y+dy] = s2;
                            for(int i = 0; i < dy; ++i)
                            {
                                int tmp = f[x][y][x+dx][y+i] + f[x][y+i+1][x+dx][y+dy] + s[x][y][x+dx][y+dy];
                                if (tmp > f[x][y][x+dx][y+dy])
                                    f[x][y][x+dx][y+dy] = tmp;
                            }
                        }
                    }
            }
        printf("Case #%d: %d\n", iter, f[1][1][n][m]);
    }
    return 0;
}
