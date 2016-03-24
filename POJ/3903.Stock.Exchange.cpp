// the Longest Increasing Subsequence problem
// A = {5， 6， 7， 1， 2， 8}
// B数组内任意元素B[i]，记录的是最长递增子序列长度为i的序列的末尾元素的值，也就是这个最长递增子序列的最大元素的大小值。
// 首先，把d[1]有序地放到B里，令B[1] = 2，就是说当只有1一个数字2的时候，长度为1的LIS的最小末尾是2。这时Len=1
// 然后，把d[2]有序地放到B里，令B[1] = 1，就是说长度为1的LIS的最小末尾是1，d[1]=2已经没用了，很容易理解吧。这时Len=1
// 接着，d[3] = 5，d[3]>B[1]，所以令B[1+1]=B[2]=d[3]=5，就是说长度为2的LIS的最小末尾是5，很容易理解吧。这时候B[1..2] = 1, 5，Len＝2
// 再来，d[4] = 3，它正好加在1,5之间，放在1的位置显然不合适，因为1小于3，长度为1的LIS最小末尾应该是1，这样很容易推知，长度为2的LIS最小末尾是3，于是可以把5淘汰掉，这时候B[1..2] = 1, 3，Len = 2
// 继续，d[5] = 6，它在3后面，因为B[2] = 3, 而6在3后面，于是很容易可以推知B[3] = 6, 这时B[1..3] = 1, 3, 6，还是很容易理解吧？ Len = 3 了噢。
// 第6个, d[6] = 4，你看它在3和6之间，于是我们就可以把6替换掉，得到B[3] = 4。B[1..3] = 1, 3, 4， Len继续等于3
// 第7个, d[7] = 8，它很大，比4大，嗯。于是B[4] = 8。Len变成4了
// 第8个, d[8] = 9，得到B[5] = 9，嗯。Len继续增大，到5了。
// 最后一个, d[9] = 7，它在B[3] = 4和B[4] = 8之间，所以我们知道，最新的B[4] =7，B[1..5] = 1, 3, 4, 7, 9，Len = 5。
// 于是我们知道了LIS的长度为5。

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
