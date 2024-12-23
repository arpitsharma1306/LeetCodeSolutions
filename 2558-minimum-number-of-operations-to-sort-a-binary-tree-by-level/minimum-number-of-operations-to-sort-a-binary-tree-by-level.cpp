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
    int minSwaps(vector<int>&arr){
        int n=arr.size();
        map<int,int>mp;
        vector<int>temp=arr;
        sort(temp.begin(),temp.end());
        for(int i=0;i<n;i++){
            mp[temp[i]]=i;
        }
        int cnt=0;
        for(int i=0;i<n;){
            int idx=mp[arr[i]];
            if(idx==i){
                i++;
            }
            else{
                swap(arr[idx],arr[i]);
                cnt++;
            }
        }
        return cnt;
    }
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
            cnt+=minSwaps(arr);
        }

        return cnt;
    }
};