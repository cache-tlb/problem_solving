const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};
class Solution {
public:
    struct Item {
        int dis, pos;
        Item() {}
        Item(int d, int p) : dis(d), pos(p) {}
    };
    struct cmp{
        bool operator () (const Item &a, const Item &b) {
            return a.dis < b.dis || (a.dis == b.dis && a.pos < b.pos);
        }
    };
    int trapRainWater(vector<vector<int> >& heightMap) {
        int n = heightMap.size();
        if (n <= 2) return 0;
        int m = heightMap[0].size();
        if (m <= 2) return 0;
        std::vector<int> dist(n*m, -1);
        std::map<Item,int,cmp> pq;
        for (int j = 0; j < m; j++) {
            pq[Item(0, 0*m + j)] = 1;
            pq[Item(0, (n-1)*m + j)] = 1;
        }
        for (int i = 1; i < n - 1; i++) {
            pq[Item(0, i*m + 0)] = 1;
            pq[Item(0, i*m + m-1)] = 1;
        }
        while (!pq.empty()) {
            Item item = pq.begin()->first;
            pq.erase(pq.begin());
            int row = item.pos/m, col = item.pos%m;
            if (dist[item.pos] >= 0) continue;
            dist[item.pos] = item.dis;
            for (int k = 0; k < 4; k++) {
                int new_row = row + dy[k], new_col = col+ dx[k];
                if (new_row < 0 || new_row >= n || new_col < 0 || new_col >= m) continue;
                int new_index = new_row*m + new_col;
                int new_dis = std::max(heightMap[row][col], item.dis);
                if (dist[new_index] < 0 || dist[new_index] > new_dis) {
                    Item new_item(new_dis, new_index);
                    pq[new_item] = 1;
                }
            }
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++)
        //         std::cout << dist[i*m+j] << ' ';
        //     std::cout << std::endl;
        // }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (heightMap[i][j] < dist[i*m+j]) {
                    res += dist[i*m+j] - heightMap[i][j];
                }
            }
        }
        return res;
    }
};
