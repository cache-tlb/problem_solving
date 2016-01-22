#include <cstdio>
#include <list>

using namespace std;

struct Window {
    int x1, y1, x2, y2, stamp, tx, ty, index;
    bool maximized;
    Window(int _x1, int _y1, int _x2, int _y2, int _i):x1(_x1),y1(_y1),x2(_x2),y2(_y2),index(_i),maximized(false),stamp(-100),tx(-1),ty(-1){}
};

int N, titleHeight, wMax, hMax, M;

int inWindow(Window &window, int x, int y) {
    int xmin = window.x1, xmax = window.x2, ymin = window.y2, ymax = window.y1;
    if (window.maximized) {
        xmin = 0, ymin = 0, xmax = wMax, ymax = hMax;
    }
    if (x < xmin || x > xmax || y < ymin || y > ymax) return 0; // out of window
    if (xmin <= x && x <= xmax && ymax - (titleHeight - 0) <= y && y <= ymax) return 2;   // title
    return 1;
}

void process(list<Window> &windowList, int x, int y, int t) {
    int index = -1;
    for (list<Window>::iterator it = windowList.begin(); it != windowList.end() && index < 0; it++) {
        int res = inWindow(*it, x, y);
        if (!res) continue;
        index = it->index;
        Window newWindow = *it;
        windowList.erase(it);
        if (res==1) {}
        else {
            if(newWindow.stamp == t - 1 && x == newWindow.tx && y == newWindow.ty) newWindow.maximized = !newWindow.maximized;
            newWindow.stamp = t, newWindow.tx = x, newWindow.ty = y;
        }
        windowList.push_front(newWindow);
        break;
    }
    printf("%d", index);
}

int main(int argc, char const *argv[])
{
    list<Window> windowList;
    while(scanf("%d%d%d%d", &N, &titleHeight, &wMax, &hMax) != EOF) {
        windowList.clear();
        int x1, y1, x2, y2;
        for (int i = 0; i < N; i++) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            windowList.push_front(Window(x1, y1, x2, y2, i));
        }
        scanf("%d", &M);
        for (int t = 0; t < M; t++) {
            int x, y;
            scanf("%d%d", &x, &y);
            process(windowList, x, y, t);
            if (t == M - 1) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
