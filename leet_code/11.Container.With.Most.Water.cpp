// 11. Container With Most Water
/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
 

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104
*/

// 思路：从最高的矩形出发，逐渐把冒尖的部分削平，合成一个宽度更大的矩形。

class Solution {
public:
	int maxArea(vector<int>& height) {
		int n = height.size();
		int maxIdx = 0;
		int maxH = height[0];
		for (int i = 0; i < n; i++) {
			if (maxH < height[i]) {
				maxH = height[i];
				maxIdx = i;
			}
		}
		std::vector<int> leftHeights(n);
		std::vector<int> rightHeights(n);
		int h = height[0];
		for (int i = 0; i < n; i++) {
			h = std::max(h, height[i]);
			leftHeights[i] = h;
		}
		h = height.back();
		for (int i = n - 1; i >= 0; i--) {
			h = std::max(h, height[i]);
			rightHeights[i] = h;
		}

		int p1 = maxIdx, p2 = maxIdx;
		int ret = 0;
		while (p1 > 0 && p2 < n - 1) {
			int a = std::min(leftHeights[p1], rightHeights[p2])*(p2 - p1);
			ret = std::max(a, ret);
			if (leftHeights[p1 - 1] > rightHeights[p2 + 1]) p1--;
			else p2++;
		}
		if (p2 >= n - 1) {
			while (p1 >= 0) {
				int a = std::min(leftHeights[p1], rightHeights[n - 1])*(n - 1 - p1);
				ret = std::max(a, ret);
				p1--;
			}
		}
		else {
			while (p2 <= n - 1) {
				int a = std::min(leftHeights[0], rightHeights[p2])*(p2 - 0);
				ret = std::max(a, ret);
				p2++;
			}
		}
		return ret;
	}
};
