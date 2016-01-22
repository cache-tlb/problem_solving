#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool finished = false;
        ListNode *res = new ListNode(0);
        ListNode *curNode = res;
        while (!finished) {
            finished = true;
            int minVal = 0;
            int minPos = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (!lists[i]) continue;
                if (minPos < 0) minPos = i, minVal = lists[i]->val;
                else if (minVal > lists[i]->val) minPos = i, minVal = lists[i]->val;
            }
            if (minPos >= 0) {
                ListNode *newNode = new ListNode(minVal);
                curNode->next = newNode;
                curNode = newNode;
                lists[minPos] = lists[minPos]->next;
                finished = false;
            }
        }
        return res->next;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}
