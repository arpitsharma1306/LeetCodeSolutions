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
    int maxlength;
    int solve(TreeNode* root){
        if(!root) return 0;

        int left=solve(root->left);
        int right=solve(root->right);

        if(maxlength<left+right+1) maxlength=left+right+1;

        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        maxlength=0;

        solve(root);

        return maxlength-1;
    }
};