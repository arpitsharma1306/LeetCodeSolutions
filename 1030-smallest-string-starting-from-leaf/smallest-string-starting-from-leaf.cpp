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
string answer = "~"; // Initialize with a high lexicographical value

    void dfs(TreeNode* root, string output) {
        if (!root) return;

        // Convert node value (0-25) to corresponding character ('a' - 'z') and append
        output += ('a' + root->val);

        // If it's a leaf node, check if we found a smaller lexicographical string
        if (!root->left && !root->right) {
            reverse(output.begin(), output.end()); // Reverse to form correct root-to-leaf string
            answer = min(answer, output); // Store lexicographically smaller string
            return;
        }

        // Recur for left and right subtrees
        dfs(root->left, output);
        dfs(root->right, output);
    }

    string smallestFromLeaf(TreeNode* root) {
        answer = "~"; // Any lexicographical string would be smaller
        dfs(root, "");
        return answer;
    }
};