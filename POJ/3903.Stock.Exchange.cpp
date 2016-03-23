#include <cstdio>

const int MAXN = 100010;
int a[MAXN], b[MAXN];

int BinarySearch(int array[], int value, int nLength) {
    int begin = 0;
    int end = nLength - 1;
    while(begin <= end) {
        int mid = begin + (end - begin) / 2;
        if(array[mid] == value)
            return mid;
        else if(array[mid] > value)
            end = mid - 1;
        else
            begin = mid + 1;
    }
    return begin;
}

int LIS_DP_NlogN(int array[], int B[], int nLength) {
    int nLISLen = 1;
    B[0] = array[0];
    for(int i = 1; i < nLength; i++) {
        if(array[i] > B[nLISLen - 1]) {
            B[nLISLen] = array[i];
            nLISLen++;
        }
        else {
            int pos = BinarySearch(B, array[i], nLISLen);
            B[pos] = array[i];
        }
    }
    return nLISLen;
}


int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        printf("%d\n", LIS_DP_NlogN(a, b, n));
    }
    return 0;
}
