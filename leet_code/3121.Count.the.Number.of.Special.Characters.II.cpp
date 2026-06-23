// 3121. Count the Number of Special Characters II
// no trick
class Solution {
public:
	int numberOfSpecialChars(string word) {
		int ret = 0;
		int find_upper[26];
		int find_lower[26];
		int earlist_upper[26];
		int latest_lower[26];
		for (int i = 0; i < 26; i++) {
			find_upper[i] = 0;
			find_lower[i] = 0;
			earlist_upper[i] = word.length();
			latest_lower[i] = 0;
		}
		for (int pos = 0; pos < word.length(); pos++) {
			char c = word[pos];
			if ('a' <= c && c <= 'z') {
				int i = c - 'a';
				find_lower[i]++;
				latest_lower[i] = std::max(latest_lower[i], pos);
			}
			else if ('A' <= c && c <= 'Z') {
				int i = c - 'A';
				find_upper[i]++;
				earlist_upper[i] = std::min(earlist_upper[i], pos);
			}
		}
		for (int i = 0; i < 26; i++) {
			if (find_upper[i] == 0 || find_lower[i] == 0) continue;
			if (earlist_upper[i] > latest_lower[i]) ret++;
		}
		return ret;
	}
};