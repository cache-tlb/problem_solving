// 2. Add Two Numbers
// no trick
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *ret = new ListNode();
		ListNode *tail = ret;
		int carry = 0;
		while (carry || p1 || p2) {
			int s = carry;
			if (p1) s += p1->val;
			if (p2) s += p2->val;
			ListNode *node = new ListNode(s%10, NULL);
			carry = s / 10;
			tail->next = node;
			tail = node;
			if (p1) p1 = p1->next;
			if (p2) p2 = p2->next;
		}
		ListNode *tmp = ret->next;
		delete ret;
		return tmp;
	}
};