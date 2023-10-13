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
*/
class Solution {
public:
    //// recursion
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(root, res);
        return res;
    }

    void traverse(TreeNode* root, vector<int> &list)
    {
        if(!root)
            return;
        
        traverse(root->left, list);
        list.push_back(root->val);
        traverse(root->right, list);
    }
};