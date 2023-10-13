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

    Divide and conquer
    The length of the 'diameter' of each binary tree is the sum of the maximum depths of the left and right subtrees of a node

    Now let me find the longest "diameter" in the whole tree, then the straightforward idea is to traverse the whole tree in each node, 
    and then through the maximum depth of the left and right subtree of each node to calculate the "diameter" of each node, 
    and finally all the "diameter" to find the maximum value can be.

    time O(N)
    space O(N)
*/
class Solution {
public:

    int res;

    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;

        traverse(root);

        return res;    
    }

    // Find the max depth of the root using divide and conquer
    int traverse(TreeNode* root)
    {
        if(!root)
            return 0;
        
        //// we don't need to plus 1 here because we are not calculating the depth
        int leftMax = traverse(root->left);
        int rightMax = traverse(root->right);
        
        // postorder, update res
        res = max(res, leftMax + rightMax);

        //// plus 1 for the length of the path of the current node to its parent node (diameter)
        return max(leftMax, rightMax) + 1;
    }
};