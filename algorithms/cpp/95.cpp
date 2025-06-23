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
    /** 95. Unique Binary Search Trees II
        BST
        divide and conquer
        This problem is a variant of the problem of 96. Unique Binary Search Trees

        Intuition:
            We will use a recursive helper function build(left, right) that receives a range (left to right, within n) 
            and returns all BST's rooted in that range.
            
            As there will be trees with root as 1, 2, 3...n. 
            Iterate through all values from left to right to construct tree rooted at i and construct its left and right subtree recursively.

            We know that in Binary Search Tree all nodes in left subtree are smaller than root and in right subtree are larger than root. 
            So for left = 1 and right = n, if we have ith number as root, all numbers from 1 to i-1 will be in left subtree and i+1 to n will be in right subtree.
            Therefore, we will build the tree recursively for left and right subtrees rooted at i as leftSubTree = build(left, i-1) and rightSubtree = build(i + 1, right)

            So, till what moment we will recursively find the left and right subtrees?? Answer is until start < end!!
            So when start > end, add NULL to the list and return
            This will be our base case!

            Now, we have leftSubtree and rightSubtree for node with root i. The last thing we need to do is connect leftSubTree and rightSubTree with root and add this tree(rooted at i) to the ans list!
            Here, we can have multiple left and right subtrees. So we need to loop through all left and right subtrees and connect every left subTree to right subTree and to current root(i) one by one.

        time O(N^2)
        space O(N)
    **/

    vector<TreeNode*> generateTrees(int n) {
        // the val of node starts from 1
        return build(1, n);
    }

    //// build and return the tree that has node with range [left, right]
    vector<TreeNode*> build(int left, int right) {
        vector<TreeNode*> res;
        //// bc
        if(left > right)
        {
            res.push_back(nullptr);
            
        }

        //// iterate over the node that can be selected as a root in range [left, right]
        for(int i = left; i <= right; ++i)
        {
            //// gererate valid left & right subTree
            // i is the root, so leftTree = [left, i-1], rightTree = [i+1, right]
            vector<TreeNode*> leftTree = build(left, i - 1);
            vector<TreeNode*> rightTree = build(i + 1, right);
            //// iterate over all possible combination of left & right subTree and insert it into res
            //// we construct the new tree with root i for each different subTree, and add them into the res
            for(auto &l : leftTree)
            {
                for(auto &r : rightTree)
                {
                    res.push_back(new TreeNode(i, l ,r));
                }
            }
        }
        return res;
    }
};