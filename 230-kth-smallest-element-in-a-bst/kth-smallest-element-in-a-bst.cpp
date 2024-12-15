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
    int ans,kth;
    void inOrder(TreeNode* root){
        if(!root) return;

        inOrder(root->left);
        kth--;
        if(kth==0){
            ans=root->val;
            return;
        }
        inOrder(root->right);
        
    }

    int kthSmallest(TreeNode* root, int k) {
        kth=k;
        inOrder(root);

        return ans;
    }
};