class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int p1 = 0, p2 = 0, val = A[0];
        while (p2 < n) {
            val = A[p2];
            while (p2 < n && A[p2] == val) p2++;
            A[p1++] = val;
        }
        return p1;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
