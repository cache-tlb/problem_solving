#include <string>
#include <iostream>
#include <cstdio>
#include <map>

std::string str;

std::string clipboard = "";

bool equal(char *a, char *b, int len) {
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

struct Item {
    int dis;
    int start;
    int cfrom, cto;
    Item() {}
    Item(int d, int s, int cf, int ct): dis(d), start(s), cfrom(cf), cto(ct) {}
};

struct cmp {
    bool operator () (const Item &a, const Item &b) {
        return a.dis < b.dis || (a.dis == b.dis && a.start > b.start) 
        || (a.dis == b.dis && a.start == b.start && a.cfrom < b.cfrom)
        || (a.dis == b.dis && a.start == b.start && a.cfrom == b.cfrom && a.cto < b.cto);
    }
};

int solve() {
    int res = -1;
    std::map<Item,int,cmp> pq;
    Item item(1, 1, -1, -1);
    pq[item] = 1;
    while (!pq.empty()) {
        Item item = pq.begin()->first;
        pq.erase(item);
        // printf("%d %d %d %d\n", item.start, item.dis, item.cfrom, item.clen);
        if (item.start == str.length()) {
            res = item.dis;
            break;
        }
        bool match = true;
        int clen = item.cto - item.cfrom;
        if (item.cfrom < 0) match = false;
        for (int i = 0; i < clen; i++) {
            if (str[i+item.cfrom] != str[i+item.start]) {
                match = false;
                break;
            }
        }
        if (!match) {
        } else {
            Item new_item(item.dis+1, item.start+clen, item.cfrom, item.cto);
            pq[new_item] = 1;
        }
        for (int i = 0; i < item.start; i++) {
            if (str[i] != str[item.start]) continue;
            int clen = 1;
            while (i+clen-1 < item.start && item.start+clen-1 < str.length() && str[i+clen-1] == str[item.start+clen-1]) {
                Item new_item(item.dis+2, item.start+clen, i, i+clen);
                pq[new_item] = 1;
                clen++;
            }
        }
        Item new_item(item.dis+1, item.start+1, item.cfrom, item.cto);
        pq[new_item] = 1;
    }
    return res;
}
int main() {
    freopen ("A-large-practice.in","r",stdin);
    freopen ("A-large-practice.out","w",stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        std::cin >> str;
        int res = solve();
        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}