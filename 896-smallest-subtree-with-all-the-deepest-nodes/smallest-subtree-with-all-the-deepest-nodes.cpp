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
    int height;
    void maxdepth(TreeNode* root,int curr){
        if(!root) return;
        height=max(height,curr);

        if(root->left) maxdepth(root->left,curr+1);
        if(root->right) maxdepth(root->right,curr+1);
    }

    void maxdepthNodes(TreeNode* root,unordered_map<TreeNode*,int>&mp,int curr){
        if(!root) return;
        if(curr==height) mp[root]++;

        if(root->left) maxdepthNodes(root->left,mp,curr+1);
        if(root->right) maxdepthNodes(root->right,mp,curr+1);
    }

    TreeNode* findingNode(TreeNode* root,unordered_map<TreeNode*,int>mp){
        if(!root) return NULL;

        if(mp.find(root)!=mp.end()){
            return root;
        }

        TreeNode* leftN=findingNode(root->left,mp);
        TreeNode* rightN=findingNode(root->right,mp);

        if(leftN!=NULL && rightN!=NULL){
            return root;
        }

        if(leftN!=NULL) return leftN;

        return rightN;
        
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        height = 0;
        maxdepth(root,0);

        unordered_map<TreeNode*,int>mp;
        maxdepthNodes(root,mp,0);

        TreeNode* answer = findingNode(root,mp);

        return answer;
    }
};