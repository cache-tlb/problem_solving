class Solution {
public:
    std::vector<std::vector<int> > adj_list;
    std::vector<std::vector<int> > dis_set;
    std::vector<int> distance;

    bool is_adj(const std::string &a, const std::string &b) {
        if (a.length()!=b.length()) return false;
        int count = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) {
                count++;
                if (count > 1) return false;
            }
        }
        return true;
    } 
    void recur(int node_id,  vector<vector<int> > &res, vector<int> &cur_path) {
        if (distance[node_id] == 1) {
            res.push_back(cur_path);
            return;
        }
        int dis = distance[node_id]-1;
        for (int i = 0; i < adj_list[node_id].size(); i++) {
            int idx = adj_list[node_id][i];
            if (distance[idx] != dis) continue;
            cur_path.push_back(idx);
            recur(idx, res, cur_path);
            cur_path.pop_back();
        }
    }
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string> > ret;
        std::map<std::string,int> word2id;
        for (int i = 0; i < wordList.size(); i++) {
            word2id[wordList[i]] = i;
        }
        if (word2id.count(endWord) == 0) return ret;
        int end_id = word2id[endWord];
        int n = wordList.size();
        adj_list.resize(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                bool adj = is_adj(wordList[i], wordList[j]);
                if (adj) {
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }
        // find the distance of each word to beginWord
        distance.resize(n, -1);
        std::list<int> queue;
        for (int i = 0; i < n; i++) {
            if (is_adj(beginWord, wordList[i])) {
                queue.push_back(i);
                distance[i] = 1;
            }
        }
        while (!queue.empty()) {
            int current_index = queue.front();
            int d = distance[current_index];
            queue.pop_front();
            for (int i = 0; i < adj_list[current_index].size(); i++) {
                int neighbor_index = adj_list[current_index][i];
                if (distance[neighbor_index] > 0) continue;
                queue.push_back(neighbor_index);
                distance[neighbor_index] = d + 1;
            }
        }

        int end_dis = distance[end_id];
        if (end_dis < 0) return ret;
        dis_set.resize(n+1);
        for (int i = 0 ; i < n; i++) {
            if (distance[i] < 0) continue;
            dis_set[distance[i]].push_back(i);
        }
        vector<vector<int> > res;
        vector<int> cur_path;
        cur_path.push_back(end_id);
        recur(end_id, res, cur_path);
        for (int i = 0; i < res.size(); i++) {
            std::vector<std::string> tmp;
            tmp.push_back(beginWord);
            for (int j = res[i].size() - 1; j >= 0; j--) {
                tmp.push_back(wordList[res[i][j]]);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};