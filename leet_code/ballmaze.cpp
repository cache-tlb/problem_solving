#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Matrix {
public:
	Matrix(int height, int width) :rows(height), cols(width) {
		data = new int *[rows];
		for (int i = 0; i < rows; i++) {
			data[i] = new int[cols];
			memset(data[i], 0, cols * sizeof(int));
		}
	}
	~Matrix() {
		for (int i = 0; i < rows; i++) {
			delete[] data[i];
		}
		delete[] data;
	}

	/* data */
	int rows, cols;
	int **data;
	int get(int i, int j) {
		return data[i][j];
	}
	void set(int i, int j, int v) {
		data[i][j] = v;
	}
};

struct State {
	int i, j, p;
	State(){}
	State(int _i, int _j, int _p) : i(_i), j(_j), p(_p) {}
};

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void forward(Matrix &mat, int color, int dir, int &i, int &j) {
	int ii = i + dx[dir], jj = j + dy[dir];
	while (0 <= ii && ii < mat.rows && 0 <= jj && jj < mat.cols && mat.get(ii,jj) != color) {
		i = ii;
		j = jj;
		ii = i + dx[dir], jj = j + dy[dir];
	}
}

int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);
	int rows, cols;
	int init_i, init_j;
	int dst_i, dst_j;
	cin >> rows >> cols >> init_i >> init_j >> dst_i >> dst_j;
	init_i--;init_j--;dst_i--;dst_j--;
	Matrix mat(rows, cols);
	set<int> colors;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			char c;
			cin >> c;
			mat.set(i, j, (int)c);
			if (c != 'w') colors.insert((int)c);
		}
	}
	Matrix visit(rows, cols);
	State cur_state(init_i, init_j, -1);
	int front = 0;
	vector<State> q;
	q.push_back(cur_state);
	visit.set(init_i, init_j, 1);
	while (front < q.size()) {
		cur_state = q[front];
		if (cur_state.i == dst_i && cur_state.j == dst_j) break;
		int color = mat.get(cur_state.i, cur_state.j);
		for (set<int>::iterator si = colors.begin(); si != colors.end(); si++) {
			if (*si == color) continue;
			for (int k = 0; k < 4; k++) {
				int i = cur_state.i, j = cur_state.j;
				forward(mat, *si, k, i, j);
				if (!visit.get(i, j)) {
					visit.set(i, j, 1);
					q.push_back(State(i, j, front));
				}
			}
		}
		front++;
	}
	if (front >= q.size()) printf("No solution\n");
	while (front >= 0) {
		printf("%d,  %d\n", q[front].i + 1, q[front].j + 1);
		front = q[front].p;
	}
	return 0;
}
