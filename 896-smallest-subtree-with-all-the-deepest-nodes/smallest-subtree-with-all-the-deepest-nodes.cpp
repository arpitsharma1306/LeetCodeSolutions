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
    TreeNode* ans;
    int maxh;
    int solve(TreeNode* root,int curr){
        if(!root) return 0;
        int l = solve(root->left,curr+1);
        int r = solve(root->right,curr+1);
        if(l==r){
            if(maxh<=curr+l){
                ans=root;
                maxh=curr+l;
            }
        }

        return 1+max(l,r);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        maxh=0;
        solve(root,1);
        return ans;
    }
};