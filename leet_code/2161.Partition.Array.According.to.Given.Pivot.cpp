// 2161. Partition Array According to Given Pivot
// note: no trick

class Solution {
public:
	vector<int> pivotArray(vector<int>& nums, int pivot) {
		std::vector<int> ret;
		for (auto v : nums) {
			if (v < pivot) ret.push_back(v);
		}
		for (auto v : nums) {
			if (v == pivot) ret.push_back(v);
		}
		for (auto v : nums) {
			if (v > pivot) ret.push_back(v);
		}
        		return ret;

	}
};