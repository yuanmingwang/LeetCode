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
    /** 
        Binary Tree
        Divide and conquer

        Intuition: 
            the structure of inorder array: left | root | right
            the structure of postorder array: left | right | root

        time O(N)
        space O(N)
    **/

    // since they have unique values, we can use a map to find the index in O(1)
    // k = inorder array value, v = inorder array index
    unordered_map<int, int> umap;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        //// build umap
        for(int i = 0; i < size; ++i)
            umap[inorder[i]] = i;
        
        return build(inorder, 0, size - 1,
                    postorder, 0, size - 1);
    }

    //// param: given arrays preorder[pre_left, pre_right] and inorder[in_left, in_right]
    //// return: build the tree and return the root
    TreeNode* build(vector<int>& inorder, int in_left, int in_right,
                    vector<int>& postorder, int post_left, int post_right) {
        
        //// bc
        if(in_left > in_right)
            return nullptr;
        
        //// find root value index in the inorder array
        int root_val = postorder[post_right];
        int root_val_inorder_index = umap[root_val];
        int left_size = root_val_inorder_index - in_left;

        //// build tree
        TreeNode* root = new TreeNode(root_val);
        root->left = build(inorder, in_left, root_val_inorder_index - 1,
                            postorder, post_left, post_left + left_size - 1);
        root->right = build(inorder, root_val_inorder_index + 1, in_right,
                            postorder, post_left + left_size, post_right - 1);
        
        return root;
    }
};