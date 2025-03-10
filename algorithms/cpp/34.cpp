class Solution {
    public:
        /** 
            Array, Binary Search
    
            Binary search to find left and right boundaries.
            Check 704. Binary Search for detailed explanation
    
            1. Meaning of left_bound Return Value When target Does Not Exist
            Answer: If target does not exist, the index returned by the binary search for the left boundary is the smallest index greater than target.
                    For example, with nums = [2,3,5,7] and target = 4, the left_bound function returns 2 because the element 5 is the smallest element greater than 4.
    
            2. Meaning of right_bound Return Value When target Does Not Exist
            Answer: Unlike the previously discussed left_bound: If target does not exist, the binary search for the right boundary returns the largest index that is less than target.
                    For example, with nums = [2,3,5,7] and target = 4, the right_bound function returns 1 because the element 3 is the largest element less than 4.
    
            3. If you want to return -1 when the target does not exist, it's actually quite simple. 
            Just add an extra check when returning to see if nums[left]**left bound** or nums[right]**right bound** equals target. If it doesn't, it means the target does not exist. 
            Note that you must ensure the index does not go out of bounds before accessing the array index
    
            time O(logn)
            space O(1)
        */
        vector<int> searchRange(vector<int>& nums, int target) {
            return {left_bound(nums, target), right_bound(nums, target)};
        }
    
        //// Binary Search that find the left boundary
        int left_bound(vector<int>& nums, int target)
        {
            // we use [left, right] which is closed interval on both ends
            int left = 0;
            int right = nums.size() - 1;
    
            while(left <= right)
            {
                int mid = left + (right - left) / 2;
                if(nums[mid] < target)
                    left = mid + 1;
                else if(nums[mid] > target)
                    right = mid - 1;
                else if(nums[mid] == target)
                    right = mid - 1;    // shrink the right bound to find the target's left bound
            }
            // check if left index is out of bounds and if the target exist
            if(left < 0 or left >= nums.size() or nums[left] != target)
                return -1;
    
            return left;
        }
    
        //// Binary Search that find the right boundary
        int right_bound(vector<int>& nums, int target)
        {
            // we use [left, right] which is closed interval on both ends
            int left = 0;
            int right = nums.size() - 1;
    
            while(left <= right)
            {
                int mid = left + (right - left) / 2;
                if(nums[mid] < target)
                    left = mid + 1;
                else if(nums[mid] > target)
                    right = mid - 1;
                else if(nums[mid] == target)
                    left = mid + 1;     // shrink the left bound to find the target's right bound
            }
            // check if right index is out of bounds and if the target exist
            if(right < 0 or right >= nums.size() or nums[right] != target)
                return -1;
    
            // note that right = left - 1 here because the while loop ending condition is while left = right + 1
            return right;
        }
    };