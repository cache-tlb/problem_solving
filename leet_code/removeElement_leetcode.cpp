class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (elem == A[i]) cnt++;
        }
        int p1 = 0, p2 = n - 1;
        while (p1 < n - cnt) {
            while (p1 < n - cnt && A[p1] != elem) p1++;
            while (A[p2] == elem) p2--;
            if(p1 < n - cnt) A[p1++] = A[p2--];
        }
        return n - cnt;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
