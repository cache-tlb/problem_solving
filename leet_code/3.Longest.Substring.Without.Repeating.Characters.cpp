// 3. Longest Substring Without Repeating Characters
// note: no trick, just try possible length, < 128
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		bool bitmap[128];
		for (int len = 127; len >= 1; len--) {
			bool find = false;
			for (int i = 0; i + len <= s.length(); i++) {
				memset(bitmap, 0, sizeof(bitmap));
				bool valid = true;
				for (int j = i; j < i + len; j++) {
					if (bitmap[s[j]]) {
						valid = false;
						break;
					}
					bitmap[s[j]] = 1;
				}
				if (!valid) continue;
				find = true;
				break;
			}
			if (find) return len;
		}
		return 0;
	}
};