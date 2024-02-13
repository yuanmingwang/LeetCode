class Solution {
public:
    /** 
        dp, iteration, btm up
        
        def: 
            dp[i] = answer of fib(i)
        stf:
            1. dp[i] = dp[i - 1] + dp[i - 2]
        bc:
            if(n == 0), return 0. if(n == 1), return 1
            dp[0] = 0
            dp[1] = 1

        time: O(n)
        space: O(1)
    */
    int fib(int n) {
        if(n <= 1)
            return n;
        //// init dp & bc
        int dp_i_1 = 1, dp_i_2 = 0;
        //// dp
        for(int i = 2; i <= n; ++i)
        {
            int temp = dp_i_1;
            //// stf 1.
            dp_i_1 += dp_i_2;
            // update dp_i_2 to previous dp_i_1
            dp_i_2 = temp;
        }
        return dp_i_1;
    }
};