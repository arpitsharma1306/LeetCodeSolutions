/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void serializing(TreeNode* root, ostringstream& out){
        if(root){
            out << root->val << ' ';
            serializing(root->left,out);
            serializing(root->right,out);
        }else{
            out << "# ";
        }
    }

    TreeNode* decode(istringstream& in){
        string val;
        in >> val;
        if(val=="#") return NULL;

        TreeNode* root = new TreeNode(stoi(val));
        root->left=decode(in);
        root->right=decode(in);

        return root;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializing(root,out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return decode(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));