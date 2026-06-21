// 7. Reverse Integer
/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-231 <= x <= 231 - 1
*/
// the only trick is boundry check
class Solution {
public:
	int reverse(int x) {
		const int MAX_INT = 2147483647;
		if (x == 0) return 0;
		int sign = (x >= 0 ? 1 : -1);
		if (x >= MAX_INT) return 0;
		if (x < -MAX_INT) return 0;
		x = abs(x);
		std::vector<int> digits;
		while (x) {
			int n = x % 10;
			x /= 10;
			digits.push_back(n);
		}
		int s = 0;
		for (auto v : digits) {
			if (s > MAX_INT / 10) return 0;
			s = 10 * s + v;
			if (s < 0) return 0;
		}
		return s*sign;
	}
};