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
        Recursion

        Intuition: 
            Make full use of the BST's characteristic of 'left small and right large'. 
            There is no need to search both sides recursively; 
            by comparing the target with root->val, you can eliminate one side, similar to the concept of binary search.

        time O(N)
        space O(logN)
    **/

    TreeNode* searchBST(TreeNode* root, int val) {
        //// bc
        if(root == nullptr) 
            return nullptr;
        
        //// smaller, search left tree
        if(val < root->val) 
            return searchBST(root->left, val);

        //// larger, search right tree
        if(val > root->val) 
            return searchBST(root->right, val);

        //// equal, return root
        return root;
    }
};

/** 2.---------------------------------------------------------------------------------------------------------------------------------------- **/
class Solution {
public:
    /** 
        Binary Search Tree
        Iteration

        Intuition: 
            same as above

        time O(N)
        space O(1)
    **/
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root and root->val != val)
            root = root->val > val ? root->left : root->right;
            
        return root;
    }
};