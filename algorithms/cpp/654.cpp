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
    
            Intution:
                The maximum value in the current nums is the root node. 
                Then, recursively call the left and right arrays based on the index to construct the left and right subtrees.
            
            time O(n^2)
            space O(n)
        **/
        TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
            return construct(nums, 0, nums.size() - 1);
        }
    
        // Definition: 
        //         construct the maximum binary tree from nums[left..right]
        //     Return: 
        //         the root node of the maximum binary tree (root is the largest number in range nums[left..right])
        TreeNode* construct(vector<int> &nums, int left, int right) {
            //// bc
            if(left > right)
                return nullptr;
            
            //// find the maximum value in the array and its corresponding index
            int max_val = -1;
            int max_val_index = -1;
            for(int i = left; i <= right; ++i)
            {
                if(nums[i] > max_val)
                {
                    max_val = nums[i];
                    max_val_index = i;
                }
            }
    
            //// construct the root node first
            TreeNode* root = new TreeNode(max_val);
            //// recursively construct the left and right subtrees
            root->left = construct(nums, left, max_val_index - 1);
            root->right = construct(nums, max_val_index + 1, right);
    
            return root;
        }
    };