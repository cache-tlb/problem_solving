// 3838. Weighted Word Mapping
// notes: no trick
class Solution {
public:
	string mapWordWeights(vector<string>& words, vector<int>& weights) {
		std::string ret;
		for (int i = 0; i < words.size(); i++) {
			const std::string &str = words[i];
			int s = 0;
			for (int j = 0; j < str.length(); j++) {
				s += weights[str[j] - 'a'];
			}
			s = s % 26;
			s = 25 - s;
			ret.push_back('a' + s);
		}
		return ret;
	}
};