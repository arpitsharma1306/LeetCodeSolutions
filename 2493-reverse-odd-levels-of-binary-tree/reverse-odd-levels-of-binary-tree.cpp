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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int sz=q.size();
            vector<TreeNode*>v;
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();
                q.pop();
                v.push_back(node);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(level%2==1){
                int i=0;
                int j=sz-1;
                while(i<j){
                    int temp=v[i]->val;
                    v[i]->val=v[j]->val;
                    v[j]->val=temp;
                    i++;
                    j--;
                }
            }
            level++;
        }

        return root;
    }
};