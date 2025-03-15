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
    
        //// stores the pre-order traverse result
        vector<int> res;
    
        vector<int> preorderTraversal(TreeNode* root) {
            traverse(root);
            return res;
        }
    
        void traverse(TreeNode* root){
            if(root == nullptr)
                return;
            
            // pre-order
            res.push_back(root->val);
    
            traverse(root->left);
            // in-order
            traverse(root->right);
            // post-order
        }
    };