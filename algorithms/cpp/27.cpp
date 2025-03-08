class Solution {
    public:
        /** 
            Array, Two Pointers
            slow and fast pointer:
    
            If fast encounters an element with the value val, it skips it. 
            Otherwise, it assigns the value to the slow pointer and moves the slow pointer forward.
    
            time O(n)
            space O(1)
        */
        int removeElement(vector<int>& nums, int val) {
            int size = nums.size();
            int slow = 0, fast = 0;
            while(fast < size)
            {
                if(nums[fast] != val)
                {
                    //// Here, we assign a value to nums[slow] before incrementing ++slow, 
                    //// ensuring that nums[0..slow-1] does not contain elements with the value val. 
                    nums[slow] = nums[fast];
                    ++slow;
                }
                ++fast;
            }
            //// The final length of the result array is slow.
            return slow;
        }
    };