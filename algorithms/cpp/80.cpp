class Solution {
public:
    /** 
        Two Pointers, slow & fast pointer

        time O(N)
        space O(1)
    */
    int removeDuplicates(vector<int>& nums) {
        // slow & fast pointer
        int slow = 0, fast = 1;
        int count = 0;  // counter of the # of time current element appears
        while(fast < nums.size())
        {
            // different number
            if(nums[slow] != nums[fast])
            {
                // store the number to its corresponding position
                ++slow;
                nums[slow] = nums[fast];
                // reset count
                count = 0;
            }
            // same number
            else
            {
                // find a same number, update counter first
                ++count;
                // When an element is repeated less than 2 times, we want to keep it
                if(count < 2)
                {
                    // store the number to its corresponding position
                    ++slow;
                    nums[slow] = nums[fast];
                }
            }
            ++fast;
        }
        // now slow points to the last element, so the size of new nums is slow + 1
        return slow + 1;
    }
};