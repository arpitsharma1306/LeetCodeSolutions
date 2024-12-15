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
    vector<int>list;
    void preOrder(TreeNode* root){
        if(!root) return;

        list.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
    void flatten(TreeNode* root) {
        preOrder(root);
        int n=list.size();
        for(int i=1;i<n;i++){
            root->left=NULL;
            root->right=new TreeNode(list[i]);
            root=root->right;
        }
    }
};