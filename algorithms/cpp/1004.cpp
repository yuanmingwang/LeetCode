class Solution {
    public:
    //// 1004. Max Consecutive Ones III
    /**
        Array, Sliding Window

        Approach #1: Sliding Window. Similar sliding window framework as 76.Minimum Window Substring
        
        For each right in range [0..n-1]:
            1. If nums[right] == 0 then ++zero_count
            2. If zero_count > k then ++left: 
                This is the case when nums[left, right] contains more than k zeros -> move left util the sliding window contains no more than k zeros.

        time O(n)
        space O(1)
    */
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, num_size = nums.size();
        int zero_count = 0;
        int res = 0;

        while(right < num_size)
        {
            //// expand the window
            int num = nums[right];
            ++right;

            //// perform a series of updates to the data within the window
            if(num == 0)
            {
                ++zero_count;
            }

            //// determine whether the left window needs to be shrinked
            // Case nums[left, right) contains more than k zeros, move `left` util the subarray has no more than k zeros
            while(zero_count > k)
            {
                if(nums[left] == 0)
                    --zero_count;
                ++left;
            }

            //// update. we are using close interval on left side and open interval on right side, so right - left = the total number of element in the window
            res = max(res, right - left);
        }

        return res;
    }
};