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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>q;
        q.push(root);
        priority_queue<long long ,vector<long long>,greater<long long>>pq;

        while(!q.empty()){
            int levelSize=q.size();
            long long levelSum=0;

            for(int i=0;i<levelSize;i++){
                TreeNode* curr=q.front();
                q.pop();

                levelSum+=(long long)curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                
            }

            pq.push(levelSum);
            if(pq.size()>k) pq.pop();
        }

        return pq.size()==k?pq.top():-1;
    }
};