/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int find(vector<int>& inorder, int start, int end, int key) {
        int i;
        for (i = start; i <= end; i++) {
            if (inorder[i] == key)
                break;
        }
        return i;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int instart,
                    int inend, int& preindex) {
        if (instart > inend)
            return NULL;
        int rootval = preorder[preindex++];
        TreeNode* root = new TreeNode(rootval);

        int inindex = find(inorder, instart, inend, rootval);

        root->left = solve(preorder, inorder, instart, inindex - 1, preindex);
        root->right = solve(preorder, inorder, inindex + 1, inend, preindex);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        int preindex = 0;
        TreeNode* root =
            solve(preorder, inorder, 0, inorder.size() - 1, preindex);
        return root;
    }
};