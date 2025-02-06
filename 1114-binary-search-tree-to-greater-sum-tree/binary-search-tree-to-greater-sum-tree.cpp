/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum = 0; // Global sum tracker

    void reverseInorder(TreeNode* root) {
        if (!root) return;

        // Process right subtree first (greater values)
        reverseInorder(root->right);

        // Accumulate sum and update the node
        sum += root->val;
        root->val = sum;

        // Process left subtree
        reverseInorder(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        reverseInorder(root);
        return root;
    }
};