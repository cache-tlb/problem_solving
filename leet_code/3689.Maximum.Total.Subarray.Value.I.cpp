// 3689. Maximum Total Subarray Value I
// notes: no tricks

class Solution {
public:
	long long maxTotalValue(vector<int>& nums, int k) {
		int h = nums[0], l = nums[0];
		for (const auto v : nums) {
			h = std::max(h, v);
			l = std::min(l, v);
		}
		return (long long)(h - l)*(long long)k;
	}
};