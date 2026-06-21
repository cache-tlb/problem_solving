// 2574. Left and Right Sum Differences
// no trick


class Solution {
public:
	vector<int> leftRightDifference(vector<int>& nums) {
		int sum = 0;
		for (auto v : nums) {
			sum += v;
		}
		std::vector<int> ret;
		int acc = 0;
		for (auto v : nums) {
			acc += v;
			int ls = acc - v;
			int rs = sum - acc;
			ret.push_back(abs(ls - rs));
		}
		return ret;
	}
};

