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
            Divide and conquer solution
    
            1. Can this problem be solved with a "traversal"?
            A: flatten function, which returns void. This means the problem expects us to flatten the binary tree into a linked list in place.
                With this requirement, we cannot solve the problem through simple binary tree traversal.
            
            2. Can this problem be solved using the "divide and conquer" ?
            A: Yes. Let's define the flatten function:
                Definition: Input node root, then the binary tree rooted at root will be flattened into a linked list
            
            For a node x, you can follow these steps:
            1. Use flatten(x.left) and flatten(x.right) to flatten the left and right subtrees of x.
            2. Attach the right subtree of x below the left subtree, and then make the entire left subtree the right subtree.
            3. In this way, the entire binary tree rooted at x is flattened, effectively fulfilling the definition of flatten(x).
            
            
            time O(n)
            space O(n)
        **/
        void flatten(TreeNode* root) {
            //// bc
            if(root == nullptr)
                return;
            
            //// Use the definition to flatten the left and right subtrees
            flatten(root->left);
            flatten(root->right);
            
            //// post-order
    
            // 1. Left and right subtrees have been flattened into linked lists
            TreeNode* left = root->left;
            TreeNode* right = root->right;
    
            // 2. Make the left subtree the new right subtree
            root->left = nullptr;
            root->right = left;
    
            // 3. Attach the original right subtree to the end of the current right subtree
            TreeNode* p = root; // assign p to root because left and right could be nullptr
            while(p->right != nullptr)
                p = p->right;
            p->right = right;
        }
    };