class Solution {
public:
    /** 
        70. Climbing Stairs
        dp, iteration, btm up, Tabulation

        Intuition:
            This question is similar to 509. Fibonacci numbers: 
            The # of ways to climb to the nth step = # of ways to n-1 + # of ways to n-2
            
        Algorithm:
            def: 
                dp[i] = The number of ways to climb to the ith step.
                dp[i] = # of distinct ways we can climb to step i
            stf:
                1. dp[i] = dp[i - 2] + dp[i - 1]
            bc:
                if(n == 0), return 0. if(n == 1), return 1.
                dp[0] = 0
                dp[1] = 1

        time O(n)
        space O(n)
    */
    int climbStairs(int n) {
        //// bc
        if (n <= 1)
            return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        //// dp
        for(int i = 2; i <= n; ++i)
        {
            dp[i] = dp[i - 2] + dp[i - 1];
        }

        return dp[n];
    }


    // 2. -------------------------------------------------------------------------------------------------------------- 
    /** 
        70. Climbing Stairs
        dp, iteration, btm up, Tabulation with Space Optimization

        Intuition:
            This question is similar to 509. Fibonacci numbers: 
            The # of ways to climb to the nth step = # of ways to n-1 + # of ways to n-2
            
        Algorithm:
            def: 
                dp[i] = The number of ways to climb to the ith step.
                dp[i] = # of distinct ways we can climb to step i
            stf:
                1. dp[i] = dp[i - 2] + dp[i - 1]
            bc:
                dp[i - 2], base case n = 1, res = 1
                dp[i - 1], base case n = 2, res = 2

        time O(n)
        space O(1)
    */
    int climbStairs(int n) {
        //// bc
        if (n <= 1)
            return 1;
        int dp_2 = 1;   // dp[i - 2], base case n = 1, res = 1
        int dp_1 = 2;   // dp[i - 1], base case n = 2, res = 2
        //// dp
        for(int i = 2; i < n; ++i)
        {
            int cur = dp_2 + dp_1;
            //// update dp_2, dp_1
            dp_2 = dp_1;
            dp_1 = cur;
        }

        return dp_1;
    }
};