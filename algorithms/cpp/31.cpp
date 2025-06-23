class Solution {
public:
    /** 31. Next Permutation
        Two Pointers

        algorithm: 
            1. Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
            2. Find the largest index l > k such that nums[k] < nums[l].
            3. Swap nums[k] and nums[l].
            4. Reverse the sub-array nums[k + 1:].
        
        ex:
            123456
            123465
            123546
            123564
            123645
            123654
            124356 ...
        
        time O(N)
        space O(1)
    */
    void nextPermutation(vector<int>& nums) {
        int k = nums.size() - 2;  // pivot
        int l; // next_pivot
        //// 1.
        while(k >= 0)
        {
            if(nums[k] < nums[k + 1])
                break;
            --k;
        }
        if(k < 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        //// 2.
        for(l = nums.size() - 1; l > k; --l)
        {
            if(nums[k] < nums[l])
            {
                //// 3.
                swap(nums[k], nums[l]);
                //// 4.
                reverse(nums.begin() + k + 1, nums.end());
                return;
            }
        }
    }
};