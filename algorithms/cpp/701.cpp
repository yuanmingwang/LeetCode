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
        recursion, divide and conquer

        Intuition: 
            The operation of a data structure is nothing more than traversal access, traversal is "finding", 
            and access is "changing". To insert a number, we need to find the insertion position first, and then insert it.

            In 700. Search in a Binary Search Tree, we summarized the traversal framework in BST, which is the problem of "finding". 
            When it comes to "changing", it's similar to the problem of constructing a binary tree, 
            where the function returns the TreeNode type and receives the return value of the recursive call.
            
            Note that BST generally does not have nodes with duplicate values
        
        time O(N)
        space O(logN)
    **/
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //// bc. this menas that we find an empty space to insert the new val
        if(root == nullptr)
            return new TreeNode(val);
        
        //// root is smaller, find a spot in the right subTree
        if(root->val < val)
            root->right = insertIntoBST(root->right, val);
        //// root is larger, find a spot in the left subTree
        else if(root->val > val)
            root->left = insertIntoBST(root->left, val);

        //// the upper recursion receives the return new TreeNode as a child node, so just return the original root
        return root;
    }
};

/** 2.---------------------------------------------------------------------------------------------------------------------------------------- **/
class Solution {
public:
    /** 
        Binary Search Tree
        iteration

        Intuition: 
            Iterative version of the above code
        
        time O(N)
        space O(logN)
    **/
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //// bc. this menas that we find an empty space to insert the new val
        if(root == nullptr)
            return new TreeNode(val);

        //// find an empty spot
        TreeNode* prev;
        TreeNode* node = root;
        while(node)
        {
            prev = node;
            // if root is smaller, find a spot in the right subTree
            // if root is larger, find a spot in the left subTree
            node = node->val < val ? node = node->right : node = node->left;
        }

        //// Insert the new node
        // here, we find an empty space to insert the new val. node should be a child to prev
        // therefore, we use prev->val to determine where to insert as above
        if(prev->val < val)
            prev->right = new TreeNode(val);
        else
            prev->left = new TreeNode(val);
        
        return root;
    }
};