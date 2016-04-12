/*
分别把第二行加到第一行求最大子段和，再第三行加到第一行求最大子段和，....，第n行...；
再把第三行，第四行，....，n行 依次加到第二行，分别求最大子段和................。
记录过程中的最大值即可。
*/

/*
4
0 -2 -7 0 
9 2 -6 2
-4 1 -4  1 
-1 8  0 -2
ans is 15
*/

#include <cstdio>
#include <algorithm>
#include <cstring>

const int MAXN = 128;
int a[MAXN][MAXN] = {};

int max_segment(int *arr, int N) {
    int maxsum, maxhere;  
    // 记录以a[i]结尾的最大子序列和
    maxsum = maxhere = arr[0];   //初始化最大和为a【0】  
    for (int i = 1; i < N; i++) {  
        if (maxhere <= 0)  
            maxhere = arr[i];  //如果前面位置最大连续子序列和小于等于0，则以当前位置i结尾的最大连续子序列和为a[i]  
        else  
            maxhere += arr[i]; //如果前面位置最大连续子序列和大于0，则以当前位置i结尾的最大连续子序列和为它们两者之和  
        if (maxhere > maxsum) {  
            maxsum = maxhere;  //更新最大连续子序列和  
        }
    }  
    return maxsum;  
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int ans = -100000;
    for (int i1 = 0; i1 < N; i1++) {
        for (int i2 = i1 + 1; i2 < N; i2++) {
            // add the values of row i2 to row i1;
            for (int j = 0; j < N; j++) {
                a[i1][j] += a[i2][j];
            }
            ans = std::max(ans, max_segment(a[i1], N));
        }
    }
    printf("%d\n", ans);
    return 0;
}
