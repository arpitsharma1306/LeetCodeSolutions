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
    bool validate(TreeNode* node,TreeNode* minnode, TreeNode* maxnode){
        if(!node) return true;

        if(minnode && (minnode->val >= node->val)) return false;

        if(maxnode && (maxnode->val <= node->val)) return false;

        return validate(node->left,minnode,node) && validate(node->right,node,maxnode);
    }
    bool isValidBST(TreeNode* root) {
        return validate(root,nullptr,nullptr);
    }
};