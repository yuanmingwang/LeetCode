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
    /** 230.Kth Smallest Element in a BST
        Binary Search Tree
        Traverse

        Intuition: 
            inorder traverse of a BST gives it's value in an accending order.

        time O(N)
        space O(1)
    **/
    
    int res;
    int kthSmallest(TreeNode* root, int k) {
        traverse(root, k);
        return res;
    }

    void traverse(TreeNode* root, int& k) {
        //// bc
        if(root == nullptr)
            return;
        
        traverse(root->left, k);
        //// inorder, check if we reach the kth smallest node
        if(--k == 0)
        {
            res = root->val;
            return;
        }
        traverse(root->right, k);
    }
};