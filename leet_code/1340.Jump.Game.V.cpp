// 1340. Jump Game V
// notes: 简单 dp。从高度最低的出发，

class Solution {
public:
	int maxJumps(vector<int>& arr, int d) {
		int n = arr.size();
		std::vector<std::pair<int, int> > items;
		for (int i = 0; i < n; i++) {
			items.push_back({arr[i], i});
		}
		std::sort(items.begin(), items.end());
		std::vector<int> cache(n, 0);
		for (const auto item : items) {
			int h = item.first, pos = item.second;
			int c = 0;
			for (int k = 1; k <= d && pos + k < n; k++) {
				if (arr[pos + k] >= arr[pos]) break;
				c = std::max(c, cache[pos + k]);
			}
			for (int k = 1; k <= d && pos - k >= 0; k++) {
				if (arr[pos - k] >= arr[pos]) break;
				c = std::max(c, cache[pos - k]);
			}
			cache[pos] = c + 1;
		}
		int ret = 0;
		for (const auto v : cache) {
			ret = std::max(ret, v);
		}
		return ret;
	}
};
