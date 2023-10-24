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
        Breadth-First Search, Binary Tree

        Time O(N). In the worst case for a balanced tree, we need to visit all nodes level by level up to the tree height, that excludes the bottom level only. This way we visit N/2 nodes, and thus the time complexity is O(N)
        Space O(N).
    */
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);

        int depth = 0;  // 0 because the below while loop starts from level 0
        while(!q.empty())
        {
            ++depth;    // new level, add 1 to the depth
            int size = q.size();    // size of the current level
            //// Spread all nodes in the current queue
            for(int i = 0; i < size; ++i)
            {
                TreeNode* cur = q.front();
                q.pop();
                //// Determine if you've reached the end (a leaf node)
                if(!cur->left && !cur->right)
                    return depth;
                //// Add neighboring nodes of cur to the queue
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
        }
        return depth;
    }

    // /** 
    //     Depth-First Search, Binary Tree

    //     Time: O(N). Because each node is visited exactly once.
    //     Space: O(H), where H is the height of the tree, it's the cost for depth of recursion stack memory.
    // */
    // //// recursion, DFS
    // int minDepth(TreeNode* root) {
    //     if(!root)
    //         return 0;
        
    //     int left = minDepth(root->left);
    //     int right = minDepth(root->right);
        
    //     //// find min depth
    //     if(left == 0 or right == 0) // if one of the child is 0, it might not be the leaf node. we need to use the larger value here and plus 1 
    //         return left + right + 1;
    //     return min(left, right) + 1;
    // }
};