class Solution {
    public:
    //// 485. Max Consecutive Ones
    /** 
        Array

        Approach #1: One Pass
        
        time O(n)
        space O(1)
    */
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int curr_count = 0;
        for(auto& num : nums)
        {
            if(num == 1)
                res = max(res, ++curr_count);
            else
                curr_count = 0;
        }
        return res;
    }
};