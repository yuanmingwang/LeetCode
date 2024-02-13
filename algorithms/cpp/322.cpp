class Solution {
public:
    /** 
        dp, iteration, btm up
        
        def: 
            dp[i] = When the target amount is i, at least dp[i] coins are needed to round up to amount i.
        stf:
            1. dp[i] = 0 if i = 0
            2. dp[i] = - 1 if i < 0
            3. dp[i] = min(dp[i - coin] + 1 | for coin in coins) if i > 0
        bc:
            dp[0] = 0

        time: O(coins.size() * amount)
        space: O(n)
    */
    int coinChange(vector<int>& coins, int amount) {
        //// init dp
        // coin >= 1 so the max number of coins needed to reach amount is amount
        // Why not INT_MAX? Because we have dp[i - coin] + 1 later, which would cause an integer overflow.
        vector<int> dp(amount + 1, amount + 1);
        //// bc
        dp[0] = 0;
        //// dp
        for(int i = 1; i < dp.size(); ++i)
        {
            // iterate over all selections
            for(auto &coin : coins)
            {
                //// stf 2. , no solution
                if(i - coin < 0)
                    continue;
                //// stf 3.
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        // if dp[amount] has the default value, we have no solution, return -1
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};