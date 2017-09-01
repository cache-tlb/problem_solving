class Solution {
public:
    std::vector<long long> sum, aux, index;
    int lo, hi;
    int count;
    void mergesort(int start, int end) {
        if (start + 1 >= end) return;
        int mid = (start+end)/2;
        mergesort(start,mid);
        mergesort(mid, end);
        int q1 = mid, q2 = mid;
        for (int i = start; i < mid; i++) {
            while (q1 < end && sum[index[q1]] - sum[index[i]] < lo) q1++;
            while (q2 < end && sum[index[q2]] - sum[index[i]] <= hi) q2++;
            count += q2 - q1;
        }
        int p1 = start, p2 = mid, p = start;
        while (p1 < mid && p2 < end) {
            if (sum[index[p1]] < sum[index[p2]]) aux[p++] = index[p1++];
            else aux[p++] = index[p2++];
        }
        while (p1 < mid) aux[p++] = index[p1++];
        while (p2 < end) aux[p++] = index[p2++];
        for (int i = start; i < end; i++) index[i] = aux[i];
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        aux.resize(n);
        index.resize(n);
        sum.resize(n);
        count = 0;
        long long s = 0;
        for (int i = 0; i < n; i++) {
            s += nums[i];
            sum[i] = s;
            index[i] = i;
            if (lower <= sum[i] && sum[i] <= upper) count++;
        }
        lo = lower;
        hi = upper;
        mergesort(0, n);
        return count;
    }
};