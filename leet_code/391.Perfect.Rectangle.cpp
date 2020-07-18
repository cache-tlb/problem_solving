class Solution {
public:
	struct Point{
		int x, y;
		Point(int x, int y) : x(x), y(y) {}
		bool operator < (const Point &that) const {
			return x < that.x || (x == that.x && y < that.y);
		}
	};
	bool isRectangleCover(vector<vector<int>>& rectangles) {
		std::map <Point,int> points;
		if (rectangles.empty()) return false;
		int s = 0;
		int x0 = rectangles[0][0], y0 = rectangles[0][1], x1 = rectangles[0][2], y1 = rectangles[0][3];
		for (int i = 0; i < rectangles.size(); i++) {
			Point p0(rectangles[i][0], rectangles[i][1]);
			Point p1(rectangles[i][2], rectangles[i][3]);
			x0 = std::min(x0, p0.x);
			y0 = std::min(y0, p0.y);
			x1 = std::max(x1, p1.x);
			y1 = std::max(y1, p1.y);
			Point p2(p0.x, p1.y);
			Point p3(p1.x, p0.y);
			points[p0]++;
			points[p1]++;
			points[p2]++;
			points[p3]++;
			s += (p1.x - p0.x) * (p1.y - p0.y);
		}
		Point corner[4] = { Point(x0,y0), Point(x1,y0), Point(x0,y1), Point(x1,y1) };
		for (int i = 0; i < 4; i++) {
			if (points[corner[i]] != 1)
				return false;
			points[corner[i]]++;
		}
		for (auto it = points.begin(); it != points.end(); it++) {
			if (it->second != 2 && it->second != 4) return false;
		}
		return s == (x1 - x0) * (y1 - y0);
	}
};
