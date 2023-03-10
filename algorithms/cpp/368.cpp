class Solution {
public:
    /** 
        dp, iteration, btm up
        
        def: 
            dp[i] = the longest divisible subset that ends at nums[i]

            if we sort the nums, that means nums[i] can divide all number if it can divide the largest number in the subset.
                ex: nums[i] = 8, subset = {1, 2, 4}. 8 % 4 = 0 means 8 can divide all number in the subset
        stf:
            1.  if(nums[i] & nums[i - 1] == 0) 
                    dp[i] = dp[i - 1] + nums[i]
            2.  else
                    dp[i] = {nums[i]}
        bc:
            dp[0] = nums[0]

        time O(n^2)
        space O(n)
    */
    
    //// O(n) space
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //// sort
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int curMaxIndex = 0;    // cur max value's index in dpSize and dpPrevIndex
        //// dp def & bc
        // dp[i] = size of the longest divisible subset that ends at nums[i]
        // bc = 1 for all nums
        vector<int> dpSize(size, 1);
        // dp[i] = the index of the previous index of the number of the longest divisible subset that ends at nums[i]. we need this to construct the res
        // bc = -1 for all nums. which means it is unchecked yet
        vector<int> dpPrevIndex(size, -1);
        //// dp
        for(int i = 1; i < size; ++i)
        {
            //// check nums[0 .. i] to find the longest divisible subset
            for(int j = 0; j < i; ++j)
            {
                if(nums[i] % nums[j] == 0 and dpSize[j] + 1 > dpSize[i])
                {
                    dpSize[i] = dpSize[j] + 1;
                    dpPrevIndex[i] = j;
                }
            }
            //// update curMaxIndex
            if(dpSize[i] > dpSize[curMaxIndex])
                curMaxIndex = i;
        }
        //// construct the res from the curMaxIndex to the front using dpPrevIndex
        vector<int> res;
        for(int i = curMaxIndex; i >= 0; i = dpPrevIndex[i])
        {
            res.push_back(nums[i]);
        }
        return res;
    }

    // //// O(n^2) space
    // vector<int> largestDivisibleSubset(vector<int>& nums) {
    //     //// sort
    //     sort(nums.begin(), nums.end());
    //     int size = nums.size();
    //     vector<vector<int>> dp(size);
    //     vector<int> res;
    //     //// bc
    //     dp[0].push_back(nums[0]);
    //     //// dp
    //     for(int i = 1; i < size; ++i)
    //     {
    //         int maxLen = 0; // cur maxLen in dp
    //         int index = -1;  // index of the maxLen in dp. -1 means it does not exist yet
    //         //// check nums[0 .. i] to find the longest divisible subset
    //         for(int j = 0; j < i; ++j)
    //         {
    //             auto& v = dp[j];
    //             if(nums[i] % v[v.size() - 1] == 0 and maxLen < v.size())
    //             {
    //                 maxLen = v.size();
    //                 index = j;
    //             }
    //         }
    //         //// the longest subset in nums[0 .. i] + nums[j] is dp[i]
    //         // maxLen exists
    //         if(index != -1)
    //             dp[i] = vector<int>(dp[index]);
    //         dp[i].push_back(nums[i]);
    //     }
    //     //// find the max
    //     for(int i = 0; i < size; ++i)
    //     {
    //         if(res.size() < dp[i].size())
    //             res = dp[i];
    //     }
    //     return res;
    // }
};