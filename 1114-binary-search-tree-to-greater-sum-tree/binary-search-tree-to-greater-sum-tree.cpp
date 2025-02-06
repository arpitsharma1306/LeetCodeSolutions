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
    vector<int>inorder;
    void inordertraverse(TreeNode* root){
        if(!root) return;
        inordertraverse(root->left);
        inorder.push_back(root->val);
        inordertraverse(root->right);
    }

    void solve(TreeNode* root,unordered_map<int,int>&mp){
        if(!root) return;

        int value = mp[root->val];
        root->val=value;

        solve(root->left,mp);
        solve(root->right,mp);
    }

    TreeNode* bstToGst(TreeNode* root) { 
        inordertraverse(root);
        unordered_map<int,int>mp;
        int sum=0;
        int n=inorder.size();
        for(int r=n-1;r>=0;r--){
            sum+=inorder[r];
            mp[inorder[r]]=sum;
        }

        solve(root,mp);

        return root;
    }
};