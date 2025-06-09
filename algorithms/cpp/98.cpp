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

        Intuition: 
            If we use in-order traversal to serialize a binary search tree, 
            we can get a list of values in ascending order. 
            It can be proved with the definition of BST. 
            And here I use the reference of TreeNode pointer prev as a global variable to mark the address of previous node in the list.

        time O(N)
        space O(1)
    **/

    TreeNode* prev = nullptr;
    bool isValidBST(TreeNode* root) {
        return traverse(root);
    }

    bool traverse(TreeNode* root) {
        //// bc
        if(root == nullptr) return true;
        
        if(!traverse(root->left)) return false;

        //// inorder, check value
        if(prev and prev->val >= root->val) return false;

        //// update prev before going to the next node
        prev = root;
        return traverse(root->right);
    }
};

/** 2.---------------------------------------------------------------------------------------------------------------------------------------- **/
class Solution {
public:
    /** 
        Binary Search Tree
        Divide and conquer

        Intuition: 
            Check range of each node.
            When we go left, update maxinum value only. A minimum number will be the same number from parent.
            On the other hand, when we go right, update minimum number only. A maxinum number will be the same number from parent.
            At each node, we check the range and if we reach null, that path is valid binary serach tree.

        time O(N)
        space O(1)
    **/
    
    bool isValidBST(TreeNode* root) {
        return check(root, NULL, NULL);
    }
    
    //// all left child should be smaller than root->val and all right child should be larger than root->val
    //// max > root->val > min
    bool check(TreeNode* root, TreeNode* min, TreeNode* max) // can't use int directly. because we are passing NULL as the initial value
    {
        //// base case
        if(!root) return true;
        
        //// check min & max.
        if(min != NULL and root->val <= min->val) return false;
        if(max != NULL and root->val >= max->val) return false;
        
        // check and set left child max value to root->val and right child min value to root->val
        return check(root->left, min, root) and check(root->right, root, max);
    }
};