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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int cnt=0;
        while(!q.empty()){
            vector<int>arr;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();
                q.pop();
                arr.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            int n=arr.size();
            for(int i=0;i<n-1;i++){
                int minIdx=i;
                for(int j=i+1;j<n;j++){
                    if(arr[j]<arr[minIdx]){
                        minIdx=j;
                    }
                }
                if(minIdx!=i){
                    cnt++;
                    swap(arr[minIdx],arr[i]);
                }
            }
        }

        return cnt;
    }
};