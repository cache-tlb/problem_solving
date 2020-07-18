class Solution {
public:
	struct Item {
		Item(int value, int row, int col) : value(value), row(row), col(col) {}
		int value, row, col;
		bool operator < (const Item &that) const {
			return value > that.value;
		}
	};
	int swimInWater(vector<vector<int>>& grid) {
		int dx[] = {-1, 1, 0, 0};
		int dy[] = { 0,0,-1,1 };
		int N = grid.size();
		std::vector<int> status(N*N, 0);		// 0: never visit; 1: in queue; 2. removed
		std::priority_queue<Item> queue;
		int current_value = grid[0][0];
		queue.push(Item(current_value, 0, 0));
		status[0] = 1;
		int max_value = 0;
		while (!queue.empty()) {
			Item top = queue.top();
			queue.pop();
			max_value = std::max(max_value, top.value);
			if (top.row == N - 1 && top.col == N - 1) break;
			for (int k = 0; k < 4; k++) {
				int row = dx[k] + top.row, col = dy[k] + top.col;
				int idx = row * N + col;
				if (row >= 0 && row < N && col >= 0 && col < N && status[idx] == 0) {
					queue.push(Item(grid[row][col], row, col));
					status[idx] = 1;
				}
			}
			status[top.row*N + top.col] = 2;
		}
		return max_value;
	}
};
