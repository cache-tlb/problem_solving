#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct Mouse {
    int weight, speed, index, parent;
    Mouse():parent(-1){}
};

const int MAXN = 1024;

bool cmp (const Mouse &a, const Mouse &b) {
    return (a.weight < b.weight) || (a.weight == b.weight && a.speed > b.speed) ||
           (a.weight == b.weight && a.speed == b.speed && a.index < b.index);
}

int N;
Mouse mice[MAXN];
int cache[MAXN];

void process() {
    sort(mice, mice+N, cmp);
    /*printf("---------------------\n");
    for(int i = 0; i < N; i++){
        printf("%d %d %d\n", mice[i].weight, mice[i].speed, mice[i].index);
    }*/
    memset(cache, 0, sizeof(cache));
    cache[0] = 1;
    for(int i = 1; i < N; i++){
        int tmp = 0;
        int pos = -1;
        for(int j = i - 1; j >= 0; j--){
            if(mice[j].weight < mice[i].weight && mice[j].speed > mice[i].speed && cache[j] > tmp){
                tmp = cache[j];
                pos = j;
            }
        }
        cache[i] = tmp + 1;
        mice[i].parent = pos;
        //printf("%d %d %d\n", i, cache[i], pos);
    }
    int pos = -1;
    int max_n = 0;
    for(int i = 0; i < N; i++){
        if(cache[i] > max_n){
            max_n = cache[i];
            pos = i;
        }
    }
    vector<int> vi;
    while(pos >= 0){
        vi.push_back(pos);
        pos = mice[pos].parent;
    }
    printf("%d\n", vi.size());
    for(int i = vi.size() - 1; i >= 0; i--){
        printf("%d\n", mice[vi[i]].index + 1);
    }
}

int main(int argc, char const *argv[])
{
    N = 0;
    while(scanf("%d%d", &mice[N].weight, &mice[N].speed) != EOF){
        mice[N].index = N;
        mice[N].parent = -1;
        N++;
    }
    process();
    return 0;
}
