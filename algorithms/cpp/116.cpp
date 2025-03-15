/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    public:
        /** 
            Binary Tree
            Traverse solution
    
            We can abstract the binary tree into a ternary tree, where each node on the ternary tree represents two adjacent nodes of the original binary tree.
            In example 1, we have 45, 56, 67 as a ternary tree, 23 as left and right.
            Now, we just need to implement a traverse function to traverse this ternary tree. 
            The task for each "ternary tree node" is to connect its two internal binary tree nodes. (node 2,3 in example 1)
            
            time O(n)
            space O(n)
        **/
        Node* connect(Node* root) {
            if(root == nullptr)
                return nullptr;
            
            // traverse the "ternary tree" and connect adjacent nodes
            traverse(root->left, root->right);
            return root;
        }
    
        //// connect left and right, than traverse the ternary tree formed by left and right
        void traverse(Node* left, Node* right)
        {
            //// bc. because it is a perfect binary tree, so one of the node = null means parent is a leaf node
            if(left == nullptr or right == nullptr)
                return;
            
            //// pre-order. Connect two input nodes
            left->next = right;
    
            // Connect two child nodes with the same parent. node 45, 67 in example 1
            traverse(left->left, left->right);
            traverse(right->left, right->right);
            // Connect two child nodes across different parents. node 56 in example 1
            traverse(left->right, right->left);
        }
    };