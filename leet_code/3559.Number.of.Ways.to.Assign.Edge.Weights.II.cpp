// 3559. Number of Ways to Assign Edge Weights II
// note: 
// a fast method to find the LCA of two tree nodes
// 思路：通过预处理 fa_x,i 数组，游标可以快速移动，大幅减少了游标跳转次数．  fa_x,i 表示点 x 的第 2^i 个祖先．fa_x,i 数组可以通过 dfs 预处理出来．
// 在调整游标的第一阶段中，我们要将 u,v 两点跳转到同一深度．
// 设 uv 深度之差 为 y，因为有了fa_x,i 数组，所以可以跳转 k 次（k=y的二进制表示中含1的个数）到达同一高度。
// 第二阶段是同时往上挪动 uv，先尝试最大的 gap，可能直接就到了根节点，再减半 gap，直到u和v不一样，此时挪动 uv 到 u1,v1.然后再减小gap继续往上挪，直到gap为1
// 

class Solution {
public:
	std::vector<std::vector<int> > v;	// adj node list
	std::vector<int> dep;		// depth
	std::vector<std::vector<int> > fa;	// aux array
	std::vector<std::vector<int> > cost;
	std::map<int, int> cache;

	// dfs，用来为 lca 算法做准备。接受两个参数：dfs 起始节点和它的父亲节点。
	void dfs(int root, int fno) {
		// 初始化：第 2^0 = 1 个祖先就是它的父亲节点，dep 也比父亲节点多 1。
		fa[root][0] = fno;
		dep[root] = dep[fa[root][0]] + 1;
		// 初始化：其他的祖先节点：第 2^i 的祖先节点是第 2^(i-1) 的祖先节点的第
		// 2^(i-1) 的祖先节点。
		for (int i = 1; i < 31; ++i) {
			fa[root][i] = fa[fa[root][i - 1]][i - 1];
			cost[root][i] = cost[fa[root][i - 1]][i - 1] + cost[root][i - 1];
		}
		// 遍历子节点来进行 dfs。
		int sz = v[root].size();
		for (int i = 0; i < sz; ++i) {
			if (v[root][i] == fno) continue;
			cost[v[root][i]][0] = 1;
			dfs(v[root][i], root);
		}
	}

	// lca。用倍增算法算取 x 和 y 的 lca 节点。
	int lca(int x, int y) {
		// 令 y 比 x 深。
		if (dep[x] > dep[y]) swap(x, y);
		// 令 y 和 x 在一个深度。
		int tmp = dep[y] - dep[x], ans = 0;
		for (int j = 0; tmp; ++j, tmp >>= 1)
			if (tmp & 1) ans += cost[y][j], y = fa[y][j];
		// 如果这个时候 y = x，那么 x，y 就都是它们自己的祖先。
		if (y == x) return ans;
		// 不然的话，找到第一个不是它们祖先的两个点。
		for (int j = 30; j >= 0 && y != x; --j) {
			if (fa[x][j] != fa[y][j]) {
				ans += cost[x][j] + cost[y][j];
				x = fa[x][j];
				y = fa[y][j];
			}
		}
		// 返回结果。
		ans += cost[x][0] + cost[y][0];
		return ans;
	}

	vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
		// construct the tree
		const long long mod = 1e9 + 7;
		int n = edges.size() + 1; // number of nodes of the tree
		v.clear();
		v.resize(n+1);
		for (const auto &edge : edges) {
			v[edge[0] ].push_back(edge[1] );
			v[edge[1] ].push_back(edge[0] );
		}
		dep.resize(n+1, -1);
		fa.resize(n+1);
		cost.resize(n+1);
		for (int i = 0; i <= n; i++) {
			fa[i].resize(32);
			cost[i].resize(32);
		}

		// 为了计算 lca 而使用 dfs。
		dfs(1, 0);
		
		// process the queries
		std::vector<int> ret;
		for (const auto &query : queries) {
			int a = query[0] , b = query[1] ;
			int path_len = lca(a, b);
			if (cache.count(path_len) != 0) {
				ret.push_back(cache[path_len]);
				continue;
			}
			// l choose k, for k = 1, 3, ...,
			long long res = 1; // is 1/2 of 2^l
			for (int i = 0; i < path_len -1; i++) {
				res = (res * 2) % mod;
			}
			if (path_len <= 0) cache[path_len] = 0;
			else cache[path_len] = res;
			ret.push_back(cache[path_len]);
		}

		return ret;
	}
};