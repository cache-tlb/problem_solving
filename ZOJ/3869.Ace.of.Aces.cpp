#include <cstdio>
#include <map>


int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        std::map<int, int> m;
        for (int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
            m[x]++;
        }
        int max_vote = -1;
        int max_key = -1;
        for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            if (it->second > max_vote) {
                max_vote = it->second;
                max_key = it->first;
            }
        }
        int max_count = 0;
        for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            if (it->second == max_vote) {
                max_count++;
            }
        }
        if (max_count == 1) {
            printf("%d\n", max_key);
        } else {
            printf("Nobody\n");
        }
    }
    return 0;
}
