/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int cross(const Point &O, const Point &A, const Point &B) {
        int crs = (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
        if (crs != 0) return crs;
        return ((A.x - O.x) * (B.x - O.x) + (A.y - O.y) * (B.y - O.y));
        // return crs;
    }
    vector<Point> convex_hull(vector<Point> P) {
        int n = P.size(), k = 0;
        vector<Point> H(2*n);

        // Sort points lexicographically
        auto cmp = [](const Point &a, const Point &b) {
            return a.x < b.x || (a.x == b.x && a.y < b.y);
        };
        sort(P.begin(), P.end(), cmp);

        // Build lower hull
        for (int i = 0; i < n; ++i) {
            while (k >= 2 && cross(H[k-2], H[k-1], P[i]) < 0) k--;
            H[k++] = P[i];
        }

        // Build upper hull
        for (int i = n-2, t = k+1; i >= 0; i--) {
            while (k >= t && cross(H[k-2], H[k-1], P[i]) < 0) k--;
            H[k++] = P[i];
        }

        H.resize(k-1);
        int rdx = H[1].x - H[0].x, rdy = H[1].y - H[0].y;
        bool is_line = true;
        for (int i = 2; i < H.size(); i++) {
            int dx = H[i].x - H[0].x, dy = H[i].y - H[0].y;
            if (dx*rdy != dy*rdx) is_line = false;
        }
        if (is_line) H.resize(H.size()/2+1);
        return H;
    }
    vector<Point> outerTrees(vector<Point>& points) {
        if (points.size() <= 3) return points;
        return convex_hull(points);
    }
};