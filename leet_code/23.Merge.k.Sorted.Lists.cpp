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
    struct Item {
        int row, val;
        Item() {}
        Item(int r, int v) : row(r), val(v) {}
    };
    struct cmp {
        bool operator () (const Item &a, const Item &b) {
            return (a.val < b.val) || (a.val == b.val && a.row < b.row);
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        std::vector<ListNode*> new_list;
        std::map<Item,int,cmp> q;
        int n = lists.size();
        std::vector<ListNode*> head(n, NULL);
        for (int i = 0; i < n; i++) {
            head[i] = lists[i];
            if (head[i]) q[Item(i,head[i]->val)] = 1;
        }
        while (!q.empty()) {
            Item item = (q.begin())->first;
            q.erase(item);
            new_list.push_back(new ListNode(item.val));
            int row = item.row;
            ListNode *next_node = head[row]->next;
            head[row] = next_node;
            if (next_node) q[Item(row, head[row]->val)] = 1;
        }
        for (int i = 1; i < new_list.size(); i++) {
            new_list[i-1]->next = new_list[i];
        }
        if (new_list.empty()) return NULL;
        return new_list[0];
    }
};