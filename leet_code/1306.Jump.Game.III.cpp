// 1306. Jump Game III
// note: simple BFS

class Solution {
public:
	bool canReach(vector<int>& arr, int start) {
		std::queue<int> q;
		std::vector<int> v(arr.size(), 0);
		if (arr[start] == 0) return true;
		v[start] = 1;
		q.push(start);
		while (!q.empty()) {
			int p = q.front();
			q.pop();
			int p1 = p - arr[p], p2 = p + arr[p];
			if (p1 >= 0 && !v[p1]) {
				if (arr[p1] == 0) return true;
				v[p1] = 1;
				q.push(p1);
			}
			if (p2 < arr.size() && !v[p2]) {
				if (arr[p2] == 0) return true;
				v[p2] = 1;
				q.push(p2);
			}
		}
		return false;
	}
};