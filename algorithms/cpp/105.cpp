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
            the structure of preorder array: root | left | right
            the structure of inorder array: left | root | right

        time O(N)
        space O(N)
    **/

    // since they have unique values, we can use a map to find the index in O(1)
    // k = inorder array value, v = inorder array index
    unordered_map<int, int> umap;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = inorder.size();
        //// build umap
        for(int i = 0; i < size; ++i)
            umap[inorder[i]] = i;
        
        return build(preorder, 0, size - 1,
                    inorder, 0, size - 1);
    }

    //// param: given arrays preorder[pre_left, pre_right] and inorder[in_left, in_right]
    //// return: build the tree and return the root
    TreeNode* build(vector<int>& preorder, int pre_left, int pre_right,
                    vector<int>& inorder, int in_left, int in_right) {
        //// bc
        if(pre_left > pre_right)
            return nullptr;
        
        //// find root value index in the inorder array
        int root_val = preorder[pre_left]; // the first element in the preorder array is the root
        int root_val_inorder_index = umap[root_val];
        int left_size = root_val_inorder_index - in_left;
        
        //// build tree
        TreeNode* root = new TreeNode(root_val);
        root->left = build(preorder, pre_left + 1, pre_left + left_size,
                            inorder, in_left, root_val_inorder_index - 1);
        root->right = build(preorder, pre_left + left_size + 1, pre_right,
                            inorder, root_val_inorder_index + 1, in_right);
        
        return root;
    }
};