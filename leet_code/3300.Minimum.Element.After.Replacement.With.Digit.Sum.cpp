// 3300. Minimum Element After Replacement With Digit Sum
// easy
class Solution {
public:
	int minElement(vector<int>& nums) {
		int ret = nums[0];
		for (auto v : nums) {
			int s = 0;
			while (v) {
				s += v % 10;
				v /= 10;
			}
			ret = std::min(ret, s);
		}
		return ret;
	}
};