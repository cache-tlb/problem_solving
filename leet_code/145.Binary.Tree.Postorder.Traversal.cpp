/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct Item {
        TreeNode *node;
        int state;
        Item(TreeNode *n, int s) : node(n), state(s) {}
        Item() : node(NULL), state(0) {}
    };
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> res;
        std::list<Item> queue;
        queue.push_back(Item(root, 0));
        while (!queue.empty()) {
            Item item = queue.front();
            queue.pop_front();
            TreeNode *node = item.node;
            if (!node) continue;
            if (item.state == 0) {
                item.state = 1;
                queue.push_front(Item(node, 1));
                queue.push_front(Item(node->right, 0));
                queue.push_front(Item(node->left, 0));
            } else {
                res.push_back(node->val);
            }
        }
        return res;
    }
};