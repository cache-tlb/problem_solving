// 3699. Number of ZigZag Arrays I
/*
You are given three integers n, l, and r.

A ZigZag array of length n is defined as follows:

Each element lies in the range [l, r].
No two adjacent elements are equal.
No three consecutive elements form a strictly increasing or strictly decreasing sequence.
Return the total number of valid ZigZag arrays.

Since the answer may be large, return it modulo 109 + 7.

A sequence is said to be strictly increasing if each element is strictly greater than its previous one (if exists).

A sequence is said to be strictly decreasing if each element is strictly smaller than its previous one (if exists).

 

Example 1:

Input: n = 3, l = 4, r = 5

Output: 2

Explanation:

There are only 2 valid ZigZag arrays of length n = 3 using values in the range [4, 5]:

[4, 5, 4]
[5, 4, 5]​​​​​​​
Example 2:

Input: n = 3, l = 1, r = 3

Output: 10

Explanation:

There are 10 valid ZigZag arrays of length n = 3 using values in the range [1, 3]:

[1, 2, 1], [1, 3, 1], [1, 3, 2]
[2, 1, 2], [2, 1, 3], [2, 3, 1], [2, 3, 2]
[3, 1, 2], [3, 1, 3], [3, 2, 3]
All arrays meet the ZigZag conditions.

 

Constraints:

3 <= n <= 2000
1 <= l < r <= 2000
 
*/
// 

class Solution {
public:
	int zigZagArrays(int n, int l, int r) {
		const int mod = 1e9 + 7;
		int d = r - l;
		std::vector<std::vector<int> > dp1, dp2;	// dp1[i][j] -> len is i, last = j, increasing;
		dp1.resize(n+1);
		dp2.resize(n + 1);
		for (int i = 0; i <= n; i++) {
			dp1[i].resize(d + 1, 0);
			dp2[i].resize(d + 1, 0);
		}
		for (int j = 0; j <= d; j++) {
			dp1[1][j] = 1;
			dp2[1][j] = 1;
		}
		std::vector<int> s1(d + 1);
		std::vector<int> s2(d + 1);
		for (int i = 2; i <= n; i++) {
			// dp1[i][j] = sum( dp2[i-1][k] ) for k < j
			// dp2[i][j] = sum( dp1[i-1][k] ) for k > j
			memset(s1.data(), 0, sizeof(int)*s1.size());
			memset(s2.data(), 0, sizeof(int)*s2.size());
			int acc1 = 0, acc2 = 0;
			for (int j = 0; j <= d; j++) {
				acc1 = (acc1 + dp1[i - 1][j]) % mod;
				acc2 = (acc2 + dp2[i - 1][j]) % mod;
				s1[j] = acc1;
				s2[j] = acc2;
			}
			for (int j = 0; j <= d; j++) {
				if (j == 0) dp1[i][j] = 0;
				else dp1[i][j] = s2[j-1];
				if (j == d) dp2[i][j] = 0;
				else dp2[i][j] = (s1[d] - s1[j] + mod) % mod;
			}
		}
		int ret = 0;
		for (int j = 0; j <= d; j++) {
			ret = (ret + dp1[n][j]) % mod;
			ret = (ret + dp2[n][j]) % mod;
		}
		return ret;
	}
};