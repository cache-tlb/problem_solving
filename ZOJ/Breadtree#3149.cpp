#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

// keep unchange when weight is more than this limit
const int weight_limit = 1234567890;

int calc(int N, int K){
    if(K==0) return (N-1 < weight_limit+1 ? N-1 : weight_limit+1);
    int total_weight = 0;
    int total_nodes = 1;
    int t = 1;
    queue<int> q;
    q.push(1);
    int sum_q = 1;
    while(t < N && t <= K && total_weight <= weight_limit){
        t++;
        int val = 1<<(t-2);
        q.push(val);
        sum_q += val;
        total_weight += total_nodes;
        total_nodes += val;
    }
    if(t==N || total_weight > weight_limit) return total_weight;
    while(t < N && total_weight <= weight_limit){
        sum_q -= q.front();
        q.pop();
        q.push(sum_q);
        sum_q += q.back();
        total_weight += total_nodes;
        total_nodes += q.back();
        t++;
    }
    return total_weight;
}

int main(int argc, char const *argv[])
{
    int N, K;
    while(scanf("%d%d", &N, &K)!=EOF){
        if(!N) break;
        printf("%d\n", calc(N,K));
    }
    return 0;
}
