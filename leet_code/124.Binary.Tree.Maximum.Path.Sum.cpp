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
    int max_val;
    int traverse(TreeNode *node) {
        int res = node->val;
        int left = 0, right = 0;
        if (node->left) {
            left = traverse(node->left);
        }
        if (node->right) {
            right = traverse(node->right);
        }
        if (node->val + left + right > max_val) max_val = node->val+left+right;
        int branch = std::max(left, right);
        res += std::max(0, branch);
        if (res > max_val) max_val = res;
        return res;
    }
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        max_val = root->val;
        traverse(root);
        return max_val;
    }
};
