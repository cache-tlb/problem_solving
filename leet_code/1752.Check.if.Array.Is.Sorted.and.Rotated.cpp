// 1752. Check if Array Is Sorted and Rotated
// easy
class Solution {
public:
	bool check(vector<int>& nums) {
		int n = nums.size();
		for (int d = 0; d < n; d++) {
			bool valid = true;
			for (int i = 1; i < n; i++) {
				if (nums[(i + d - 1) % n] > nums[(i+d)%n]) {
					valid = false;
					break;
				}
			}
			if (valid) return true;
		}
		return false;
	}
};