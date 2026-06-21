// 2130. Maximum Twin Sum of a Linked List
// notes: no trick, or use in-place reverse linked list
class Solution {
public:
	int pairSum(ListNode* head) {
		std::vector<int> vals;
		while (head) {
			vals.push_back(head->val);
			head = head->next;
		}
		int ret = 0;
		for (int i = 0; i < vals.size(); i++) {
			int s = vals[i] + vals[vals.size() - 1 - i];
			ret = std::max(ret, s);
		}
		return ret;
	}
};