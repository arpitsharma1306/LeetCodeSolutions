/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode*& root, int val) {
        if (!root) {
            root = new TreeNode(val);
            return;
        }

        if (root->val > val)
            solve(root->left, val);
        else
            solve(root->right, val);
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        solve(root, val);

        return root;
    }
};