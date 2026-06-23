// 2144. Minimum Cost of Buying Candies With Discount
// easy

class Solution {
public:
	int minimumCost(vector<int>& cost) {
		std::sort(cost.begin(), cost.end(), [](int a, int b) {return a > b; });
		int s = 0;
		for (int i = 0; i < cost.size(); i++) {
			if (i % 3 != 2) s += cost[i];
		}
		return s;
	}
};