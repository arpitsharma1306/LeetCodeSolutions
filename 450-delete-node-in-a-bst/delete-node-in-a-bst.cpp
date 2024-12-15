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
    int findMax(TreeNode* root) {
        int maxi = root->val;
        while (root) {
            maxi = max(maxi, root->val);
            root = root->right;
        }
        return maxi;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return NULL;

        if (root->val < key)
            root->right = deleteNode(root->right, key);
        else if (root->val > key)
            root->left = deleteNode(root->left, key);
        else {
            if (root->left && root->right) {
                int v = findMax(root->left);
                root->val = v;
                root->left = deleteNode(root->left, v);
                return root;
            } else if (root->left) {
                return root->left;
            } else if (root->right) {
                return root->right;
            } else {
                return NULL;
            }
        }

        return root;
    }
};