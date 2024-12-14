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
    map<int, map<int, multiset<int>>> mymap;
    void solve(TreeNode* curr, int col, int row) {
        if (!curr)
            return;

        mymap[col][row].insert(curr->val);

        solve(curr->left, col - 1, row + 1);
        solve(curr->right, col + 1, row + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        solve(root, 0, 0);

        for (auto& col : mymap) {
            vector<int> v;
            for (auto& row : col.second) {
                for (auto& val : row.second)
                    v.push_back(val);
            }
            ans.push_back(v);
        }

        return ans;
    }
};

//T.C-> O(N(logN)^3)