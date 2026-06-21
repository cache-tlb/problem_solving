// 6. Zigzag Conversion
// no trick, no magic
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows <= 1) return s;
		if (s.length() <= numRows) return s;
		std::vector<std::string > rowStr(numRows);
		int k = numRows - 1;
		for (int i = 0; i < s.length(); i++) {
			int r = i % (2 * k);
			int row = std::min(r, 2*k-r);
			rowStr[row].push_back(s[i]);
		}
		std::string ret;
		for (auto &str : rowStr) {
			ret = ret + str;
		}
		return ret;
	}
};