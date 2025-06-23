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
    /** 450. Delete Node in a BST
        Binary Search Tree
        Binary search, recursion

        Intuition:
            1. find the target node a using binary search
            2. remove the node while maintaining the BST. There are 3 cases:
                Case 1: A happens to be the end node, and both child nodes are empty, then it can be removed directly.
                Case 2: A has only one non-empty child node, so it wants the child to take its place.
                Case 3: A has two child nodes, in order not to maintain the BST, 
                        A must find the largest node in the left subtree, or the smallest node in the right subtree, to take over it.
                        In this case, we use the smallest node in the right subtree

        time O(N)
        space O(logN)
    **/

    //// Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
    //// Return the root node reference (possibly updated) of the BST.
    TreeNode* deleteNode(TreeNode* root, int key) {
        //// bc
        if(root == nullptr)
            return nullptr;
        
        if(root->val == key)
        {
            //// Case 1 & Case 2
            if(root->left == nullptr) return root->right;
            if(root->right == nullptr) return root->left;

            //// Case 3
            // find the smallest node in the right subtree
            TreeNode* node_min = getMinNode(root->right);
            // delete the minNode from the right subTree
            root->right = deleteNode(root->right, node_min->val);
            // replace root with minNode
            node_min->left = root->left;
            node_min->right = root->right;
            root = node_min;
        }
        // root is larger, search in the left subTree
        else if(root->val > key)
            root->left = deleteNode(root->left, key);
        // root is smaller, search in the right subTree
        else if(root->val < key)
            root->right = deleteNode(root->right, key);

        return root;
    }

    //// return the node with the minimum val
    TreeNode* getMinNode(TreeNode* root) {
        // left most node is the smallest node in a BST
        while(root and root->left)
            root = root->left;
        return root;
    }

};