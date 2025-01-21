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
    void dfs(TreeNode* root,int value,int parent,int depth,int &targetParent,int& targetDepth){
        if(!root){
            return;
        }
        if(root->val==value){
            targetParent=parent;
            targetDepth=depth;
            return;
        }
        if(root->left){
            dfs(root->left,value,root->val,depth+1,targetParent,targetDepth);
        } 
        if(root->right){
            dfs(root->right,value,root->val,depth+1,targetParent,targetDepth);
        }

        return;

    }
    bool isCousins(TreeNode* root, int x, int y) {
        int depthX = -1, depthY = -1;
        int parentX = -1, parentY =-1;

        dfs(root,x,0,-1,parentX,depthX);
        dfs(root,y,0,-1,parentY,depthY);

        if(parentX==parentY) return false;
        if(depthX!=depthY) return false;

        return true;
    }
};