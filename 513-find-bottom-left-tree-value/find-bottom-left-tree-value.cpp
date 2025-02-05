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
    int result,maxheight;
    void dfs(TreeNode* root,int height){
        if(!root) return;

        if(!root->left && !root->right){
            if(height>maxheight){
                maxheight = height;
                result=root->val;
            }
        }

        dfs(root->left,height+1);
        dfs(root->right,height+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        
        maxheight=0;
        dfs(root,1);

        return result;
    }
};