// 5. Longest Palindromic Substring
// no trick, just try each length and check if is palindromic 
class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.length();
		if (n <= 1) return s;
		for (int len = n; len >= 1; len--) {
			// enum each position for length len
			for (int i = 0; i + len <= n; i++) {
				// check substr: s[i+0:i+len]
				bool valid = true;
				for (int j = 0; j < len; j++) {
					if (s[i+j] != s[i+len-1-j]) {
						valid = false;
						break;
					}
				}
				if (valid) return s.substr(i, len);
			}
		}
		return std::string() + s[0];
	}
};