#include <cstdio>
#include <map>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        std::map<int,int> id_map;
        int id;
        for (int i = 0; i < n; i++) {
            scanf("%d", &id);
            id_map[id]++;
        }
        for (std::map<int,int>::iterator it = id_map.begin(); it != id_map.end(); it++) {
            if (it->second == 1) {
                printf("%d\n", it->first);
            }
        }
    }
    return 0;
}
