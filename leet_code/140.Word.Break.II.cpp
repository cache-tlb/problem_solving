#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <list>
using namespace std;

class Solution {
public:
    void dfs(int start) {
        if (start == n) {
            paths.push_back(cur_path);
            return;
        }
        for (int i = start + 1; i <= n; i++) {
            if (adj[start*(n+1)+i] < 0) continue;
            cur_path.push_back(i);
            dfs(i);
            cur_path.pop_back();
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        std::vector<string> res;
        n = s.length();
        std::map<string, int> dict;
        for (int i = 0; i < wordDict.size(); i++) {
            dict[wordDict[i]] = i;
        }
        adj.resize((n+1)*(n+1), -1);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                string subs(s, i, j - i);
                if (dict.count(subs) == 0) continue;
                adj[i*(n+1)+j] = dict[subs];
            }
        }
        std::vector<bool> vis(n+1,0);
        std::list<int> que;
        que.push_back(0);
        vis[0] = 1;
        while (!que.empty()) {
            int cur = que.front();
            que.pop_front();
            for (int i = cur + 1; i <= n; i++) {
                if (adj[cur*(n+1)+i] >= 0 && !vis[i]) {
                    que.push_back(i);
                    vis[i] =  true;
                }
            }
        }
        if (!vis[n]) return res;
        paths.clear();
        cur_path.clear();
        cur_path.push_back(0);
        dfs(0);
        for (int i = 0; i < paths.size(); i++) {
            string s = "";
            for (int j = 1; j < paths[i].size(); j++) {
                int start = paths[i][j-1], end = paths[i][j];
                s = s + wordDict[ adj[start*(n+1)+end] ];
                if (j != paths[i].size() - 1) s += " ";
            }
            res.push_back(s);
        }
        return res;
    }
    int n;
    std::vector<int> adj;
    std::vector<int> cur_path;
    std::vector<std::vector<int> > paths;
};