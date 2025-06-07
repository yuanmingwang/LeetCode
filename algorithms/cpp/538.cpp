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
        Binary Search Tree
        Traverse
        Same as: 1038. Binary Search Tree to Greater Sum Tree

        Intuition: 
            Since this is a BST, we can do a reverse inorder traversal to traverse the nodes of the tree in descending order. 
            In the process, we keep track of the running sum of all nodes which we have traversed thus far.

        time O(N)
        space O(1)
    **/

    // sum of all nodes which we have traversed thus far
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        traverse(root);
        return root;
    }

    void traverse(TreeNode* root) {
        //// bc
        if(root == nullptr)
            return;
        
        //// reverse inorder traversal
        traverse(root->right);

        //// inorder, calculate sum and assign it to current node to convert the BST to Greater Tree
        sum += root->val;
        root->val = sum;

        traverse(root->left);
    }
};