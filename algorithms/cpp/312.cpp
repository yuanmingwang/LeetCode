class Solution {
public:
    /** 
        dp, iteration, btm up
        we want to use dp here, so we have to make the subproblem independent. However, the adjacent left and right ballons have effect on the final result
        Hence, we need to select the last ballons to brust in order to make the subproblem independent.
        For problem dp[i][j], if we choose to brust k lastly, we can seperate the problem dp[i][j] in to subproblems dp[i][k - 1] and dp[k + 1][j]

        Important point to be noted here is that the balloons in the range (i, k - 1) and (k + 1, j) will be burst BEFORE kth balloon. 
        So, when we burst the kth balloon, the profit will be nums[i - 1] * nums[k] * nums[j + 1] PROVIDED that index i - 1 and j + 1 are valid
        
        def: 
            dp[i][j] = max # of coins we can get if we burst the balloon between nums[i] and nums[j]
        stf:
            1. dp[i][j] = dp[i][k - 1] + nums[i - 1] * nums[k] * nums[j + 1] + dp[k + 1][j]
                        = result of left + last ballon + result of right
        bc:
            dp[i][j] = 0
        res:
            dp[1][size]
        time O(n^3)
        space O(n^2)
    */
    int maxCoins(vector<int>& nums1) {
        int size = nums1.size();
        //// insert dummy node on both ends
        vector<vector<int>> dp(size + 2, vector<int>(size + 2, 0));
        //// insert dummy node 1 on both ends
        vector<int> nums(size + 2);
        for(int i = 0; i < size; ++i)
            nums[i + 1] = nums1[i];
        nums[0] = nums[size + 1] = 1;

        //// dp
        // i goes from btm to top. because we have dummy node at idnex 0, size + 1 for nums and dp, so the range of i is [1, size]
        for(int i = size; i > 0; --i)
        {
            // j goes from left to right
            for(int j = i; j <= size; ++j)
            {
                // k is choosen between i and j
                for(int k = i; k <= j; ++k)
                {
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + nums[i - 1] * nums[k] * nums[j + 1] + dp[k + 1][j]);
                }
            }
        }
        // for(auto& i : dp)
        // {
        //     for(auto& j : i)
        //         cout<<j<<" ";
        //     cout<<endl;
        // }

        return dp[1][size];
    }
};