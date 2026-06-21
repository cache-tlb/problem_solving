// 3558. Number of Ways to Assign Edge Weights I
// note: find the max depth of the tree. then the num of methods is C_k^1 + C_k^3 + C_k^5 + ... = 2^(k-1)
class Solution {
public:
	int assignEdgeWeights(vector<vector<int>>& edges) {
		// construct the tree
		const long long mod = 1e9 + 7;
		int n = edges.size() + 1; // number of nodes of the tree
		std::vector<std::vector<int> > adj;
		adj.resize(n);
		for (const auto &edge : edges) {
			adj[edge[0] - 1].push_back(edge[1] - 1);
			adj[edge[1] - 1].push_back(edge[0] - 1);
		}
		std::vector<int> depth(n, -1);
		std::vector<int> parent(n, -1);
		std::queue<std::tuple<int, int, int> > q;	// depth, node_id
		q.push({ 0,0,-1 });
		while (!q.empty()) {
			const auto item = q.front();
			q.pop();
			auto d = std::get<0>(item), idx = std::get<1>(item), p = std::get<2>(item);
			if (depth[idx] >= 0) continue;
			depth[idx] = d;
			parent[idx] = p;
			for (const auto &v : adj[idx]) {
				q.push({d+1, v, idx});
			}
		}

		int path_len = 0;
		for (int i = 0; i < depth.size(); i++) {
			path_len = std::max(path_len, depth[i]);
		}
		int res = 1; // is 1/2 of 2^l
		for (int i = 0; i < path_len - 1; i++) {
			res = (res * 2);
			res = res % mod;
		}
		if (path_len == 0) return 0;
		return res;
	}
};
