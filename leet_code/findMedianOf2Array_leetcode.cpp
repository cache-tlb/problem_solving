#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    double kthEle(int *A, int m, int *B, int n, int k) {
        if (m > n) return kthEle(B,n,A,m,k);
        if (m==0) return B[k-1];
        if (k==1) return min(A[0],B[0]);
        int pa = min(k/2,m), pb = k - pa;
        if (A[pa - 1] < B[pb - 1]) return kthEle(A + pa, m - pa, B, n, k - pa);
        if (B[pb - 1] < A[pa - 1]) return kthEle(A, m, B + pb, n - pb, k - pb);
        else return A[pa - 1];
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int k = m + n;
        if(k%2) return kthEle(A, m, B, n, k/2 + 1);
        else return (kthEle(A,m,B,n,(k-1)/2 + 1) + kthEle(A,m,B,n,(k+1)/2 + 1))/2.0;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int *p1 = a + 4;
    cout << *p1 << endl;
    cout << (a + 10 - p1) << endl;
    return 0;
}
