// 3093. Longest Common Suffix Queries
// use trie

class Solution {
public:
	struct TrieNode {
		std::map<int,TrieNode *> children;
		TrieNode() { shortest_index = -1; shortest_len = 1e6; }
		// shortest len and index among all (grand) children
		int shortest_index;
		int shortest_len;
	};
	TrieNode root;
	void buildTrie(const std::string &str, int idx) {
		TrieNode *cur = &root;
		int len = str.length();
		if (len < cur->shortest_len) {
			cur->shortest_len = len;
			cur->shortest_index = idx;
		}
		for (int i = 0; i < str.length(); i++) {
			int child_id = str[i] - 'a';
			if (cur->children.count(child_id) == 0) {
				cur->children[child_id] = new TrieNode;
			}
			cur = cur->children[child_id];
			if (len < cur->shortest_len) {
				cur->shortest_len = len;
				cur->shortest_index = idx;
			}
		}
	}
	int queryTrie(const std::string &str) {
		TrieNode *cur = &root;
		int ret = -1;
		for (int i = 0; i < str.length(); i++) {
			int child_id = str[i] - 'a';
			if (cur->children.count(child_id) > 0) {
				cur = cur->children[child_id];
			}
			else {
				break;
			}
		}
		ret = cur->shortest_index;
		return ret;
	}
	vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
		for (auto & v : wordsContainer) {
			std::reverse(v.begin(), v.end());
		}
		for (auto & v : wordsQuery) {
			std::reverse(v.begin(), v.end());
		}

		// form a trie
		for (int i = 0; i < wordsContainer.size(); i++) {
			buildTrie(wordsContainer[i], i);
		}
		std::vector<int> ret;
		for (const auto & v : wordsQuery) {
			ret.push_back(queryTrie(v));
		}
		return ret;
	}
};