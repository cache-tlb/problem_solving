// 887. Super Egg Drop
// 思路：
// 状态递推关系：如果有 k 个鸡蛋，剩余m次move，则第一次仍可能碎或不碎，对应 f(k,m) = f(k-1,m-1) + f(k,m-1) + 1
// 边界关系：若 k > m，则多余的鸡蛋也没法在m步之内用完，相当于 k 个鸡蛋 m次move，f(k,m) = f(k-1,m)

class Solution {
public:
	std::vector<std::vector<int> > cache;
	int superEggDrop(int k, int n) {
		// cache[k][m], use k eggs, and m moves, how many floors can be handle
		if (k == 1) return n;
		const int MAXN = 10086;
		cache.resize(k+1);
		for (int i = 0; i < MAXN; i++) {
			cache[1].push_back(i);
		}

		for (int kk = 2; kk <= k; kk++) {
			for (int mm = 1; ; mm++) {
				if (cache[kk].size() < mm + 1) cache[kk].resize(mm + 1);
				if (kk > mm) cache[kk][mm] = cache[kk-1][mm];
				else {
					int s = cache[kk - 1][mm - 1] + cache[kk][mm - 1] + 1;
					cache[kk][mm] = s;
				}
				if (cache[kk][mm] >= MAXN) break;
			}
		}
		int m = 1;
		for (; ; m++) {
			if (cache[k][m] >= n) break;
		}
		return m;
	}
};
