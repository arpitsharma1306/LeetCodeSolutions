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
class FindElements {
public:
    TreeNode* root;
    void solve(TreeNode* root,int value){
        if(root==NULL){
            return;
        }

        root->val = value;
        if(root->left) solve(root->left, 2*value + 1);
        if(root->right) solve(root->right, 2*value + 2);

        return;
    }
    FindElements(TreeNode* node) {
        root=node;
        root->val=0;
        if(root->left) solve(root->left,1);
        if(root->right) solve(root->right,2);
    }
    
    bool traverse(TreeNode* root,int target){
        if(!root){
            return false;
        }
        if(root->val==target){
            return true;
        }

        bool left = traverse(root->left,target);
        bool right = traverse(root->right,target);

        return left||right;
    }

    bool find(int target) {
        return traverse(root,target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */