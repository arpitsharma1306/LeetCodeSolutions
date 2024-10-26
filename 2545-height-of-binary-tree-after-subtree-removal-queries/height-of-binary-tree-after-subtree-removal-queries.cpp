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
    int level[100001];
    int height[100001];
    int lvlMaxHgt[100001];
    int secondlvlMaxHgt[100001];

    int findHeight(TreeNode* root, int lvl) {
        if (!root) {
            return 0;
        }

        level[root->val] = lvl;

        height[root->val] = max(findHeight(root->left, lvl + 1),
                                findHeight(root->right, lvl + 1)) +
                            1;

        if (lvlMaxHgt[lvl] < height[root->val]) {
            secondlvlMaxHgt[lvl] = lvlMaxHgt[lvl];
            lvlMaxHgt[lvl] = height[root->val];
        } else if (secondlvlMaxHgt[lvl] < height[root->val]) {
            secondlvlMaxHgt[lvl] = height[root->val];
        }

        return height[root->val];
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> result;

        findHeight(root, 0);

        // L+H-1 (level of that node + height of that from leaf node - 1(height
        // node wali thi and hume edges wali height use karni h.))

        for (int i = 0; i < queries.size(); i++) {
            int node = queries[i];

            int L = level[node];
            // height after removing node from that level. If that node not
            // having max. height than no problem but if it then take the second
            // maximum height
            int H = height[node] == lvlMaxHgt[L] ? secondlvlMaxHgt[L]
                                                 : lvlMaxHgt[L];
            int ans = L + H - 1;
            result.push_back(ans);
        }

        return result;
    }
};