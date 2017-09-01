class Solution {
public:
    std::vector<int> value, count, index, aux;
    void mergesort(int start, int end) {
        if (start + 1 >= end) return;
        int mid = (start + end)/2;
        mergesort(start, mid);
        mergesort(mid, end);
        int p1 = start, p2 = mid, p = start;
        while (p1 < mid && p2 < end) {
            if (value[index[p2]] < value[index[p1]]) {
                aux[p++] = index[p2++];
            } else {
                count[index[p1]] += p2 - mid;
                aux[p++] = index[p1++];
            }
        }
        while (p1 < mid) {
            count[index[p1]] += p2 - mid;
            aux[p++] = index[p1++];
        }
        while (p2 < end) {
            aux[p++] = index[p2++];
        }
        for (int i = start; i < end; i++) {
            index[i] = aux[i];
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        value = nums;
        count.resize(n, 0);
        index.resize(n);
        aux.resize(n);
        for (int i = 0; i < index.size(); i++) {
            index[i] = i;
        }
        mergesort(0, n);
        return count;
    }
};