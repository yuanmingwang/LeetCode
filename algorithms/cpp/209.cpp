class Solution {
    public:
        /** 
            Array, Binary Search, Sliding Window, Prefix Sum
    
            Sliding Window, Two pointers
            Similar approach & sliding Window framework as 76.Minimum Window Substring and 567. Permutation in String
            Check them for detailed explanation.
    
            time O(n)
            space O(1)
        */
        int minSubArrayLen(int target, vector<int>& nums) {
            int left = 0, right = 0, nums_size = nums.size();
            int sum = 0;
            int res = INT_MAX;
            
            while(right < nums_size)
            {
                //// expand the window
                int num_right = nums[right];
                ++right;
    
                //// perform a series of updates to the data within the window
                sum += num_right;
    
                //// determine whether the left window needs to be shrinked
                while(sum >= target)
                {
                    //// update res
                    if(sum >= target)
                        res = min(res, right - left);
                    
                    //// shrink the window
                    int num_left = nums[left];
                    ++left;
                    
                    //// perform a series of updates to the data within the window
                    sum -= num_left;
                }
            }
            return res == INT_MAX ? 0 : res;
        }
    };