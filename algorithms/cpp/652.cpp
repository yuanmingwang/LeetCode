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
    /** 652.Find Duplicate Subtrees
        Binary Tree
        Traverse

        Intuition: 
            We perform postorder traversal, serializing and hashing the serials of subtrees in the process. 
            We can recognize a duplicate subtree by its serialization.

        time O(N)
        space O(N)
    **/

    string s_NULL = "#";    // null indicator
    unordered_map<string, int> umap;    // k = subTree serialized string. v = number of time that subTree k occurs
    vector<TreeNode*> res;

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        return res;
    }

    //// postorder traverse to find duplicate subTree. 
    //// return the serialized string of the subtree
    string traverse(TreeNode* root) {
        //// bc
        if(root == nullptr)
            return s_NULL;
        
        //// preorder
        string s_left = traverse(root->left);
        string s_right = traverse(root->right);

        //// postorder
        //// construct curr tree string
        string s_subtree = format("{},{},{}", to_string(root->val), s_left, s_right);

        //// compare it with the string in umap
        if(umap[s_subtree] == 1)    // find a duplicate, insert root into res
            res.push_back(root);
        ++umap[s_subtree];  // update count

        return s_subtree;
    }
};