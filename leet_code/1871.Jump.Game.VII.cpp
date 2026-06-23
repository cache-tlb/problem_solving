// 1871. Jump Game VII
// note: 每个点往后试探的范围可能很大，相邻的点的试探范围会有大部分重叠，故不要让 for 循环遍历到同样的位置。
// 确定之前已经试探过的区间，然后将新的点试探的起点挪到已经试探过的区间右侧
class Solution {
public:
	bool canReach(string s, int minJump, int maxJump) {
		// BFS
		int n = s.length();
		std::vector<bool> visited(n, 0);
		std::queue<int> q;
		q.push(0);
		visited[0] = 1;
		int cur_l = 0, cur_r = 1;	// window
		while (!q.empty()) {
			int p = q.front();
			q.pop();
			
			int next_l = cur_r, next_r = cur_r;
			
			auto v = p;
			int mj = std::max(minJump, next_r - v);
			for (int i = mj; i <= maxJump && v + i < n; i++) {
				int next = v + i;
				next_r = std::max(next_r, next + 1);
				if (s[next] == '1') continue;
				q.push(next);
				visited[next] = 1;
			}
			cur_l = next_l;
			cur_r = next_r;
		}
		return visited.back();
	}
};