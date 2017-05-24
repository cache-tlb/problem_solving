class Solution {
public:
    int findKth(int *a, int na, int *b, int nb, int k) {
        // printf("find kth: %d\n", k);
        // printf("a:");
        // for (int i = 0; i < na; i++) {
        //     printf("%d ", a[i]);
        // }
        // printf("\nb:");
        // for (int i = 0; i < nb; ++i) {
        //     printf("%d ", b[i]);
        // }
        // printf("\n");
        if (na < nb) {
            return findKth(b,nb,a,na,k);
        }
        // na >= nb
        if (nb == 0) return a[k];
        if (k == 0) return std::min(a[0], b[0]);
        int k2 = k/2;
        if (na > k2 && nb > k2) {
            // pass
        } else if (nb <= k2) {
            k2 = nb - 1;
        }
        if (k == 1 || k2 == 0) {
            if (a[0] > b[0]) return findKth(a, na, b+1, nb-1, k-1);
            else return findKth(a+1,na-1,b,nb, k-1);
        }
        if (a[k2] > b[k2]) {
            return findKth(a, na, b+k2, nb-k2, k-k2);
        } else {
            return findKth(a+k2, na-k2, b, nb, k-k2);
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int *a1 = NULL, *a2 = NULL;
        if (n1) a1 = &nums1[0];
        if (n2) a2 = &nums2[0];
        int n = n1 + n2;
        if (n % 2) {
            return findKth(a1, n1, a2, n2, n/2);
        }
        return (findKth(a1, n1, a2, n2, n/2-1) + findKth(a1, n1, a2, n2, n/2))/2.0;
    }
};
