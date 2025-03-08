class Solution {
    public:
        /** 
            Array, Two Pointers, Simulation
    
            use same method as 27.remove element, 283. Move Zeroes
    
            time O(n)
            space O(1)
        */
        vector<int> applyOperations(vector<int>& nums) {
            int size = nums.size();
            
            //// Step 1: Apply operations on the array
            for(int i = 0; i < size - 1; ++i)
            {
                if(nums[i] == nums[i + 1])
                {
                    nums[i] *= 2;
                    nums[i + 1] = 0;
                }
            }
    
            //// Step 2: Shift non-zero elements to the beginning. same method as 283. Move Zeroes
            int slow = 0, fast = 0;
            while(fast < size)
            {
                if(nums[fast] != 0)
                {
                    nums[slow] = nums[fast];
                    ++slow;
                }
                ++fast;
            }
            // Step 3: Fill the remaining positions with zeros
            while(slow < size)
            {
                nums[slow] = 0;
                ++slow;
            }
    
            return nums;
        }
    };