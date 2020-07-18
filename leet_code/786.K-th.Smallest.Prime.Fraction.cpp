class Solution {
public:
	
	std::vector<int> nums;

	int CountLessThan(double val, int &p, int &q) {
		int count = 0;
		int i = 0;
		double min_dist = 1;
		for (int j = 1; j < nums.size(); j++) {
			double c = nums[j] * val;
			int k = i;
			for (; k+1 < nums.size(); k++) {
				if (nums[k] > c) break;
				if (nums[k] <= c && nums[k + 1] > c) {
					double d = val - double(nums[k]) / double(nums[j]);
					if (d < min_dist) {
						p = nums[k];
						q = nums[j];
						min_dist = d;
					}
					break;
				}
			}
			if (nums[k] <= c && nums[k + 1] > c) {
				i = k;
				count += (i + 1);
			}
		}
		return count;
	}

	vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
		nums = A;
		int ret_p, ret_q;
		double low = 0, high = 1;
		int low_count = 0, high_count = A.size() * (A.size() - 1) / 2;
		while (low < high) {
			double mid = (low + high) / 2.;
			int mid_count = CountLessThan(mid, ret_p, ret_q);
			if (mid_count < K) {
				low = mid;
			}
			else if (mid_count > K) {
				high = mid;
			}
			else {
				low = high = mid;
				break;
			}
		}
		
		std::vector<int> ret;
		ret.push_back(ret_p);
		ret.push_back(ret_q);
		return ret;
	}
};
