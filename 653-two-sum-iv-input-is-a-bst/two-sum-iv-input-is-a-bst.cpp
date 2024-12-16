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
class BSTIterator {
    stack<TreeNode*> s;
    // reverse==true->before
    // reverse==false->next
    bool reverse = true;

public:
    BSTIterator(TreeNode* root, bool isreverse) {
        reverse = isreverse;
        pushAll(root);
    }
    int next() {
        TreeNode* node = s.top();
        s.pop();
        if (!reverse)
            pushAll(node->right);
        else
            pushAll(node->left);
        return node->val;
    }

    void pushAll(TreeNode* node) {
        while (node != NULL) {
            s.push(node);
            if (reverse == true)
                node = node->right;
            else
                node = node->left;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root)
            return false;
        // for next
        BSTIterator l(root, false);
        // for before
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();

        while (i < j) {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = l.next();
            else
                j = r.next();
        }

        return false;
    }
};