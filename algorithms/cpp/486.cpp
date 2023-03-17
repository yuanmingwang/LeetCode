class Solution {
public:
    /** 
        dp, iteration, btm up
        
        def: 
            dp[i][j][0] = the max score you can get with nums[i .. j] if you pick first
            dp[i][j][1] = the max score you can get with nums[i .. j] if you pick second

            ex: for nums = [1, 5, 2]
                dp[0][1][0] = 5 because if you pick first from [1, 5], the max score you can get is 5
                dp[1][2][2] = 2 because if you pick second from [5, 2], the max score you can get is 2
        stf:
            1.  dp[i][j][0] = max(nums[i] + dp[i + 1][j][1], nums[j] + dp[i][j - 1][1])
                            = max(choose the left most num, choose the right most num)

                if you choose the left, your oppenent will have nums[i + 1 .. j] and you are the second to pick
                if you choose the right, your oppenent will have nums[i .. j - 1] and you are the second to pick

            2.  dp[i][j][1]
                if your oppenent pick the left
                    dp[i][j][1] = dp[i + 1, j][0]
                if your oppenent pick the right
                    dp[i][j][1] = dp[i, j - 1][0]
                
                if your oppenent pick the left, you will have nums[i + 1 .. j] and now you are the first to pick
                if your oppenent pick the left, you will have nums[i .. j - 1] and now you are the first to pick
        bc:
            for 0 <= i == j <= nums.size()
            dp[i][j][0] = dp[i][i][0] = nums[i]
            dp[i][j][1] = dp[i][i][1] = 0

            because there is only 1 num we can choose if i == j, so the first pick get nums[i] and the scond pick get nothing
        res:
            we want to find the scores difference between two players using nums[0 .. nums.size() - 1]
            scores difference = dp[0][size - 1][0] - dp[0][size - 1][1]

        time O(n^2)
        space O(n) if you use 1d array
    */

    //// space O(n)
    bool PredictTheWinner(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> dp(size, vector<int>(2, 0));
        //// dp
        for(int i = size - 1; i >= 0; --i)
        {
            //// bc
            dp[i][0] = nums[i];
            for(int j = i + 1; j < size; ++j)
            {
                int left = nums[i] + dp[j][1];
                int right = nums[j] + dp[j - 1][1];
                //// pick left
                if(left > right)
                {
                    dp[j][1] = dp[j][0];
                    dp[j][0] = left;
                }
                //// pick right
                else
                {
                    dp[j][0] = right;
                    dp[j][1] = dp[j - 1][0];
                }
            }
        }
        return dp[size - 1][0] - dp[size - 1][1] >= 0;
    }

    //// space O(n^2)
    bool PredictTheWinner(vector<int>& nums) {
        int size = nums.size();
        vector<vector<vector<int>>> dp(size, vector<vector<int>>(size, vector<int>(2, 0)));
        //// bc
        for(int i = 0; i < size; ++i)
            dp[i][i][0] = nums[i];
        //// dp
        // we need dp[i + 1][j] and dp[i][j - 1] to find dp[i][j], so we need to iterate from btm to top, left to right
        // start from i = size - 1 because dp[size - 1][size - 1] is a bc
        for(int i = size - 2; i >= 0; --i)  
        {
            // start from j = i + 1 because dp[i][i] is a bc, so we start from dp[i][i + 1]
            for(int j = i + 1; j < size; ++j)
            {
                int left = nums[i] + dp[i + 1][j][1];
                int right = nums[j] + dp[i][j - 1][1];
                //// pick left
                if(left > right)
                {
                    dp[i][j][0] = left;
                    dp[i][j][1] = dp[i + 1][j][0];
                }
                //// pick right
                else
                {
                    dp[i][j][0] = right;
                    dp[i][j][1] = dp[i][j - 1][0];
                }
            }
        }

        return dp[0][size - 1][0] - dp[0][size - 1][1] >= 0;
    }
};