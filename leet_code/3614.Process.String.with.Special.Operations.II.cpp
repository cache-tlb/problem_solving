// 3614. Process String with Special Operations II
/*
You are given a string s consisting of lowercase English letters and the special characters: '*', '#', and '%'.

You are also given an integer k.

Build a new string result by processing s according to the following rules from left to right:

If the letter is a lowercase English letter append it to result.
A '*' removes the last character from result, if it exists.
A '#' duplicates the current result and appends it to itself.
A '%' reverses the current result.
Return the kth character of the final string result. If k is out of the bounds of result, return '.'.

 

Example 1:

Input: s = "a#b%*", k = 1

Output: "a"

Explanation:

i	s[i]	Operation	Current result
0	'a'	Append 'a'	"a"
1	'#'	Duplicate result	"aa"
2	'b'	Append 'b'	"aab"
3	'%'	Reverse result	"baa"
4	'*'	Remove the last character	"ba"
The final result is "ba". The character at index k = 1 is 'a'.

Example 2:

Input: s = "cd%#*#", k = 3

Output: "d"

Explanation:

i	s[i]	Operation	Current result
0	'c'	Append 'c'	"c"
1	'd'	Append 'd'	"cd"
2	'%'	Reverse result	"dc"
3	'#'	Duplicate result	"dcdc"
4	'*'	Remove the last character	"dcd"
5	'#'	Duplicate result	"dcddcd"
The final result is "dcddcd". The character at index k = 3 is 'd'.

Example 3:

Input: s = "z*#", k = 0

Output: "."

Explanation:

i	s[i]	Operation	Current result
0	'z'	Append 'z'	"z"
1	'*'	Remove the last character	""
2	'#'	Duplicate the string	""
The final result is "". Since index k = 0 is out of bounds, the output is '.'.

 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters and special characters '*', '#', and '%'.
0 <= k <= 1015
The length of result after processing s will not exceed 1015.
*/

// notes: keep track of the length of the str after each opeator.
// then backtrace k, find its coresponding pos in previous operations.

class Solution {
public:
	char processStr(string s, long long k) {
		std::vector<long long> len(s.length());	// the length of string after applying the operator s[i]
		long long acc = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '*') {
				if (acc > 0) acc--;
			}
			else if (s[i] == '#') {
				acc *= 2;
			}
			else if (s[i] == '%') {

			}
			else {
				acc += 1;
			}
			len[i] = acc;
		}

		if (k >= acc) return '.';
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s[i] == '%') {
				k = len[i] - 1 - k;
			}
			else if (s[i] == '#') {
				k = k % (len[i] / 2);
			}
			else if (s[i] == '*') {
				// nothing
			}
			else if (k + 1 == len[i]) {
				return s[i];
			}
		}
		return '.';
	}
};