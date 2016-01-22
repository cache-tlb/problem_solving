#include <cstdio>
#include <set>

using namespace std;

const int MAXN = 10002;

int main(int argc, char const *argv[])
{
    int N, M;
    while(scanf("%d%d", &N, &M) != EOF) {
        if(!N && !M) break;
        set<int> ids;
        int count[MAXN] = {};
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                int index;
                scanf("%d", &index);
                count[index] ++;
                ids.insert(index);
            }
        }
        int first = 0, second = 0;
        for(set<int>::iterator it = ids.begin(); it != ids.end(); it++) {
            if (count[*it] > first) {
                second = first;
                first = count[*it];
            }
            else if (count[*it] > second) {
                second = count[*it];
            }
        }
        for(set<int>::iterator it = ids.begin(); it != ids.end(); it++) {
            if (count[*it] == second) printf("%d ", *it);
        }
        printf("\n");
    }
    return 0;
}
