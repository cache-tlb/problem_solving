/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return NULL;
        if (k <= 1) return head;
        ListNode *ret = NULL;
        int n = 0;
        ListNode *node = head;
        while (node) {
            n++;
            node = node->next;
        }
        int cur_num = 0;
        ListNode *old_head = head;
        ListNode *new_tail = NULL;
        while (cur_num + k <= n) {
            ListNode *new_head = old_head;
            ListNode *cur_node = old_head->next;
            for (int i = 1; i < k; i++) {
                cur_node = old_head->next;
                old_head->next = cur_node->next;
                cur_node->next = new_head;
                new_head = cur_node;
            }
            if (!ret) ret = new_head;
            if (new_tail) new_tail->next = new_head;
            new_tail = old_head;
            old_head = old_head->next;
            cur_num += k;
        }
        if (!ret) ret = head;
        return ret;
    }
};