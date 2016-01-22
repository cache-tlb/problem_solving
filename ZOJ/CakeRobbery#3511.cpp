#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

// brute force, use map to record which piece contains which vertex

const int MAXN = 16384;

struct node {
    int start, end;
};

typedef std::map<int, int> mii;

bool cmp(const node &a, const node &b){
    return (a.start > b.start) || (a.start == b.start && a.end < b.end);
}

node v[MAXN];

int main(int argc, char const *argv[])
{
    int N, M;
    int start, end;
    while(scanf("%d%d", &N, &M) != EOF){
        vector<mii> vmap;
        for(int i = 0; i < M; i++){
            scanf("%d%d", &start, &end);
            if(start > end) std::swap(start, end);
            v[i].start = start;
            v[i].end = end;
        }
        sort(v, v + M, cmp);
        mii mp;
        for(int i = 1; i <= N; i++){
            mp[i] = 1;
        }
        vmap.push_back(mp);
        for(int i = 0; i < M; i++){
            int index = 0;
            for(; index < vmap.size(); index++){
                if(vmap[index].count(v[i].start) > 0 && vmap[index].count(v[i].end) > 0){
                    break;
                }
            }
            mii &rmp = vmap[index];
            mii newmap;
            mii::iterator it1 = rmp.find(v[i].start);
            mii::iterator it2 = rmp.find(v[i].end);
            it1++;
            newmap[v[i].start] = 1;
            newmap.insert(it1, it2);
            newmap[v[i].end] = 1;
            rmp.erase(it1, it2);
            vmap.push_back(newmap);
        }
        int max_edge = 0;
        for(int i = 0; i < vmap.size(); i++){
            if(vmap[i].size() > max_edge) max_edge = vmap[i].size();
        }
        printf("%d\n", max_edge);
    }
    return 0;
}
