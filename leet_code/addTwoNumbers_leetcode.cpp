#include <iostream>

using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int carry = 0;
        ListNode *node = new ListNode(0);
        ListNode *ret = node;
        while(l1 || l2 || carry) {
            int c1 = l1 ? l1->val : 0;
            int c2 = l2 ? l2->val : 0;
            int sum = c1 + c2 + carry;
            carry = sum / 10;
            ListNode *newNode = new ListNode(sum % 10);
            node->next = newNode;
            node = newNode;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return ret->next;
    }
};

int main(int argc, char const *argv[])
{
    /* code */

    return 0;
}
