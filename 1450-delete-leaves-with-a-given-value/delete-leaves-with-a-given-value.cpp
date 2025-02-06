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
    void solve(TreeNode*& root,int target){
        if(!root) return;

        solve(root->left,target);
        solve(root->right,target);
        if(!root->left && !root->right){
            if(root->val==target){
                root=NULL;
                return;
            }
            else return;
        }
 
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        solve(root,target);
        return root;
    }
};