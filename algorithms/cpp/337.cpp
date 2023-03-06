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
        dp, recursion
        
        def: 
            rob(root) = return the max # of money we can get starting from root
        stf:
            1. we robbed at cur node, so we can not rob the left & right nodes
            2. we didn't rob at day cur node, so we can rob the left & right nodes
        bc:
            return 0 if we can't rob

        time O(n)
        space O(n)
    */

    unordered_map<TreeNode*, int> umap;
    int rob(TreeNode* root) {
        //// bc
        if(!root)
            return 0;
        //// subproblem already calculated, return the result directly
        if(umap.find(root) != umap.end())
            return umap[root];
        
        //// 1. rob
        int doRobLeft = !root->left ? 0 : rob(root->left->left) + rob(root->left->right);
        int doRobRight = !root->right ? 0 : rob(root->right->left) + rob(root->right->right);
        int doRob = root->val + doRobLeft + doRobRight;

        //// 2. don't rob
        int dontRob = rob(root->left) + rob(root->right);

        //// update umap
        int res = max(doRob, dontRob);
        umap[root] = res;
        
        return res;
    }
};