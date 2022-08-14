class Solution {
public:
	int maxSatisfaction(vector<int>& satisfaction) {
		int ret = 0;
		std::sort(satisfaction.begin(), satisfaction.end());
		int n = satisfaction.size() - 1;
		int sum = 0;
		int total = 0;
		for (int i = n; i >= 0; i--) {
			sum += satisfaction[i];
			total += sum;
			ret = max(ret, total);
		}
		return ret;
	}
};
