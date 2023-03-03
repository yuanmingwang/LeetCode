class Solution {
public:
    /** 
        dp, iteration
        
        def: 
            dp[i] = least number of perfect square numbers that sum to i
        stf:
            we try to construct the number using n-1*1, then n-2*2, n-3*3 ... and update dp[i] in this process
            1. dp[i] = min(dp[i], dp[i - j * j] + 1)
        bc:
            dp[0] = 0

        time O(n * sqrt(n))
        space O(n)
    */
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        //// bc
        dp[0] = 0;
        //// dp
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j * j <= i; ++j) // 0 <= i - j * j, so j * j <= i
            {
                //// we are using j * j as a number to add up to dp[i], which means we need 1 extra number from dp[i - j * j]
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
