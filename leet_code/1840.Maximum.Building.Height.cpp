// tips:
// adjust the restriction array to match the constrains from neighboors, foward and backward.
// do not allocate an array for each point. or you will get a memory limit exceeded.

class Solution {
public:
	int maxBuilding(int n, vector<vector<int>>& restrictions) {
		restrictions.push_back({ 1,0 });
		std::sort(restrictions.begin(), restrictions.end(), [](const vector<int>& a, const vector<int> &b) {
			return a[0] < b[0]; // Sort by x-coordinate
		});
		if (restrictions.back()[0] != n) {
			restrictions.push_back({n,n-1});
		}
		
		bool changed = false;
		do {
			changed = false;
			for (int i = 1; i < restrictions.size(); i++) {
				int cur_p = restrictions[i - 1][0] - 1;
				int cur_h = restrictions[i - 1][1];
				int next_p = restrictions[i][0] - 1;
				int next_h = restrictions[i][1];
				cur_h += (next_p - cur_p);
				if (restrictions[i][1] > cur_h) {
					restrictions[i][1] = cur_h;
					changed = true;
				}
			}
			for (int i = restrictions.size() - 1; i >= 1; i--) {
				int cur_p = restrictions[i][0] - 1;
				int cur_h = restrictions[i][1];
				int next_p = restrictions[i - 1][0] - 1;
				int next_h = restrictions[i - 1][1];
				cur_h += -(next_p - cur_p);
				if (restrictions[i - 1][1] > cur_h) {
					restrictions[i - 1][1] = cur_h;
					changed = true;
				}
			}
		} while (changed);

		int ret = 0;
		for (int i = 1; i < restrictions.size(); i++) {
			int h0 = restrictions[i - 1][1];
			int x0 = restrictions[i - 1][0] - 1;
			int h1 = restrictions[i][1];
			int x1 = restrictions[i][0] - 1;
			int y = (h0 + h1 + x1 - x0) / 2;
			ret = std::max(ret, y);
		}

		return ret;
	}
};

//class Solution {
//public:
//	struct QueueData {
//		int height;
//		int idx;
//	};
//	struct CmpData {
//		bool operator () (const QueueData &a, const QueueData &b) {
//			return a.height < b.height || (a.height == b.height && a.idx < b.idx);
//		}
//	};
//	int maxBuilding(int n, vector<vector<int>>& restrictions) {
//		std::vector<int> lim(n);
//		for (int i = 0; i < n; i++) {
//			lim[i] = i;
//		}
//		for (int i = 0; i < restrictions.size(); i++) {
//			int id = restrictions[i][0] - 1;
//			int h = restrictions[i][1];
//			lim[id] = std::min(lim[id], h);
//		}
//		std::priority_queue<QueueData, std::vector<QueueData>, CmpData> pq;
//		for (int i = 0; i < lim.size(); i++) {
//			QueueData data;
//			data.height = lim[i];
//			data.idx = i;
//			pq.push(data);
//		}
//		while (!pq.empty()) {
//			QueueData data = pq.top();
//			pq.pop();
//			int idx = data.idx;
//			int height = data.height;
//			if (lim[idx] < height) continue;
//			lim[idx] = height;
//			if (idx > 0 && height + 1 < lim[idx - 1]) {
//				data.idx = idx - 1;
//				data.height = height + 1;
//				pq.push(data);
//				lim[idx - 1] = height + 1;
//			}
//			if (idx < n - 1 && height + 1 < lim[idx + 1]) {
//				data.idx = idx + 1;
//				data.height = height + 1;
//				pq.push(data);
//				lim[idx + 1] = height + 1;
//			}
//		}
//		int maxH = 0;
//		for (const auto &item : lim) {
//			maxH = std::max(maxH, item);
//		}
//		return maxH;
//	}
//};
