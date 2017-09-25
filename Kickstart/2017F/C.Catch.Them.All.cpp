#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

std::vector<std::vector<int> > dist;

int main() {
    // freopen("input.txt", "r", stdin);
    freopen("C-large-practice.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int N, M, P;
        scanf("%d%d%d", &N, &M, &P);
        dist.resize(N);
        for (int i = 0; i < N; i++) {
            dist[i].clear();
            dist[i].resize(N, -1);
        }
        for (int i = 0; i < M; i++) {
            int u, v, d;
            scanf("%d%d%d", &u, &v, &d);
            u--;
            v--;
            dist[u][v] = d;
            dist[v][u] = d;
        }
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (dist[i][k] < 0 || dist[k][j] < 0) continue;
                    int x = dist[i][k] + dist[k][j];
                    if (dist[i][j] < 0 || dist[i][j] > x) {
                        dist[i][j] = x;
                    }
                }
            }
        }
        for (int i = 0; i < N; i++) dist[i][i] = 0;
        // std::vector<double> p(N);
        double p0 = 1, pnz = 0;
        int sumd0 = 0, sumd_nz = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == 0) sumd0 += dist[i][j];
                else sumd_nz += dist[i][j];
            }
        }
        
        double res = 0;
        // for (int k = 1; k <= P; k++) {
        //     double x = 0;
        //     x = (p0*sumd0)/double(N-1);
        //     x += (pnz*sumd_nz)/double(N-1);
        //     res += x;
        //     p0 = (1-p0)/double(N-1);
        //     pnz = (1-pnz)/double(N-1);
        // }
        double oneminusn = 1./double(1-N);
        double f = (pow(oneminusn, double(P)) - 1.0)/(oneminusn - 1);
        res += (p0*f - (f-P)/double(N))*sumd0/double(N-1);
        res += (pnz*f - (f-P)/double(N))*sumd_nz/double(N-1);
        printf("Case #%d: %llf\n", t, res);
    }
    return 0;
}