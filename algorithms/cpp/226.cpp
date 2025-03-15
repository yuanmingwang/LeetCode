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
            Traverse solution
            
            time O(n)
            space O(n)
        **/
        TreeNode* invertTree(TreeNode* root) {
            traverse(root);
            return root;
        }
    
        void traverse(TreeNode* root) {
            if(root == nullptr)
                return;
            
            //// swap left and right node. This can be done in pre-order, in-order, or post-order position.
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
    
            traverse(root->left);
            traverse(root->right);
        }

        /** 2.---------------------------------------------------------------------------------------------------------------------------------------- **/
        /** 
            Binary Tree
            Divide and conquer solution

            definition: invert the binary tree with root.
            return: the root node of the inverted binary tree
            
            time O(n)
            space O(n)
        **/
        TreeNode* invertTree(TreeNode* root) {
            if(root == nullptr)
                return root;
            
            //// Using the function definition to invert the left and right subtrees first
            TreeNode* left = invertTree(root->left);
            TreeNode* right = invertTree(root->right);

            //// swap the left and right child nodes. have to do this in post-order because we need to invert the children first
            root->left = right;
            root->right = left;
            
            return root;
        }
    };