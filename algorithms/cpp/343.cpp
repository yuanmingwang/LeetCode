class Solution {
public:
    /** 
        dp, iteration, btm up
        
        def: 
            dp[i] = max product of intergers after breaking from 0 to i
        stf:
            1. dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j])) for j in range[1, i / 2]
               we break i into positive integer j and i - j
        bc:
            dp[0] = 0
            dp[1] = 1

        time O(n)
        space O(n)
    */
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        
        for(int i = 2; i <= n; ++i)
        {
            for(int j = 1; j <= i / 2; ++j)
            {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }

        // for(auto& i : dp)
        //     cout<<i<<" ";

        return dp[n];
    }
};