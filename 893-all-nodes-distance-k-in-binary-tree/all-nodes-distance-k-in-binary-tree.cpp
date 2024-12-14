/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // node to its parent map
    map<TreeNode*,TreeNode*>mp;
    vector<int>ans;

    void parentMapping(TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            if(node->left){
                mp[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right]=node;
                q.push(node->right);
            }
        }

        return;
    }

    void nodeAtk(TreeNode* root,int k){
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        int dist=0;
        queue<TreeNode*>q;
        map<TreeNode*, bool> isVisited;
        q.push(root);
        isVisited[root] = true;

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !isVisited[node->left]){
                    q.push(node->left);
                    isVisited[node->left] = true;
                }
                if(node->right && !isVisited[node->right]){
                    q.push(node->right);
                    isVisited[node->right] = true;
                }
                if(mp[node] && !isVisited[mp[node]]){
                    q.push(mp[node]);
                    isVisited[mp[node]] = true;
                }
            }
            dist++;
            if(dist==k){
                while(!q.empty()){
                    TreeNode* node=q.front();
                    q.pop();
                    ans.push_back(node->val);
                }
                break;
            }
        }

        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parentMapping(root);

        nodeAtk(target,k);

        return ans;
    }
};