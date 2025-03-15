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


/** 
    Binary Tree
    Binary tree reccursion

    time O(N)
    space O(N)
**/
class Solution {
public:

    int maxDepth(TreeNode* root) {
        int res = 0;
        int depth = 0;
        
        traverse(root, res, depth);
        return res;
    }

    void traverse(TreeNode* root, int &res, int &depth)
    {
        if(!root)
            return;

        // preorder
        ++depth;
        res = max(res, depth);
        traverse(root->left, res, depth);
        // inorder
        traverse(root->right, res, depth);
        // postorder
        --depth;
    }
};

/** ---------------------------------------------------------------------------------------------------------------------------------------- **/

/** 
    Binary Tree

    Divide and conquer
    The maximum depth of a binary tree can be derived from the maximum depth of a subtree

    time O(N)
    space O(N)
**/
class Solution {
public:

    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        //// find the depth of the subtree
        int leftMax = maxDepth(root->left) + 1;
        int rightMax = maxDepth(root->right) + 1;

        return max(leftMax, rightMax);
    }
};