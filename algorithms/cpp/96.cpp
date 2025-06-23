class Solution {
public:
    /** 96. Unique Binary Search Trees
        Binary Search Tree, Dynamic Programming
        dp iteration, buttom up

        Intuition:
            For a BST with i nodes in total, we select a random root. 
            If we have (j) nodes on the left side of the root, we must have (i-j-1) nodes on the right side

            Therefore, we have total dp(j) * dp(i-j-1) unique BST
            where dp(i) = the number of unique BST can be created with i nodes

        Algorithm:
            def: dp[i] = the number of unique BST trees can be created from 1...i;
            stf: dp(i) = sumation{dp(j) * dp(i-j-1)} for j = [0, i] 
                where i = total number of current root, j = the index of the root = the number of node on the left side of the root

        time O(N^2)
        space O(N)
    **/

    int numTrees(int n) {
        //// init dp table
        // size = n+1 because the range of i is [0, n]
        // k = i, v = the number of unique BST can be created with i nodes
        vector<int> dp(n + 1, 0);

        //// bc
        // only 1 BST can be created with 0 or 1 node
        dp[0] = dp[1] = 1;

        //// construct dp table
        for(int i = 2; i < dp.size(); ++i)
        {
            //// iterate over the node that can be selected as a root.
            for(int j = 0; j < i; ++j)
            {
                //// stf
                // += because we are find the sumation here
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }

        return dp[n];
    }
};