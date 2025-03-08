class Solution {
    public:
        /** 
            Array, Two Pointers
    
            use same method as 27.remove element
    
            time O(n)
            space O(1)
        */
        void moveZeroes(vector<int>& nums) {
            int slow = 0, fast = 0;
            int size = nums.size();
            while(fast < size)
            {
                if(nums[fast] != 0)
                {
                    nums[slow] = nums[fast];
                    ++slow;
                }
                ++fast;
            }
            // fill the rest of the array with 0
            // note that slow points to the first item to be assigned to 0
            while(slow < size)
            {
                nums[slow] = 0;
                ++slow;
            }
        }
    };