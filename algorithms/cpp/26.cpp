class Solution {
public:
    /** 26. Remove Duplicates from Sorted Array
        Two Pointers, slow & fast pointer

        time O(N)
        space O(1)
    */
    int removeDuplicates(vector<int>& nums) {
        // slow & fast pointer
        int slow = 0, fast = 1;
        while(fast < nums.size())
        {
            // update nums[slow] if it is not equal to nusm[fast]
            if(nums[slow] != nums[fast])
            {
                ++slow;
                nums[slow] = nums[fast];
            }
            ++fast;
        }
        // now slow points to the last element, so the size of new nums is slow + 1
        return slow + 1;
    }
};