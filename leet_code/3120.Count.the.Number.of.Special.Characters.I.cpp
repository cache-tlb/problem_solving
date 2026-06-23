// 3120. Count the Number of Special Characters I
// easy

class Solution {
public:
	int numberOfSpecialChars(string word) {
		int ret = 0;
		int find_upper[26] = {};
		int find_lower[26] = {};
		for (int pos = 0; pos < word.length(); pos++) {
			char c = word[pos];
			if ('a' <= c && c <= 'z') {
				int i = c - 'a';
				find_lower[i]++;
			}
			else if ('A' <= c && c <= 'Z') {
				int i = c - 'A';
				find_upper[i]++;
			}
		}
		for (int i = 0; i < 26; i++) {
			if (find_upper[i] == 0 || find_lower[i] == 0) continue;
			ret++;
		}
		return ret;
	}
};