#include <cstdio>
#include <cstring>

using namespace std;

const int MAXM = 128;
const int MAXSCORE = 100;
const int MAXN = 1000000001;
const int INF = 0x3f3f3f3f;

int M, N;
int cache[MAXM*MAXM];
int score[MAXM];

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &M, &N);
        int max_score = 0;
        for(int i = 0; i < M; i++) {
            scanf("%d", &score[i]);
            max_score = max(max_score, score[i]);
        }
        int ub = max_score * max_score;
        for(int i = 1; i < ub; i++) {
            cache[i] = INF;
        }
        for(int i = 0; i < M; i++) {
            for(int j = score[i]; j < ub; j++) {
                cache[j] = min(cache[j], cache[j - score[i]] + 1);
            }
        }
        if(N < ub) {
            if(cache[N] == INF) printf("-1\n");
            else printf("%d\n", cache[N]);
        }
        else {
            int c = N / max_score, ans = INF, rem = N % max_score;
            for(int i = rem; i < ub; i+= max_score, c--) {
                ans = min(ans, c + cache[i]);
            }
            if(ans == INF) printf("-1\n");
            else printf("%d\n", ans);
        }
    }
    return 0;
}
