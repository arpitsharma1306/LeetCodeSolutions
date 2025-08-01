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
    vector<int>sizes;
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = solve(root->left);
        int right = solve(root->right);

        if(left!=-1 && right!=-1 && left==right){
            sizes.push_back(left+right+1);
            return left+right+1;
        }

        return -1;
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        solve(root);
        sort(sizes.rbegin(),sizes.rend());

        if(sizes.size()<k) return -1;

        return sizes[k-1];

    }
};