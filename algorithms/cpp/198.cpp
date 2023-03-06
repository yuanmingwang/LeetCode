class Solution {
public:
    /** 
        dp, iteration, btm up
        
        def: 
            dp[i] = max # of money we can get at day i
        stf:
            1. we robbed at day i - 1, so we can't rob at day i
                dp[i] = dp[i - 1]
            2. we didn't rob at day i - 1, so we can rob at day i
                dp[i] = dp[i - 2] + nums[i]
        bc:
            in day 0 and day 1, we can only buy one of them, so in day 1, our max must be max(nums[0], nums[1])
            dp[0] = nums[0]
            dp[1] = max(nums[0], nums[1])

        time O(n)
        space O(1) if we store only dp[i - 1] and dp[i - 2]
    */
    int rob(vector<int>& nums) {
        //// o(1) space
        int size = nums.size();
        //// bc
        if(size < 2)
            return nums[0];
        int dp_i_2 = nums[0];
        int dp_i_1 = max(nums[0], nums[1]);
        //// dp
        for(int i = 2; i < size; ++i)
        {
            int temp = dp_i_1;
            dp_i_1 = max(dp_i_1, dp_i_2 + nums[i]);
            dp_i_2 = temp;
        }
        return dp_i_1;

        // //// o(n) space
        // int size = nums.size();
        // if(size < 2)
        //     return nums[0];
        // vector<int> dp(size);
        // //// bc
        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);
        // //// dp
        // for(int i = 2; i < size; ++i)
        // {
        //     dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        // }
        // return dp[size - 1];
    }
};