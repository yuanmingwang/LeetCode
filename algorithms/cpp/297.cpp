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
    /** 297.Serialize and Deserialize Binary Tree
        Binary Tree
        Traverse

        Intuition: 
            We perform preorder traversal, serializing the binary tree in the process. 
            Note that we have the following conclusion: (traversal order = preorder, inorder or postorder)

            1. If your serialization result doesn't contain null pointer information, and you only give a traversal order, then you can't restore a unique binary tree.

            2. If your serialization result does not contain null pointer information, and you will give two traversal orders, then follow the previous article
                The Binary Tree Heart Method (Structure) is divided into two situations:
                2.1. If you give a pre-order and a middle order, or a post-order and a mid-order, then you can restore the only binary tree.
                2.2. If you give the pre-order and the post-order, then you will not be able to restore the only binary tree.

            3. If your serialization result contains null pointer information, and you only give one traversal order, there are two cases:
                3.1. If you give a pre-order or a post-order, then you can restore the only binary tree.
                3.2. If you give the middle order, then you cannot restore the only binary tree.

        time O(N)
        space O(N)
    **/

    char s_SEP = ',';       // seperator
    string s_NULL = "#";    // null indicator

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        serializeTraverse(root, s);
        return s;
    }

    //// preorder traverse root and serialize the tree
    void serializeTraverse(TreeNode* root, string& s) {
        // null
        if(root == nullptr)
        {
            s += s_NULL + s_SEP;
            return;
        }
        //// preorder
        s += to_string(root->val) + s_SEP;

        //// traverse
        serializeTraverse(root->left, s);
        serializeTraverse(root->right, s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //// construct queue
        queue<string> q;
        string s = "";
        for(auto& c : data)
        {
            // curr char is a seperator, we find a new val in s, push it the the val queue and reset s
            if(c == s_SEP)
            {
                q.push(s);
                s = "";
            }
            // curr char is not a seperator, so we add it to s
            else
                s += c;
        }
        //// construct tree
        return deserializeTraverse(q);
    }

    //// traverse serialized string q and construct the tree in preorder
    TreeNode* deserializeTraverse(queue<string>& q) {
        //// bc
        if(q.empty())
            return nullptr;
        
        //// preorder, construct root
        string s = q.front();
        q.pop();
        // null
        if(s == s_NULL)
            return nullptr;
        TreeNode* root = new TreeNode(stoi(s));

        //// traverse to construct the subTree
        root->left = deserializeTraverse(q);
        root->right = deserializeTraverse(q);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));